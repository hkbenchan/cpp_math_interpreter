/**
 * \file op_multiply.cpp
 *
 * The implementation of operator '*'
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include "op_multiply.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"
#include <stdexcept>
#include "global_map.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_multiply::eval_op(Cell* operand) const
{
  // keep adding until reaches nil pointer
  int int_sum = 1;
  double double_sum = 1.0;
  bool double_exist = false;

  //to store the result of car cell if it is a list
  Cell* operand_ptr;

  //check if operand is not empty
  while(!nullp(operand))
  {
    if (nullp(car(operand)))
    {
      if (operand_ptr != NULL)
          delete operand_ptr;
      throw runtime_error("'*' can only deal with integer and double.");
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
      int_sum *= get_int(operand_ptr);
    }
    else if (doublep(operand_ptr))
    {
      double_sum *= get_double(operand_ptr);
      double_exist = true;
    }
    else
    {
      if (operand_ptr != NULL)
         delete operand_ptr;
      throw runtime_error("'*' can only deal with integer and double.");
    }
    operand = cdr(operand);
  }

  if (double_exist)
    return make_double(double_sum*int_sum);
  else
    return make_int(int_sum);
};
