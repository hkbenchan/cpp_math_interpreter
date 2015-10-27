/**
 * \file op_car.cpp
 *
 * The implementation of operator 'car'.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include "op_car.hpp"
#include "cons.hpp"
#include <stdexcept>
#include "Cell.hpp"
#include "global_map.hpp"
#include "eval.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_car::eval_op(Cell* operand) const
{
  Cell* operand_ptr;

  no_of_operands(operand,1,1,true,true);


  if (listp(operand))
  {
    operand_ptr = car(operand);
  }
  else
  {
    throw runtime_error("No conspair for car's operation.");
  }

  if (symbolp(operand_ptr))
  {
    operand_ptr = search_symbol(get_symbol(operand_ptr),true);
  }

  if (listp(operand_ptr))
  {
    operand_ptr = eval(car(operand));
  }
  else
  {
    throw runtime_error("No conspair for car's operation.");
  }

  if (!listp(operand_ptr))
  {
    return operand_ptr;
  }
  return car(operand_ptr);
}
