/**
 * \file op_if.hpp
 *
 * The interface of the operator 'if'.
 *
 * 'if': By checking the first operand is zero or not, it will return the
 * third or second operand respectively.
 *
 * If third operand should be return but there is no third operand, it will
 * return a string WARNING that the third operand is not defined.
 *
 * It can support exactly two or three operands.
 *
 * ERROR when:
 *
 * (1) Too many arguments.
 * (2) No or too few arguments.
 *
 *  Created on: Oct 12, 2011
 *      Author: ben
 */

#ifndef OP_IF_HPP_
#define OP_IF_HPP_

#include "SymbolOperator.hpp"

class op_if: public SymbolOperator
{
public:

  op_if(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_if(){};
};

#endif /* OP_IF_HPP_ */
