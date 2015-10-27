/**
 * \file op_lessthan.hpp
 *
 * The interface of the operator '<'.
 *
 * '<': Return true if the given sequence is strictly increasing
 *
 * It can support exactly any number of operand.
 *
 * ERROR when:
 *
 * (1) The operand is not a DoubleCell nor IntCell.
 *
 *  Created on: Oct 19, 2011
 *      Author: ben
 */

#ifndef OP_LESSTHAN_HPP_
#define OP_LESSTHAN_HPP_

#include "SymbolOperator.hpp"

class op_lessthan: public SymbolOperator
{
public:
  op_lessthan(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_lessthan(){};
};


#endif /* OP_LESSTHAN_HPP_ */
