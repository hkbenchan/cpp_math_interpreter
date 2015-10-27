/*
 * \file op_define.cpp
 *
 *  The implementation of operator 'define'
 *
 *  Created on: Oct 23, 2011
 *      Author: ben
 */

#include "op_define.hpp"
#include "cons.hpp"
#include "Cell.hpp"
#include "eval.hpp"
#include "global_map.hpp"
#include <map>
#include <stdexcept>

/**
 * \brief The evaluator of the operator
 * \param operand The operand that waiting for operation.
 * \return The cell contains evaluated result.
 */

Cell* op_define::eval_op(Cell* operand) const
{

  no_of_operands(operand,2,2,true,true);

  string define_str = get_symbol(car(operand));

  insert_element(define_str,eval(car(cdr(operand))));

  return nil;
}
