/**
 * \file op_not.cpp
 *
 *  The implementation of operator 'not'
 *
 *  Created on: Oct 19, 2011
 *      Author: ben
 */


#include "op_not.hpp"
#include <stdexcept>
#include "cons.hpp"
#include "Cell.hpp"
#include "eval.hpp"
#include "global_map.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_not::eval_op(Cell* operand) const
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

  if (intp(operand_ptr) && get_int(operand_ptr)==0)
  {
    return make_int(1);
  }
  else if (doublep(operand_ptr) && get_double(operand_ptr)==0)
  {
    return make_int(1);
  }

  else
    return make_int(0);
}
