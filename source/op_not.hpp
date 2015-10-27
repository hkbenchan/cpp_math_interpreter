/**
 * \file op_not.hpp
 *
 * The interface of the operator 'not'.
 *
 * 'not': Return 1 if the operand is zero, otherwise 0
 *
 * It can support exactly one operand.
 *
 * ERROR when:
 *
 * (1) Too many arguments.
 * (2) No arguments.
 *
 *  Created on: Oct 19, 2011
 *      Author: ben
 */

#ifndef OP_NOT_HPP_
#define OP_NOT_HPP_

#include "SymbolOperator.hpp"

class op_not: public SymbolOperator
{
public:
  op_not(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_not(){};
};

#endif /* OP_NOT_HPP_ */
