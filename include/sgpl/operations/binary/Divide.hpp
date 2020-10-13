#pragma once
#ifndef SGPL_OPERATIONS_BINARY_DIVIDE_HPP_INCLUDE
#define SGPL_OPERATIONS_BINARY_DIVIDE_HPP_INCLUDE

#include "../../hardware/Core.hpp"
#include "../../program/Instruction.hpp"
#include "../../program/Program.hpp"

namespace sgpl {

struct Divide {

  template<typename Spec>
  static void run(
    sgpl::Core<Spec>& core,
    const sgpl::Instruction<Spec>& inst,
    const sgpl::Program<Spec>&,
    typename Spec::peripheral_t&
  ) {
    const size_t a = inst.args[0], b = inst.args[1], c = inst.args[2];

    if ( core.registers[c] ) { // disallow division by zero
      core.registers[a] = core.registers[b] / core.registers[c];
    }
  }

  static std::string name() { return "Divide"; }

};

} // namespace sgpl

#endif // #ifndef SGPL_OPERATIONS_BINARY_DIVIDE_HPP_INCLUDE
