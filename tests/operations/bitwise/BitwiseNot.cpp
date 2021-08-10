#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch2/catch.hpp"

#include "sgpl/operations/bitwise/BitwiseNot.hpp"

#include "sgpl/hardware/Core.hpp"
#include "sgpl/program/Program.hpp"

#include "sgpl/algorithm/execute_core.hpp"

#include "sgpl/spec/Spec.hpp"

#include "sgpl/utility/EmptyType.hpp"

#include "conduit/include/uitsl/polyfill/bit_cast.hpp"

// define libray and spec
using library_t = sgpl::OpLibrary<sgpl::BitwiseNot>;

using spec_t = sgpl::Spec<library_t>;

// create peripheral
spec_t::peripheral_t peripheral;

TEST_CASE("Test BitwiseNot") {

  sgpl::Program<spec_t> program{1};

  sgpl::Core<spec_t> core;

  // set up initial state
  const float val1 = std::bit_cast<float>(0b1001001);
  const float val2 = std::bit_cast<float>(0b11111111111111111111111110110110);

  // set up values to operate on in register
  core.registers[0] = val1;

  // set up what registers to operate on
  program[0].args[0] = 1;
  program[0].args[1] = 0;

  // check initial state
  REQUIRE_THAT(core.registers, Catch::Matchers::Equals(
    emp::array<float, 8>{val1, 0, 0, 0, 0, 0, 0, 0}
  ));

  // execute single instruction
  sgpl::advance_core(core, program, peripheral);

  std::cout << std::bitset<8>(core.registers[1]) << std::endl;

  // check final state
  REQUIRE_THAT(core.registers, Catch::Matchers::Equals(
    emp::array<float, 8>{val1, val2, 0, 0, 0, 0, 0, 0}
  ));
}
