/**
 * \file op_apply.cpp
 *
 * The implementation of operator 'apply'
 *
 *  Created on: Nov 2, 2011
 *      Author: ben
 */

#include "op_apply.hpp"
#include "cons.hpp"
#include "Cell.hpp"
#include "eval.hpp"
#include <stdexcept>
#include "global_map.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_apply::eval_op(Cell* operand) const
{
  no_of_operands(operand,2,2,true,true);

  Cell* procedure = eval(car(operand));

  return procedure->apply(eval(car(cdr(operand))));
}
