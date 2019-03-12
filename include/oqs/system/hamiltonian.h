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

namespace oqs
{
	struct HamiltonianPart
	{
		int num_segments;
		std::vector<Eigen::MatrixXcd> hamiltonians;
		std::vector<double> segments_periods;
		bool is_driving;
		std::vector<std::function<std::complex<double>(double)>> drivings;

		/**
		 * \brief Init data structure for hamiltonian part of quantum system.
		 * 
		 * \param num_segments:	Number of segments with different hamiltonians.
		 * 
		 * \param hamiltonians:	Vector of hamiltonians matrices. 
		 *						Size must be equal to num_segments.
		 *								
		 * \param segments_periods:	Vector of time durations of each segment.
		 *							Size must be equal to num_segments.
		 *								
		 * \param is_driving: The system has a driving?
		 * 
		 * \param drivings:	Vector of driving functions.
		 *					Size must be equal to num_segments.
		 */
		HamiltonianPart(
			int num_segments,
			std::vector<Eigen::MatrixXcd> hamiltonians,
			std::vector<double> segments_periods,
			bool is_driving,
			std::vector<std::function<std::complex<double> (double)>> drivings
		) : num_segments{num_segments},
		    hamiltonians{std::move(hamiltonians)},
		    segments_periods{std::move(segments_periods)},
		    is_driving{is_driving},
		    drivings{std::move(drivings)}
		{
			spdlog::get("console")->info("HI");
		}
	};
} // namespace oqs

#endif // SYS_HAMILTONIAN_HPP
