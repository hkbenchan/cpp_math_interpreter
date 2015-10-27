/**
 * \file op_apply.hpp
 *
 * The interface of the operator 'apply'.
 *
 * 'apply': Link the parameters with formals and then execute the body.
 *
 * It can support exactly two operand.
 *
 * ERROR when:
 *
 * (1) Too many arguments.
 * (2) No or too few arguments.
 *
 *  Created on: Nov 2, 2011
 *      Author: ben
 */

#ifndef OP_APPLY_HPP_
#define OP_APPLY_HPP_

#include "SymbolOperator.hpp"

class op_apply: public SymbolOperator
{
public:
  op_apply(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_apply(){};
};

#endif /* OP_APPLY_HPP_ */
