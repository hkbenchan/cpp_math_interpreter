/**
 * \file DoubleCell.hpp
 *
 * A derived class from abstract class Cell
 * Store a double element
 *
 *  Created on: Oct 10, 2011
 *      Author: ben
 *
 */

#ifndef DOUBLECELL_HPP
#define DOUBLECELL_HPP

#include <iostream>
#include <iomanip>
#include "Cell.hpp"

using namespace std;

class DoubleCell : public Cell
{
public:

  /**
   * \brief Constructor of DoubleCell
   */
  DoubleCell(const double double_val)
  {
    double_m = double_val;
  };


  /**
   * \brief Check if this is a double cell.
   * \return True
   */

  inline bool is_double() const
  {
    return true;
  };

  /**
   * \brief Accessor of DoubleCell
   * \return The value in this double cell
   */

  inline double get_double() const
  {
    return double_m;
  };

  /**
   * \brief Destructor
   */

  inline ~DoubleCell(){};

  /**
   * \brief Print the double value in this cell.
   * \param os The output stream to print to.
   */

  inline void print(ostream& os = cout) const
  {
    os<<fixed<<setprecision(5)<<get_double();
  };


private:

  double double_m;

};

#endif // DOUBLECELL_HPP //


