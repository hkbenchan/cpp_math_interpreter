/*
 * \file op_print.cpp
 *
 * The implementation of operator 'print'
 *
 *  Created on: Oct 19, 2011
 *      Author: ben
 */

#include "op_print.hpp"
#include "Cell.hpp"
#include "cons.hpp"
#include "eval.hpp"
#include "global_map.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_print::eval_op(Cell* operand) const
{
  //check if there is more than one operand

  no_of_operands(operand,1,1,true,true);

  Cell* operand_ptr;

  if (listp(car(operand)))
  {
    operand_ptr = eval(car(operand));
  }
  else if (symbolp(car(operand)))
  {
    operand_ptr = search_symbol(get_symbol(car(operand)),true);
  }
  else
    operand_ptr = car(operand);
  if (!nullp(operand_ptr))
  {
    operand_ptr->print();
    cout<<endl;
    operand_ptr = nil;
  }
  else
  {
    cout<<"()\n";
  }
  return nil;

};
