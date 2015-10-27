/**
 * \file ConsCell.hpp
 *
 * A derived class from abstract class Cell
 * Store a conspair element
 *
 *  Created on: Oct 10, 2011
 *      Author: ben
 */

#ifndef CONSCELL_HPP
#define CONSCELL_HPP

#include <iostream>
#include "Cell.hpp"

using namespace std;

class ConsCell : public Cell
{
public:

  /**
   * \brief Constructor of ConsCell
   */
  ConsCell(Cell* const my_car, Cell* const my_cdr)
  {
    car_m = my_car;
    cdr_m = my_cdr;
  };

  /**
   * \brief Check if this is a conspair cell.
   * \return True
   */

  inline bool is_cons() const
  {
    return true;
  };

  /**
   * \brief Accessor of ConsCell's car
   * \return First child cell.
   */

  inline Cell* get_car() const
  {
    return car_m;
  };

  /**
   * \brief Accessor of ConsCell's cdr
   * \return Rest child cell.
   */

  inline Cell* get_cdr() const
  {
    return cdr_m;
  };

  /**
   * \brief Destructor
   */

  inline ~ConsCell()
  {
    delete car_m;
    delete cdr_m;
  }

  /**
   * \brief Print the list in this cell.
   * \param os The output stream to print to.
   */

  inline void print(ostream& os) const
  {
    os<<"(";

    const Cell* operands_ptr = this;

    while (operands_ptr!=nil)
    {
	  if (!operands_ptr->is_cons())
	  {
	    operands_ptr->print(os);
	    break;
	  }
	  
	  if (operands_ptr->get_car()==nil)
	    os<<"()";
	  else
	    operands_ptr->get_car()->print(os);
	    
	  if (operands_ptr->get_cdr()!=nil)
	    os<<" ";
	    
	  operands_ptr = operands_ptr->get_cdr();
    }

    os<<")";
  };


private:

  Cell* car_m;
  Cell* cdr_m ;

};

#endif // CONSCELL_HPP
