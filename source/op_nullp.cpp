/**
 * \file op_nullp.cpp
 *
 * The implementation of operator 'nullp'
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include "op_nullp.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"
#include "global_map.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_nullp::eval_op(Cell* operand) const
{
  Cell* operand_ptr;

  no_of_operands(operand,1,1,true,true);

  operand_ptr = car(operand);

  if (listp(operand_ptr))
  {
    operand_ptr = eval(operand_ptr);
  }
  else if (symbolp(car(operand)))
  {
    operand_ptr = search_symbol(get_symbol(car(operand)),true);
  }

  if (nullp(operand_ptr))
  {
    return make_int(1);
  }
  else
    return make_int(0);
}
