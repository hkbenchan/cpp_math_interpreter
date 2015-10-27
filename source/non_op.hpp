/**
 * \file non_op.hpp
 *
 * Implementation for non-defined operator
 * There is no defined operation with non-operator.
 *
 *  Created on: Oct 12, 2011
 *      Author: ben
 */

#ifndef NON_OP_HPP_
#define NON_OP_HPP_

#include "SymbolOperator.hpp"
#include <stdexcept>
#include "Cell.hpp"
#include "eval.hpp"
#include "global_map.hpp"
#include "cons.hpp"
#include <string>
#include <cstring>

class non_op: public SymbolOperator
{
public:

  non_op(string s)
  {
    operator_name = s;
  };

  /**
   * \brief The evaluator of the operator
   * \param operand The operand that waiting for operation.
   * \return ERROR as it is not defined.
   */

  Cell* eval_op(Cell* operand) const
  {
    throw runtime_error("Undefined operator for " + operator_name);
    ///Cell* function_ptr = search_symbol(operator_name);
    ///if (function_ptr == NULL)
    ///	throw runtime_error("Undefined operator for " + operator_name);
    //Cell* full_function_call = cons(function_ptr, operand);
    ///return function_ptr->apply(operand);
    //return (new op_apply())->eval_op(full_function_call);
    //return eval(full_function_call);
  }

  ~non_op(){};

private:
  string operator_name;
};


#endif /* NON_OP_HPP_ */
