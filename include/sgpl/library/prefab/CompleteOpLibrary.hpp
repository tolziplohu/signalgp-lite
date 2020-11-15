#pragma once
#ifndef SGPL_LIBRARY_PREFAB_COMPLETEOPLIBRARY_HPP_INCLUDE
#define SGPL_LIBRARY_PREFAB_COMPLETEOPLIBRARY_HPP_INCLUDE

#include "../../operations/operations.hpp"

#include "../OpLibrary.hpp"

namespace sgpl {

using CompleteOpLibrary = sgpl::OpLibrary<
  sgpl::ForkIf,
  sgpl::Nop,
  sgpl::TerminateIf,
  sgpl::Add,
  sgpl::Divide,
  sgpl::Modulo,
  sgpl::Multiply,
  sgpl::Subtract,
  sgpl::BitwiseAnd,
  sgpl::BitwiseNot,
  sgpl::BitwiseOr,
  sgpl::BitwiseShift,
  sgpl::BitwiseXor,
  sgpl::CountOnes,
  sgpl::Equal,
  sgpl::GreaterThanEqual,
  sgpl::LessThanEqual,
  sgpl::global::Anchor,
  sgpl::global::JumpIf,
  sgpl::global::JumpIfNot,
  sgpl::global::RegulatorAdj,
  sgpl::global::RegulatorGet,
  sgpl::global::RegulatorSet,
  sgpl::local::Anchor,
  sgpl::local::JumpIf,
  sgpl::local::JumpIfNot,
  sgpl::local::RegulatorAdj,
  sgpl::local::RegulatorGet,
  sgpl::local::RegulatorSet,
  sgpl::CoinFlip,
  sgpl::Decrement,
  sgpl::Generate,
  sgpl::Increment,
  sgpl::Negate,
  sgpl::Not,
  sgpl::Terminal<>
>;

} // namespace sgpl

#endif // #ifndef SGPL_LIBRARY_PREFAB_COMPLETEOPLIBRARY_HPP_INCLUDE
