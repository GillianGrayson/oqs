#include "infrastructure/save/dense.h"



namespace oqs
{
	/*template <typename Derived>
	void save_dense(std::string file_name, const Eigen::DenseBase<Derived>& dense)
	{
		const Eigen::IOFormat common_fmt(Eigen::FullPrecision, 0, "", "\n", "", "", "", "");
		std::ofstream file(file_name.c_str());
		file << dense.format(common_fmt);
	}*/

	void save_dense(std::string file_name, const Eigen::MatrixXcd& dense)
	{
		const Eigen::IOFormat common_fmt(Eigen::FullPrecision, 0, "", "\n", "", "", "", "");
		std::ofstream file(file_name.c_str());
		file << dense.format(common_fmt);
	}
} // namespace oqs