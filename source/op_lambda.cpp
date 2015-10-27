/*
 * \file op_lambda.cpp
 *
 * The implementation of operator 'lambda'.
 *
 *  Created on: Nov 2, 2011
 *      Author: ben
 */

#include "op_lambda.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_lambda::eval_op(Cell* operand) const
{
  //check if there are at least two operands

  no_of_operands(operand,2,2,true,false);

  return lambda(car(operand),cdr(operand));
};

