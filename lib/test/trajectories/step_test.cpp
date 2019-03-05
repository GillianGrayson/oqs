#include <catch.hpp>
#include "trajectories/step.h"

namespace oqs
{
	namespace Test
	{
		TEST_CASE("Checking trajectories propagation step", "[trajectories propagation step]")
		{
			const Eigen::VectorXcd y_real(4);
			Eigen::VectorXcd y_test(4);
			Eigen::MatrixXd A(4, 4);
			Eigen::VectorXcd x(4);

			REQUIRE(y_real.isApprox(y_test));
		}
	} // namespace Test
} // namespace oqs
