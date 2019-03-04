#include <catch.hpp>
#include "trajectories/step.h"

namespace oqs
{
	namespace Test
	{
		TEST_CASE("Check myy function", "[step]")
		{
			REQUIRE(qj_step(1) == 1);
		}
	} // namespace Test
} // namespace oqs
