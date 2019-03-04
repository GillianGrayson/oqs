#include "calc_step.h"
#include <sstream>

namespace oqs
{
	std::ostream& operator<<(std::ostream& stream, const CalcStep& step)
	{
		if (step.has_value())
		{
			stream << step.value();
		}
		else
		{
			stream << step.operation_name();
		}

		return stream;
	}
} // namespace oqs
