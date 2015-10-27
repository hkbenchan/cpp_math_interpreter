/**
 * \file op_quote.cpp
 *
 * The implementation of operator 'quote'
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include "op_quote.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_quote::eval_op(Cell* operand) const
{
  //check if there is more than one operand

  no_of_operands(operand,1,1,true,true);

  return car(operand);
};
