#include <catch.hpp>
#include <oqs/system/hamiltonian/generators/mock.h>
#include <cmath>

namespace oqs
{
	namespace Test
	{
		TEST_CASE("can create hamiltonian part mock", "[system][hamiltonian]")
		{
			std::unique_ptr<HamiltonianPart> p_hamiltonian_part = std::make_unique<HamiltonianPartMock>();

			auto hamiltonians = p_hamiltonian_part->get_hamiltonians();
			auto segments_periods = p_hamiltonian_part->get_segments_periods();
			auto drivings = p_hamiltonian_part->get_drivings();

			SECTION("checking number of segments")
			{
				REQUIRE(p_hamiltonian_part->get_num_segments() == 1);
			}
			SECTION("checking hamiltonian matrices")
			{
				REQUIRE(hamiltonians.size() == 1);
				auto matrix = Eigen::MatrixXcd::Zero(3, 3);
				REQUIRE(hamiltonians[0].isApprox(matrix));
			}
			SECTION("checking segments periods")
			{
				REQUIRE(segments_periods.size() == 1);
				REQUIRE(segments_periods[0] == 1.0);
			}
			SECTION("checking is driving")
			{
				REQUIRE_FALSE(p_hamiltonian_part->get_is_driving());
			}
			SECTION("checking segments periods")
			{
				REQUIRE(drivings.size() == 1);
				auto driving = drivings[0](1.0).real();
				REQUIRE(std::sin(1.0) == Approx(driving));
			}
			SECTION("checking sizes")
			{
				REQUIRE(drivings.size() == segments_periods.size());
				REQUIRE(segments_periods.size() == hamiltonians.size());
			}
		}
	} // namespace Test
} // namespace oqs
