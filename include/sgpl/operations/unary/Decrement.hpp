#pragma once
#ifndef SGPL_OPERATIONS_UNARY_DECREMENT_HPP_INCLUDE
#define SGPL_OPERATIONS_UNARY_DECREMENT_HPP_INCLUDE

#include "../../hardware/Core.hpp"
#include "../../program/Instruction.hpp"
#include "../../program/Program.hpp"

namespace sgpl {

struct Decrement {

  template<typename Spec>
  static void run(
    sgpl::Core<Spec>& core,
    const sgpl::Instruction<Spec>& inst,
    const sgpl::Program<Spec>&,
    typename Spec::peripheral_t&
  ) {
    --core.registers[ inst.args[0] ];
  }

  static std::string name() { return "Decrement"; }

};

} // namespace sgpl

#endif // #ifndef SGPL_OPERATIONS_UNARY_DECREMENT_HPP_INCLUDE
