#include <catch.hpp>
#include <oqs/system/hamiltonian.h>

namespace oqs
{
	namespace Test
	{
		TEST_CASE("sdfsdfdsf", "[infrastructure][save][dense]")
		{
			int num_segments;
			std::vector<Eigen::MatrixXcd> hamiltonians;
			std::vector<double> segments_periods;
			bool is_driving;
			std::vector<std::function<std::complex<double>(double)>> drivings;

			HamiltonianPart hp(num_segments, hamiltonians, segments_periods, is_driving, drivings);
			REQUIRE(1);
		}
	} // namespace Test
} // namespace oqs
