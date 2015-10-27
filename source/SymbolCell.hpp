/**
 * \file SymbolCell.hpp
 *
 * A derived class from abstract class Cell
 * Store a string element
 *
 *  Created on: Oct 10, 2011
 *      Author: ben
 */

#ifndef SYMBOLCELL_HPP
#define SYMBOLCELL_HPP

#include <iostream>
#include <cstring>
#include <string>
#include "Cell.hpp"
#include "SymbolOperator.hpp"

using namespace std;

class SymbolCell : public Cell
{
public:

  /**
   * \brief Constructor of SymbolCell
   */
  SymbolCell(const char* const string_s)
  {
    int length = strlen(string_s);
    symbol_m = new char[length+1];
    //copy the content into new string
    strcpy(symbol_m,string_s);
  };

  /**
   * \brief Check if this is a symbol cell.
   * \return True
   */

  bool is_symbol() const
  {
    return true;
  };

  /**
   * \brief Accessor of SymbolCell
   * \return The string in this SymbolCell
   */

  inline string get_symbol() const
  {
    return symbol_m;
  };

  /**
   * \brief Destructor
   */

  inline virtual ~SymbolCell()
  {
    delete[] symbol_m;
  }

  /**
   * \brief Print the sybmol in this cell.
   * \param os The output stream to print to.
   */

  inline void print(ostream& os) const
  {
    os<<get_symbol();
  };

private:

  char* symbol_m;
};

#endif // SYMBOLCELL_HPP
