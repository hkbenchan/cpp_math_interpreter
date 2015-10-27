/**
 * \file op_print.hpp
 *
 * The interface of the operator 'print'.
 *
 * 'print': Output the content of the cell
 * Return a null Cell pointer
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

#ifndef OP_PRINT_HPP_
#define OP_PRINT_HPP_

#include "SymbolOperator.hpp"

class op_print: public SymbolOperator
{
public:
  op_print(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */

  Cell* eval_op(Cell*) const;

  ~op_print(){};
};

#endif /* OP_PRINT_HPP_ */
