/**
 * \file op_ceiling.hpp
 *
 * The interface of the operator 'ceiling'.
 *
 * 'ceiling': Return an IntCell which its value is the nearest integer
 * which is larger or equal to original value.
 *
 * It can support exactly one double operand.
 *
 * ERROR when:
 *
 * (1) The operand is not a DoubleCell.
 * (2) Too many arguments.
 * (3) No arguments.
 *
 *  Created on: Oct 12, 2011
 *      Author: ben
 */

#ifndef OP_CEILING_HPP_
#define OP_CEILING_HPP_

#include "SymbolOperator.hpp"

class op_ceiling: public SymbolOperator
{
public:
  op_ceiling(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */  
  Cell* eval_op(Cell*) const;

  ~op_ceiling(){};
};
#endif /* OP_CEILING_HPP_ */
