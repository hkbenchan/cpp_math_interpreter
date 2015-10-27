/**
 * \file op_if.cpp
 *
 * The implementation of operator 'if'
 *
 *  Created on: Oct 12, 2011
 *      Author: ben
 */

#include "op_if.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"
#include "global_map.hpp"

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */
 
Cell* op_if::eval_op(Cell* operand) const
{
  Cell* operand_ptr;

  int no_of_operand = no_of_operands(operand,2,3,true,true);

  bool true_flag = false;

  operand_ptr = car(operand);

  if (listp(operand_ptr))
  {
     operand_ptr = eval(operand_ptr);
  }
  else if (symbolp(operand_ptr))
  {
     operand_ptr = search_symbol(get_symbol(operand_ptr),true);
  }

  if ((intp(operand_ptr))&&(get_int(operand_ptr)!=0))
  {
     true_flag = true;
  }
  else if ((doublep(operand_ptr)&&(get_double(operand_ptr)!=0)))
  {
     true_flag = true;
  }
  else if ((symbolp(operand_ptr)))
  {
     true_flag = true;
  }
  else if ((listp(operand_ptr)))
  {
     true_flag = true;
  }

  operand = cdr(operand);
  operand_ptr = car(operand);
  
  if (true_flag)
  {
  
    if (listp(operand_ptr))
    {
       operand_ptr = eval(operand_ptr);
    }
    else if (symbolp(operand_ptr))
    {
      Cell* possible_Cell = search_symbol(get_symbol(operand_ptr),false);
      operand_ptr = possible_Cell==NULL?operand_ptr:possible_Cell;
    }
    
    return operand_ptr;
  }

  if (no_of_operand==2)
  {
     return make_symbol("WARNING: Undefined third operand");
  }

  operand = cdr(operand);
  operand_ptr = car(operand);

  if (listp(operand_ptr))
  {
    operand_ptr = eval(operand_ptr);
  }
  else if (symbolp(operand_ptr))
  {
    Cell* possible_Cell = search_symbol(get_symbol(operand_ptr),false);
    operand_ptr = possible_Cell==NULL?operand_ptr:possible_Cell;
  }

  return operand_ptr;

}
