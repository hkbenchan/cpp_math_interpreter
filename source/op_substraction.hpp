/**
 * \file op_substraction.hpp
 *
 * The interface of the operator '-'.
 *
 *
 * '-': Return the value that a-b if (- a b) is input in the s-expression
 * Return the negative value of a if (- a) is input.
 * Return the value that (a-b)-c if (- a b c) is input.
 *
 * It supports at least one operand.
 *
 * ERROR when:
 *
 * (1) Any cell contains non-Int and non-Double value.
 * (2) No arguments.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_SUBSTRACTION_HPP_
#define OP_SUBSTRACTION_HPP_

#include "SymbolOperator.hpp"

class op_substraction: public SymbolOperator
{
public:
  op_substraction(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */
 
  Cell* eval_op(Cell*) const;

  ~op_substraction(){};
};

#endif /* OP_SUBSTRACTION_HPP_ */
