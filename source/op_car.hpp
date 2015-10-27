/**
 * \file op_car.hpp
 *
 * The interface of the operator 'car'.
 *
 * 'car': Return the car cell upon calling.
 *
 * It can support exactly one operand.
 *
 * ERROR when:
 *
 * (1) The cell that store the operand is not a list.
 * (2) Too many arguments.
 * (3) No arguments.
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef OP_CAR_HPP_
#define OP_CAR_HPP_

#include "SymbolOperator.hpp"

class op_car: public SymbolOperator
{
public:
  op_car(){};

  /**
   * \brief The evaluator of the operator
   * \return The cell contains evaluated result.
   */
   
  Cell* eval_op(Cell*) const;

  ~op_car(){};
};

#endif /* OP_CAR_HPP_ */
