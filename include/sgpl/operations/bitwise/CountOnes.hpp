#pragma once
#ifndef SGPL_OPERATIONS_BITWISE_COUNTONES_HPP_INCLUDE
#define SGPL_OPERATIONS_BITWISE_COUNTONES_HPP_INCLUDE

#include <bitset>
#include <cstring>

#include "../../hardware/Core.hpp"
#include "../../program/Instruction.hpp"
#include "../../program/Program.hpp"

namespace sgpl {

struct CountOnes {

  template<typename Spec>
  static void run(
    sgpl::Core<Spec>& core,
    const sgpl::Instruction<Spec>& inst,
    const sgpl::Program<Spec>&,
    typename Spec::peripheral_t&
  ) {
    const size_t a = inst.args[0], b = inst.args[1];

    static_assert( sizeof(core.registers[a]) <= sizeof(size_t) );
    size_t as_size_t;

    std::memcpy(
      &as_size_t,
      &core.registers[a],
      sizeof( core.registers[a] )
    );

    constexpr size_t num_bits = sizeof(core.registers[a]) * 8;
    core.registers[b] = std::bitset<num_bits>{ as_size_t }.count();
  }

  static std::string name() { return "Count Ones"; }

  static size_t prevalence() { return 1; }

};

} // namespace sgpl

#endif // #ifndef SGPL_OPERATIONS_BITWISE_COUNTONES_HPP_INCLUDE
