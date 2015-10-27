/**
 * \file IntCell.hpp
 *
 * A derived class from abstract class Cell
 * Store an integer element
 *
 *  Created on: Oct 10, 2011
 *      Author: ben
 */

#ifndef INTCELL_HPP
#define INTCELL_HPP

#include <iostream>
#include "Cell.hpp"

using namespace std;

class IntCell : public Cell
{
public:

  /**
   * \brief Constructor of IntCell
   */
  IntCell(const int int_val)
  {
    int_m = int_val;
  };

  /**
   * \brief Check if this is an int cell.
   * \return True
   */

  inline bool is_int() const
  {
    return true;
  };

  /**
   * \brief Accessor of IntCell
   * \return The value in this int cell.
   */

  inline int get_int() const
  {
    return int_m;
  };

  /**
   * \brief Destructor
   */

  inline ~IntCell(){};

  /**
   * \brief Print the integer value in this cell.
   * \param os The output stream to print to.
   */

  inline void print(ostream& os = cout) const
  {
    os<<get_int();
  };


private:
  int int_m;
};

#endif // INTCELL_HPP
