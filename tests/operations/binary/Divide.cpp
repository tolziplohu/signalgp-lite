#include "Catch/single_include/catch2/catch.hpp"

#include "sgpl/algorithm/execute_core.hpp"
#include "sgpl/hardware/Core.hpp"
#include "sgpl/library/OpLibrary.hpp"
#include "sgpl/operations/binary/Divide.hpp"
#include "sgpl/program/Program.hpp"
#include "sgpl/spec/Spec.hpp"

// define libray and spec
using library_t = sgpl::OpLibrary<sgpl::Divide>;
using spec_t = sgpl::Spec<library_t>;

// create peripheral
spec_t::peripheral_t peripheral;

TEST_CASE("Test Divide") {

  sgpl::Program<spec_t> program{1};

  sgpl::Core<spec_t> core;

  // set up initial state

  // set up values to operate on in register
  core.registers[0] = 99;
  core.registers[1] = 2;

  // set up what registers to operate on
  program[0].args[0] = 2;
  program[0].args[1] = 0;
  program[0].args[2] = 1;

  // check initial state
  REQUIRE(core.registers == emp::array<float, 8>{99, 2, 0, 0, 0, 0, 0, 0});

  // execute single instruction
  sgpl::advance_core(core, program, peripheral);

  // check final state
  // expected: 99 / 2 == 49.5
  REQUIRE(core.registers == emp::array<float, 8>{99, 2, 49.5, 0, 0, 0, 0, 0});
}
