/**
 * \file op_cdr.hpp
 *
 * The interface of the operator 'cdr'.
 *
 * 'cdr': Return the cdr cell upon calling.
 *
 * It can support exactly one operand.
 *
 * ERROR when:
 *
 * (1) The cell that store the operand is not a list.
 * (2) Too many arguments.
 * (3) No arguments.
 *
 * Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_CDR_HPP_
#define OP_CDR_HPP_

#include "SymbolOperator.hpp"

class op_cdr: public SymbolOperator
{
public:
  op_cdr(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */
 
  Cell* eval_op(Cell*) const;

  ~op_cdr(){};
};

#endif /* OP_CDR_HPP_ */
