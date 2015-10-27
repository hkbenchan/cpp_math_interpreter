/**
 * \file op_cons.cpp
 *
 * The implementation of operator 'cons'
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include "op_cons.hpp"
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

Cell* op_cons::eval_op(Cell* operand) const
{

  no_of_operands(operand,2,2,true,true);

  Cell* car_cell;
  Cell* cdr_cell;
  if (operand != nil)
  {
     if (listp(car(operand)))
       car_cell = eval(car(operand));
     else if (symbolp(car(operand)))
       car_cell = search_symbol(get_symbol(car(operand)),true);
     else car_cell = car(operand);

     if (cdr(operand) != nil)
     {
        if (listp(car(cdr(operand))))
           cdr_cell = eval(car(cdr(operand)));
        else if (symbolp(car(cdr(operand))))
           cdr_cell = search_symbol(get_symbol(car(cdr(operand))),true);
        else cdr_cell = car(cdr(operand));
     }
     else
     {
         throw runtime_error("One of the operand is null!");
     }
  }
  else
  {
      throw runtime_error("One of the operand is null!");
  }

  if (!listp(cdr_cell))
  {
    if (car_cell != NULL)
      delete car_cell;
    if (cdr_cell !=NULL)
      delete cdr_cell;

    throw runtime_error("cdr must either be nil or a conspair");
  }

  return cons(car_cell,cdr_cell);
}
