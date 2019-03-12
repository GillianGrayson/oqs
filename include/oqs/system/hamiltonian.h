#ifndef SYS_HAMILTONIAN_HPP
#define SYS_HAMILTONIAN_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

#include <Eigen/Dense>
#include <complex>
#include <vector>
#include <functional>
#include <iostream>

namespace oqs
{
	struct HamiltonianPart
	{
		int num_segments;
		std::vector<Eigen::MatrixXcd> hamiltonians;
		std::vector<double> segments_periods;
		bool is_driving;
		std::vector<std::function<std::complex<double>(double)>> drivings;

		HamiltonianPart(
			int num_segments_,
			std::vector<Eigen::MatrixXcd> hamiltonians_,
			std::vector<double> segments_periods_,
			bool is_driving_,
			std::vector<std::function<std::complex<double>(double)>> drivings_
		) : num_segments{ num_segments_ },
			hamiltonians{ hamiltonians_ },
			segments_periods{ segments_periods_ },
			is_driving{ is_driving_ },
			drivings{ drivings_ }
		{
			std::cout << "HIIIIIIIIIIIIIIIIIIIII" << std::endl;
		}

	};

} // namespace oqs

#endif // SYS_HAMILTONIAN_HPP
