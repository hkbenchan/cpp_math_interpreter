/**
 * \file op_floor.cpp
 *
 * The implementation of operator 'floor'
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include <cmath>

#include "op_floor.hpp"
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

Cell* op_floor::eval_op(Cell* operand) const
{
  Cell* operand_ptr;

  no_of_operands(operand,1,1,true,true);

  operand_ptr = car(operand);

  if (listp(operand_ptr))
  {
    operand_ptr = eval(operand_ptr);
  }
  else if (symbolp(operand_ptr))
  {
    operand_ptr = search_symbol(get_symbol(operand_ptr),true);
  }

  if (doublep(operand_ptr))
  {
    return make_int( int(floor(get_double(operand_ptr))) );
  }
  else
  {
    if (operand_ptr != NULL)
       delete operand_ptr;
    throw runtime_error("'floor' only operates with double.");
  }
}
