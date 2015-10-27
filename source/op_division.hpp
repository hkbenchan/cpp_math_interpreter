/**
 * \file op_division.hpp
 *
 * The interface of the operator '/'.
 *
 *
 * '/': Return the value that a/b if (/ a b) is input in the s-expression.
 * Return the inverse of a (in double) if (/ a) is input.
 * Return the value that (a/b)/c if (/ a b c) is input.
 *
 * It supports at least one operand.
 *
 * ERROR when:
 *
 * (1) Any cell contains non-Int and non-Double value.
 * (2) No arguments.
 * (3) Division by zero.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_DIVISION_HPP_
#define OP_DIVISION_HPP_

#include "SymbolOperator.hpp"

class op_division: public SymbolOperator
{
public:
  op_division(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_division(){};
};

#endif /* OP_DIVISION_HPP_ */
