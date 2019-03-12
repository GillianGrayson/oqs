#include <oqs/system/hamiltonian.h>

int main(int argc, char* argv[])
{
	auto console = spdlog::stdout_color_mt("console");

	int num_segments = 1;
	std::vector<Eigen::MatrixXcd> hamiltonians{ Eigen::MatrixXcd::Zero(3, 3) };
	std::vector<double> segments_periods{ 1.0 };
	bool is_driving = true;

	auto driving_sin = [](double time) { return std::complex<double>(time, 0.0); };
	std::vector<std::function<std::complex<double>(double)>> drivings{ driving_sin };

	oqs::HamiltonianPart hp = oqs::HamiltonianPart(num_segments, hamiltonians, segments_periods, is_driving, drivings);

	return 0;
}
