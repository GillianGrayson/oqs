#include <spdlog/spdlog.h>

int main(int argc, char* argv[])
{
	auto console = spdlog::stdout_color_mt("console");

	return 0;
}
