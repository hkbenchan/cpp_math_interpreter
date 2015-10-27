/**
 * \file ProcedureCell.hpp
 *
 * A derived class from abstract class Cell
 * Store the anonymous function
 *
 *  Created on: Nov 2, 2011
 *      Author: ben
 */

#ifndef PROCEDURECELL_HPP_
#define PROCEDURECELL_HPP_

#include <iostream>
#include "Cell.hpp"

using namespace std;

class ProcedureCell : public Cell
{
public:

  /**
   * \brief constructor of Procedure Cell
   */

  ProcedureCell(Cell* const my_formals,Cell* const my_body)
  {
    formals = my_formals;
    body = my_body;
  }

  /**
   * \brief destructor of Procedure Cell
   */

  ~ProcedureCell()
  {
    if (formals != nil)
      delete formals;
    if (body != nil)
      delete body;
  }

  /**
   * \brief Check if this is a procedure cell.
   * \return True
   */

  bool is_procedure() const
  {
    return true;
  }

  /**
   * \brief Accessor of ProcedureCell's formals
   * \return The formals store in this procedure cell
   */

  Cell* get_formals() const
  {
    return formals;
  }

  /**
   * \brief Accessor of ProcedureCell's body
   * \return The body store in this procedure cell
   */

  Cell* get_body() const
  {
    return body;
  }

  /**
   * \brief Apply the function with some arguments
   * \return The cell contains the value after evaluated the body
   */

  Cell* apply(Cell*) const;

  /**
   * \brief Print the content in this cell, with value.
   * \param os The output stream to print to.
   */

  void print(ostream& os = cout) const
  {
    os<<"#<function> ";
    if (formals != NULL)
       formals->print();
    else os<<"()";
  }

private:
        Cell* formals;
        Cell* body;
};

#endif /* PROCEDURECELL_HPP_ */
