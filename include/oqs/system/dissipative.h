#ifndef SYS_DISSIPATIVE_HPP
#define SYS_DISSIPATIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

#include <Eigen/Dense>
#include <spdlog/spdlog.h>
#include <vector>

namespace oqs
{
	/**********************************************************************************************/ /**
	 * \struct	DissipativePart
	 *
	 * \brief	Abstract base class for dissipative part generation.
	 **************************************************************************************************/
	struct DissipativePart
	{
		int num_dissipators; /**< Number of dissipators */
		std::vector<Eigen::MatrixXcd> dissipators; /**< Dissipation matrices */

		/**********************************************************************************************/ /**
		 * \brief	Default constructor
		 **************************************************************************************************/
		DissipativePart(): num_dissipators(1)
		{
		}

		/**********************************************************************************************/ /**
		 * \brief	Init data structure for dissipative part of quantum system.
		 *
		 * \param	num_dissipators_	Number of dissipators in model.
		 * \param	dissipators_	   	Vector of dissipators matrices. 
		 * 								Size must be equal to num_dissipators.
		 **************************************************************************************************/
		DissipativePart(
			int num_dissipators_,
			std::vector<Eigen::MatrixXcd> dissipators_
		) : num_dissipators{num_dissipators_},
		    dissipators{std::move(dissipators_)}
		{
			spdlog::get("console")->info("Dissipative part initialized.");
		}
	};
} // namespace oqs

#endif // SYS_DISSIPATIVE_HPP
