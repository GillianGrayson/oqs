#include <catch.hpp>
#include <oqs/trajectories/propagation/step.h>

namespace oqs
{
	namespace Test
	{
		TEST_CASE("Checking trajectories propagation step", "[trajectories propagation step]")
		{
			Eigen::VectorXcd y_real(3);
			y_real(0) = {207.0, -66.0};
			y_real(1) = {152.0, 126.0};
			y_real(2) = {76.0, -168.0};

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

			Eigen::VectorXcd x(3);
			x(0) = {-4.0, -3.0};
			x(1) = {-5.0, 8.0};
			x(2) = {-1.0, -10.0};

			Eigen::VectorXcd y_test(3);
			oqs::prop_step(y_test, A, x);

			REQUIRE(y_real.isApprox(y_test));
		}
	} // namespace Test
} // namespace oqs
