#include <catch.hpp>
#include <oqs/infrastructure/save/dense.h>

namespace oqs
{
	namespace Test
	{
		TEST_CASE("saving of denses creates file", "[infrastructure][save][dense]")
		{
			const std::string file_name = "dense.txt";

			SECTION("saving of complex double matrix")
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

				save_dense(file_name, A);

				REQUIRE(std::filesystem::exists(file_name));
			}
			SECTION("saving of double matrix")
			{
				Eigen::MatrixXd A(2, 2);
				A(0, 0) = 2.0;
				A(0, 1) = -10.0;
				A(1, 0) = -5.0;
				A(1, 1) = -3.0;

				save_dense(file_name, A);

				REQUIRE(std::filesystem::exists(file_name));
			}
			SECTION("saving of complex double vector")
			{
				Eigen::VectorXcd A(3);
				A(0) = {2.0, 5.0};
				A(1) = {-10.0, -6.0};
				A(2) = {-2.0, 10.0};

				save_dense(file_name, A);

				REQUIRE(std::filesystem::exists(file_name));
			}
			SECTION("saving of  double vector")
			{
				Eigen::VectorXd A(2);
				A(0) = 2.0;
				A(1) = -10.0;

				save_dense(file_name, A);

				REQUIRE(std::filesystem::exists(file_name));
			}

			std::remove(file_name.c_str());
		}
	} // namespace Test
} // namespace oqs
