/*
 * \file op_define.hpp
 *
 * The interface of the operator 'define'.
 *
 * 'define': Assign specific string(symbol) to a Cell
 * Return null
 *
 * It can support exactly two operands.
 *
 * ERROR when:
 *
 * (1) The first operand is not a SymbolCell.
 * (2) Too many arguments.
 * (3) No arguments.
 * (4) Operand is defined before.
 *
 *  Created on: Oct 23, 2011
 *      Author: ben
 */

#ifndef OP_DEFINE_HPP_
#define OP_DEFINE_HPP_

#include "SymbolOperator.hpp"

class op_define: public SymbolOperator
{
public:
  op_define(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_define(){};
};

#endif /* OP_DEFINE_HPP_ */
