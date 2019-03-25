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
#include <INIReader.h>

namespace oqs
{
	/**********************************************************************************************/ /**
	 * \struct	HamiltonianPart
	 *
	 * \brief	Abstract base class for hamiltonian part generation.
	 **************************************************************************************************/
	struct HamiltonianPart
	{
		virtual int get_num_segments() = 0;
		virtual std::vector<Eigen::MatrixXcd> get_hamiltonians() = 0;
		virtual std::vector<double> get_segments_periods() = 0;
		virtual bool get_is_driving() = 0;
		virtual std::vector<std::function<std::complex<double>(double)>> get_drivings() = 0;
	};

	
} // namespace oqs

#endif // SYS_HAMILTONIAN_HPP
