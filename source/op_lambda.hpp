/*
 * \file op_lambda.hpp
 *
 * The interface of the operator 'lambda'.
 *
 * 'lambda': Construct a ProcedureCell then return it.
 *
 * It supports at least two operands -- list of parameters and
 * list of operations.
 *
 * ERROR when:
 *
 * (1) Too few argument(s).
 *
 *  Created on: Nov 2, 2011
 *      Author: ben
 */

#ifndef OP_LAMBDA_HPP_
#define OP_LAMBDA_HPP_

#include "SymbolOperator.hpp"

class op_lambda: public SymbolOperator
{
public:
  op_lambda(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_lambda(){};
};

#endif /* OP_LAMBDA_HPP_ */
