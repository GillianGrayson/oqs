#ifndef SYS_HAMILTONIAN_HPP
#define SYS_HAMILTONIAN_HPP

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
#include <stdexcept>

namespace oqs
{
	struct HamiltonianPart
	{
		int num_segments;
		std::vector<Eigen::MatrixXcd> hamiltonians;
		std::vector<double> segments_periods;
		bool is_driving;
		std::vector<std::function<std::complex<double>(double)>> drivings;

		/**********************************************************************************************/ /**
		 * \brief	Init data structure for hamiltonian part of quantum system.
		 *
		 * \param	num_segments_		Number of segments with different hamiltonians.
		 * \param	hamiltonians_		Vector of hamiltonians matrices. 
		 * 								Size must be equal to num_segments.
		 * \param	segments_periods_	Vector of time durations of each segment. 
		 * 								Size must be equal to num_segments.
		 * \param	is_driving_			The system has a driving?
		 **************************************************************************************************/
		HamiltonianPart(
			int num_segments_,
			std::vector<Eigen::MatrixXcd> hamiltonians_,
			std::vector<double> segments_periods_,
			bool is_driving_
		) : num_segments{num_segments_},
		    hamiltonians{std::move(hamiltonians_)},
		    segments_periods{std::move(segments_periods_)},
		    is_driving{is_driving_}
		{
			spdlog::get("console")->info("Hamiltonian part initialized.");
		}

		/**********************************************************************************************/ /**
		 * \brief	Sets a driving of quantum system
		 *
		 * \param	drivings_	Vector of driving functions. 
		 * 						Size must be equal to num_segments.
		 **************************************************************************************************/
		void set_driving(std::vector<std::function<std::complex<double>(double)>> drivings_)
		{
			if (is_driving)
			{
				drivings = std::move(drivings_);
				spdlog::get("console")->info("Driving in hamiltonian part initialized.");
			}
			else
			{	
				std::string msg = "Driving initialization when driving is off.";
				spdlog::get("console")->error(msg.c_str());
				throw std::exception(msg.c_str());
			}
		}
	};
} // namespace oqs

#endif // SYS_HAMILTONIAN_HPP
