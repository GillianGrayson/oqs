#ifndef SYS_HAMILTONIAN_MOCK_HPP
#define SYS_HAMILTONIAN_MOCK_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

#include <oqs/system/hamiltonian/hamiltonian.h>
#include <cmath>

namespace oqs
{
	/**********************************************************************************************/ /**
	 * \struct	HamiltonianPart
	 *
	 * \brief	Abstract base class for hamiltonian part generation.
	 **************************************************************************************************/
	struct HamiltonianPartMock : HamiltonianPart
	{
		int get_num_segments() override
		{
			const int num_segments = 1;
			return num_segments;
		}

		std::vector<Eigen::MatrixXcd> get_hamiltonians() override
		{
			std::vector<Eigen::MatrixXcd> hamiltonians{Eigen::MatrixXcd::Zero(3, 3)};
			return hamiltonians;
		}

		std::vector<double> get_segments_periods() override
		{
			std::vector<double> segments_periods{1.0};
			return segments_periods;
		}

		bool get_is_driving() override
		{
			const bool is_driving = false;
			return is_driving;
		}

		std::vector<std::function<std::complex<double>(double)>> get_drivings() override
		{
			const auto driving_sin = [](double time) { return std::complex<double>(sin(time), 0.0); };
			std::vector<std::function<std::complex<double>(double)>> drivings{driving_sin};
			return drivings;
		}
	};
} // namespace oqs

#endif // SYS_HAMILTONIAN_MOCK_HPP
#pragma once
