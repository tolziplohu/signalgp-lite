#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch2/catch.hpp"

#include "Empirical/include/emp/math/Random.hpp"

#include "sgpl/config/Spec.hpp"
#include "sgpl/program/Instruction.hpp"

using spec_t = sgpl::Spec<>;

TEST_CASE("Test Instruction") {

  // TODO flesh out stub test
  sgpl::Instruction<spec_t>{};

}
