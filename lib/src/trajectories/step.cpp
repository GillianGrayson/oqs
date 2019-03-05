#include "trajectories/step.h"

namespace oqs
{
	void prop_step(Eigen::VectorXcd& y, const Eigen::MatrixXcd& A, const Eigen::VectorXcd& x)
	{
		y.noalias() = A * x;
	}
} // namespace oqs