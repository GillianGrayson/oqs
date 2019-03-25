#include <catch.hpp>
#include <oqs/trajectories/experiment.h>

namespace oqs
{
	namespace Test
	{
		TEST_CASE("can create non-deep experiment", "[system][init][experiment]")
		{	
			auto hamiltonian_part = std::make_unique<oqs::HamiltonianPart>();
			auto dissipative_part = std::make_unique<oqs::DissipativePart>();
			ExperimentType experiment_type = ExperimentType::statistics;
			int num_trajectories = 10;
			int num_trans_periods = 1000;
			int num_obser_periods = 1000;
			bool is_deep = false;
			int num_dumps = 1;

			SECTION("creating with correct number of dumps")
			{
				num_dumps = 1;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				REQUIRE(1);
			}
			SECTION("creating with incorrect number of dumps")
			{
				num_dumps = 2000;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				REQUIRE(ex.num_dumps == ex.num_obser_periods);
			}
			SECTION("creating with non-uniform dumps (small number of dumps)")
			{
				num_dumps = 9;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				REQUIRE(ex.num_dumps == 10);
			}
			SECTION("creating with non-uniform dumps (big number of dumps)")
			{
				num_dumps = 503;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				REQUIRE(ex.num_dumps == 500);
			}
		}

		TEST_CASE("can create deep experiment", "[system][init][experiment]")
		{
			auto hamiltonian_part = std::make_unique<oqs::HamiltonianPart>();
			auto dissipative_part = std::make_unique<oqs::DissipativePart>();
			ExperimentType experiment_type = ExperimentType::statistics;
			int num_trajectories = 10;
			int num_trans_periods = 1000;
			int num_obser_periods = 1000;
			bool is_deep = true;
			int num_dumps = 1;
			int num_deep_steps = 10;

			SECTION("creating with correct number of dumps")
			{
				num_dumps = 2000;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				ex.set_deep(num_deep_steps);
				REQUIRE(1);
			}
			SECTION("creating with incorrect number of dumps")
			{
				num_dumps = 20000;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				ex.set_deep(num_deep_steps);
				REQUIRE(ex.num_dumps == ex.num_obser_periods * num_deep_steps);
			}
			SECTION("creating with non-uniform dumps (small number of dumps)")
			{
				num_dumps = 9;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				ex.set_deep(num_deep_steps);
				REQUIRE(ex.num_dumps == 10);
			}
			SECTION("creating with non-uniform dumps (big number of dumps)")
			{
				num_dumps = 5003;
				Experiment ex(
					std::move(hamiltonian_part),
					std::move(dissipative_part),
					experiment_type,
					num_trajectories,
					num_trans_periods,
					num_obser_periods,
					num_dumps,
					is_deep
				);
				ex.set_deep(num_deep_steps);
				REQUIRE(ex.num_dumps == 5000);
			}
		}
	} // namespace Test
} // namespace oqs
