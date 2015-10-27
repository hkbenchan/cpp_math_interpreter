/**
 * \file op_substraction.cpp
 *
 * The implementation of operator '-'
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include "op_substraction.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"
#include "global_map.hpp"
#include <stdexcept>

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_substraction::eval_op(Cell* operand) const
{
  // keep adding until reaches nil pointer
  int int_sum = 0;
  double double_sum = 0.0;
  bool double_exist = false;

  Cell* operand_ptr = operand;

  int no_of_operand = no_of_operands(operand,1,2,true,false);

  int current_operand = 1;

  while(!nullp(operand))
  {
    if (nullp(car(operand)))
    {
       if (operand_ptr != NULL)
         delete operand_ptr;
       throw runtime_error("'-' can only deal with integer and double.");
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
       if ((current_operand==1)&&(no_of_operand>1))
          int_sum+= get_int(operand_ptr);
       else
          int_sum -= get_int(operand_ptr);
    }
    else if (doublep(operand_ptr))
    {
       if ((current_operand==1)&&(no_of_operand>1))
          double_sum+= get_double(operand_ptr);
       else
          double_sum -= get_double(operand_ptr);
       double_exist = true;
    }
    else
    {
       if (operand_ptr != NULL)
          delete operand_ptr;
       throw runtime_error("'-' can only deal with integer and double.");
    }
    operand = cdr(operand);
    current_operand++;
  }
  
  if (double_exist)
    return make_double(double_sum+int_sum);
  else
    return make_int(int_sum);
};
