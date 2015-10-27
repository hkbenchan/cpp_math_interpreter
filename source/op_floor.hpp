/**
 * \file op_floor.hpp
 *
 * The interface of the operator 'floor'.
 *
 * 'floor': Return an IntCell which its value is the nearest integer
 * which is smaller or equal to original value.
 *
 * It can support exactly one double operand.
 *
 * ERROR when:
 *
 * (1) The operand is not a DoubleCell.
 * (2) Too many arguments.
 * (3) No arguments.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_FLOOR_HPP_
#define OP_FLOOR_HPP_

#include "SymbolOperator.hpp"

class op_floor: public SymbolOperator
{
public:
  op_floor(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_floor(){};
};

#endif /* OP_FLOOR_HPP_ */
