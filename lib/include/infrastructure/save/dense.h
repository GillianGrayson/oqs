#ifndef INF_SAVE_MTX_HPP
#define INF_SAVE_MTX_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

#include <Eigen/Dense>
#include <complex>
#include <string>
#include <filesystem>
#include <fstream>

namespace oqs
{
	/** \brief Save dense (matrix or vector) to file
	  *
	  * \param file_name: name of file.
	  * \param dense: dense for saving.
	*/
	//template <typename Derived>
	//void save_dense(std::string file_name, const Eigen::DenseBase<Derived>& dense);
	void save_dense(std::string file_name, const Eigen::MatrixXcd& dense);
} // namespace oqs

#endif // INF_SAVE_MTX_HPP
