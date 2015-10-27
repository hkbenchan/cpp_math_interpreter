/**
 * \file op_cons.hpp
 *
 * The interface of the operator 'cons'.
 *
 * 'cons': Make a ConsCell which contains two cell based on its operands.
 *
 * It can support exactly two operand.
 *
 * ERROR when:
 *
 * (1) The cell that store the operand is not a list.
 * (2) Too many arguments.
 * (3) No or too few arguments.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_CONS_HPP
#define OP_CONS_HPP

#include "SymbolOperator.hpp"

class op_cons: public SymbolOperator
{
public:
  op_cons(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_cons(){};
};

#endif // OP_CONS_HPP
