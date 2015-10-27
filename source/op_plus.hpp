/**
 * \file op_plus.hpp
 *
 * The interface of the operator '+'.
 *
 * '+': Return a+b if (+ a b) is called. Return a if (+ a) is called.
 * Return 0 if there is no operand. Return a+b+c if (+ a b c) is called.
 *
 * It can support any number of operands.
 *
 * ERROR when:
 *
 * (1) Any cell contains non-Int and non-Double value.
 *
 *  Created on: Oct 12, 2011
 *      Author: ben
 */

#ifndef OP_PLUS_HPP_
#define OP_PLUS_HPP_

#include "SymbolOperator.hpp"

class op_plus: public SymbolOperator
{
public:
  op_plus(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_plus(){};
};


#endif /* OP_PLUS_HPP_ */
