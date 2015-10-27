/**
 * \file op_lessthan.cpp
 *
 *  The implementation of operator '<'
 *
 *  Created on: Oct 19, 2011
 *      Author: ben
 */

#include "op_lessthan.hpp"
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

Cell* op_lessthan::eval_op(Cell* operand) const
{
  double previous_element_value;

  bool first_element = true;

  bool less_than = true;

  Cell* operand_ptr;

  while(!nullp(operand))
  {
    if (nullp(car(operand)))
    {
       throw runtime_error("'<' can only deal with integer and double.");
    }
    else if (listp(car(operand)))
    {
       operand_ptr = eval(car(operand));
    }
    else if (symbolp(car(operand)))
    {
       operand_ptr = search_symbol(get_symbol(car(operand)),true);
    }
    else
    {
       operand_ptr = car(operand);
    }

    if (intp(operand_ptr))
    {
       if (!first_element)
       {
          if (previous_element_value >= get_int(operand_ptr))
	        less_than = false;
       }
       previous_element_value = get_int(operand_ptr);
    }
    else if (doublep(operand_ptr))
    {
       if (!first_element)
       {
	  if (previous_element_value >= get_double(operand_ptr))
	      less_than = false;
       }
       previous_element_value = get_double(operand_ptr);
    }
    else
    {
       throw runtime_error("'<' can only deal with integer and double.");
    }

    first_element = false;

    operand = cdr(operand);
  }

 
  if (less_than)
    return make_int(1);
  else return make_int(0);
}
