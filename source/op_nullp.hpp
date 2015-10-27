/**
 * \file op_nullp.hpp
 *
 * The interface of the operator 'nullp'.
 *
 * 'nullp': Return if operand is empty or not upon calling.
 * (1 for true and 0 for false)
 *
 * It can support exactly one operand.
 *
 * ERROR when:
 *
 * (1) Too many arguments.
 * (2) No arguments.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_NULLP_HPP_
#define OP_NULLP_HPP_

#include "SymbolOperator.hpp"

class op_nullp: public SymbolOperator
{
public:
  op_nullp(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_nullp(){};
};

#endif /* OP_NULLP_HPP_ */
