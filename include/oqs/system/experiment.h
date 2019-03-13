#ifndef SYS_EXPERIMENT_HPP
#define SYS_EXPERIMENT_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

#include <Eigen/Dense>
#include <spdlog/spdlog.h>
#include <complex>
#include <utility>
#include <vector>
#include <functional>
#include <stdlib.h>

namespace oqs
{
	/**********************************************************************************************/ /**
	 * \enum	ExperimentType
	 *
	 * \brief	Enumeration of possible types of experiments:
	 * 			
	 * 			lyapunov_exponents:	Experiment for quantum lyapunov exponent calculation.
	 * 			  					Only first trajectory is unique. 
	 * 			  					The others are variation trajectories for lyapunov exponent calculating.
	 * 			
	 * 			statistics:			Regular experiment for statistics collection.
	 * 			  					All trajectories independent.
	 **************************************************************************************************/
	enum class ExperimentType
	{
		statistics,
		lyapunov_exponents
	};

	struct Experiment
	{
		ExperimentType experiment_type;
		int num_trajectories;
		int num_trans_periods;
		int num_obser_periods;
		bool is_deep;
		int num_dumps;

		int num_deep_steps;

		/**********************************************************************************************/ /**
		 * \brief	Init quantum trajectories.
		 *
		 * \param	experiment_type_  	Type of the experiment.
		 * \param	num_trajectories_ 	Number of trajectories.
		 * \param	num_trans_periods_	Number of translition periods.
		 * \param	num_obser_periods_	Number of observable periods.
		 * \param	is_deep_		  	Possibility to dumps inside the period.
		 * 								True if experiment is deep, false if not.
		 * \param	num_dumps_		  	Number of dumps.
		 **************************************************************************************************/
		Experiment(
			ExperimentType experiment_type_,
			int num_trajectories_,
			int num_trans_periods_,
			int num_obser_periods_,
			int num_dumps_,
			bool is_deep_

		) : experiment_type{experiment_type_},
		    num_trajectories{num_trajectories_},
		    num_trans_periods{num_trans_periods_},
		    num_obser_periods{num_obser_periods_},
		    is_deep{is_deep_},
		    num_dumps{num_dumps_}
		{
			if (!is_deep)
			{
				check_num_dumps(num_obser_periods, num_dumps);
			}

			spdlog::get("console")->info("Experiment initialized.");
		}

		/**********************************************************************************************/ /**
		 * \brief	Sets deep details of the experiment.
		 *
		 * \exception	std::exception	Thrown when an exception error condition occurs.
		 *
		 * \param	num_deep_steps_	Number of deep steps.
		 **************************************************************************************************/
		void set_deep(int num_deep_steps_)
		{
			if (is_deep)
			{
				num_deep_steps = num_deep_steps_;
				check_num_dumps(num_deep_steps * num_obser_periods, num_dumps);
				spdlog::get("console")->info("Deep details of the experiment are initialized.");
			}
			else
			{
				std::string msg = "Deep details initialization when deep is off.";
				spdlog::get("console")->error(msg.c_str());
				throw std::exception(msg.c_str());
			}
		}

	private:

		void check_num_dumps(const int num_steps, const int curr_num_dumps)
		{
			if (curr_num_dumps > num_steps)
			{
				num_dumps = num_steps;
				std::string message = "Experiment is not deep. "
					"Number of dumps must be equal or less than number of observable periods. "
					"Setting num_dumps to {}";
				spdlog::get("console")->warn(message.c_str(), num_dumps);
			}
			else
			{
				auto div_res = div(num_steps, curr_num_dumps);
				if (div_res.rem != 0)
				{
					num_dumps = closest_num_dumps(num_steps, curr_num_dumps);
					std::string message = "Distribution of dumps in time should be uniform. "
						"Number of dumps is adapted. "
						"Setting num_dumps to {}";
					spdlog::get("console")->warn(message.c_str(), num_dumps);
				}
			}
		}

		int closest_num_dumps(int num_steps, int num_dumps) const
		{
			for (int i = 1; i <= std::sqrt(num_steps); i++)
			{
				auto div_res = div(num_steps, i);
				if (div_res.rem == 0)
				{
					if (i > num_dumps) return i;

					if (div_res.quot <= num_dumps) return div_res.quot;
				}
			}
			return 1;
		}
	};
} // namespace oqs

#endif // SYS_EXPERIMENT_HPP
