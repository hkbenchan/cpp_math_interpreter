/**
 * \file op_eval.hpp
 *
 * The interface of the operator 'eval'.
 *
 * 'eval': Return an evaluated Cell
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

#ifndef OP_EVAL_HPP_
#define OP_EVAL_HPP_

#include "SymbolOperator.hpp"

class op_eval: public SymbolOperator
{
public:
  op_eval(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_eval(){};
};

#endif /* OP_EVAL_HPP_ */
