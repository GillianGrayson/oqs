#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <spdlog/spdlog.h>

int main(int argc, char* argv[])
{
	auto console = spdlog::stdout_color_mt("console");
	Catch::Session().run(argc, argv);
	return 0;
}
