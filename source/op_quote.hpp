/**
 * \file op_quote.hpp
 *
 * The interface of the operator 'quote'.
 *
 * 'quote': Return the cdr cell upon calling.
 *
 * It can support exactly one operand.
 *
 * ERROR when:
 *
 * (1) Too many arguments.
 * (2) No arguments.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_QUOTE_HPP_
#define OP_QUOTE_HPP_

#include "SymbolOperator.hpp"

class op_quote: public SymbolOperator
{
public:
  op_quote(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_quote(){};
};

#endif /* OP_QUOTE_HPP_ */
