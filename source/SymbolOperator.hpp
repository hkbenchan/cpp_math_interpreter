/**
 * \file SymbolOperator.hpp
 *
 * Encapsulates the abstract interface for a concrete class-based
 * implementation of operator for the SymbolCell.
 *
 *  Created on: Oct 10, 2011
 *      Author: ben
 */

#ifndef SYMBOLOPERATOR_HPP
#define SYMBOLOPERATOR_HPP

#include <iostream>
#include "Cell.hpp"

using namespace std;

class SymbolOperator
{
public:

  /**
   * \brief The evaluator of the operator
   * \return The cell that contains value after the specific evaluation.
   */

  virtual Cell* eval_op(Cell*) const = 0;

  virtual ~SymbolOperator(){};

};

#endif // SYMBOLOPERATOR_HPP
