#ifndef INF_SAVE_MTX_HPP
#define INF_SAVE_MTX_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

#include <Eigen/Dense>
#include <complex>
#include <string>
#include <fstream>
#include <filesystem>

namespace oqs
{
	/**
	 * \brief Save dense (matrix or vector) to file
	 * \tparam Derived: 
	 * \param file_name: name of file.
	 * \param dense: dense for saving.
	 */
	template <typename Derived>
	void save_dense(const std::string& file_name, const Eigen::DenseBase<Derived>& dense)
	{
		const Eigen::IOFormat common_fmt(Eigen::FullPrecision, 0, "", "\n", "", "", "", "");
		std::ofstream file(file_name.c_str());
		file << dense.format(common_fmt);
	}
} // namespace oqs

#endif // INF_SAVE_MTX_HPP
