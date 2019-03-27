#include <catch.hpp>
#include <oqs/system/dissipative.h>

namespace oqs
{
	namespace Test
	{
		TEST_CASE("can create dissipative part", "[system][init][dissipative]")
		{
			const int num_dissipators = 1;
			const std::vector<Eigen::MatrixXcd> dissipators{Eigen::MatrixXcd::Zero(3, 3)};

			DissipativePart dp(num_dissipators, dissipators);
			REQUIRE(1);
		}
	} // namespace Test
} // namespace oqs
