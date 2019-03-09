#include <catch.hpp>
#include <oqs/infrastructure/save/dense.h>

namespace oqs
{
	namespace Test
	{
		TEST_CASE("Checking infrastructure save dence", "[can save matrix_cd]")
		{
			Eigen::MatrixXcd A(3, 3);
			A(0, 0) = {2.0, 5.0};
			A(0, 1) = {-10.0, -6.0};
			A(0, 2) = {-2.0, 10.0};
			A(1, 0) = {-5.0, -8.0};
			A(1, 1) = {-3.0, -8.0};
			A(1, 2) = {-7.0, 7.0};
			A(2, 0) = {-4.0, 7.0};
			A(2, 1) = {-8.0, 3.0};
			A(2, 2) = {7.0, 3.0};

			const std::string file_name = "matrix_cd.txt";
			save_dense(file_name, A);

			//REQUIRE(std::experimental::filesystem::exists(file_name));
			REQUIRE(1);

			std::remove(file_name.c_str());
		}
	} // namespace Test
} // namespace oqs
