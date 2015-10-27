/**
 * \file op_eval.cpp
 *
 *  The implementation of operator 'eval'
 *
 *  Created on: Oct 19, 2011
 *      Author: ben
 */

#include "op_eval.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */


Cell* op_eval::eval_op(Cell* operand) const
{
  //check if there is more than one operand

  no_of_operands(operand,1,1,true,true);

  if (listp(car(operand)))
    return eval(eval(car(operand)));
  else if (symbolp(car(operand)))
    return eval(eval(car(operand)));
  else
    return eval(car(operand));
};

