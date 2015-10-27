/**
 * \file eval.cpp
 *
 * The interface for the expression evaluator function.
 */

#include "eval.hpp"
#include <stdexcept>
#include <math.h>
#include "global_map.hpp"

/**
 * A function that will evaluate the value of that cells and return it in a cell
 */

Cell* eval(Cell* const c)
{
  
  /**
   * 
   * Algorithm: Depth first search
   *
   * Implementation:
   *
   * First get the operator (should be in LHS), and depends what operator and
   * has different operation. For detailed implementation, please refer to the
   * related operator header file.
   *
   * If a conspair cell is reached, first evaluate the car's value first by
   * calling eval(Cell* const c) to the car cell
   *
   */
 
  Cell* operator_cell;
  
  //evaluate the car cell's value
    
  if (nullp(c))
  {
    throw runtime_error("Cannot evaluate an empty list.");
  }
  else if (listp(c))
  {
    if (listp(car(c)))
    {
      operator_cell = eval(car(c));
    }
    else if (symbolp(car(c)))
    {
      operator_cell = search_symbol(get_symbol(car(c)),false);
      if (operator_cell == nil)
      {
        operator_cell = car(c);
      }
    }
    else
    {
       operator_cell = car(c);
    }
  }
  else if (symbolp(c))
  {
    return search_symbol(get_symbol(c),true);
  }
  else
  {
    return c;
  }
   
  Cell* cdr_cell = cdr(c);
  
  if (procedurep(operator_cell))
  {
    return operator_cell->apply(cdr_cell);
  }

  return eval_op(operator_cell,cdr_cell);
  // finish evaluating
}
