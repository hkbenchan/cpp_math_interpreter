/**
 * \mainpage COMP3031 Programming Assignment 4, Fall 2011
 *
 * \author Ben Chan
 * \author ustbenchan@gmail.com
 *
 * \date 2th November 2011
 *
 * Instructor: <a href="http://www.cs.ust.hk/~dekai/">Dekai Wu</a>
 */

/**
 * \file Cell.hpp
 *
 * Encapsulates the abstract interface for a concrete class-based
 * implementation of cells for a cons list data structure.
 */

#ifndef CELL_HPP
#define CELL_HPP

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <map>

using namespace std;


/**
 * \class Cell
 * \brief Abstract Class Cell
 */


class Cell
{
public:

  /**
   * \brief Check if this is an int cell.
   * \return True iff this is an int cell.
   */

  virtual bool is_int() const;

  /**
   * \brief Check if this is a double cell.
   * \return True iff this is a double cell.
   */

  virtual bool is_double() const;

  /**
   * \brief Check if this is a symbol cell.
   * \return True iff this is a symbol cell.
   */

  virtual bool is_symbol() const;

  /**
   * \brief Check if this is a conspair cell.
   * \return True iff this is a conspair cell.
   */

  virtual bool is_cons() const;

  /**
   * \brief Check if this is a procedure cell.
   * \return True iff this is a procedure cell.
   */

  virtual bool is_procedure() const;

  /**
   * \brief Accessor of IntCell
   * \return Default ERROR, because it is not specific cell
   */

  virtual int get_int() const;

  /**
   * \brief Accessor of DoubleCell
   * \return Default ERROR, because it is not specific cell
   */

  virtual double get_double() const;

  /**
   * \brief Accessor of SymbolCell
   * \return Default ERROR, because it is not specific cell
   */

  virtual string get_symbol() const;

  /**
   * \brief Accessor of ConsCell's car
   * \return Default ERROR, because it is not specific cell
   */

  virtual Cell* get_car() const;

  /**
   * \brief Accessor of ConsCell's cdr
   * \return Default ERROR, because it is not specific cell
   */

  virtual Cell* get_cdr() const;

  /**
   * \brief Accessor of ProcedureCell's formals
   * \return Default ERROR, because it is not specific cell
   */

  virtual Cell* get_formals() const;

  /**
   * \brief Accessor of ProcedureCell's body
   * \return Default ERROR, because it is not specific cell
   */

  virtual Cell* get_body() const;


  /**
   * \brief Evaluator of cons list given a SymbolCell
   * \return Default ERROR, because only SymbolCell can do operation
   */

  virtual Cell* perform_op(Cell*) const;

  /**
   * \brief Apply the function with some arguments
   * \return Default ERROR, because only ProcedureCell can do operation
   */

  virtual Cell* apply(Cell*) const;

  /**
   * \brief Destructor
   */

  virtual ~Cell(){};

  /**
   * \brief Print the content in this cell, with value.
   * \param os The output stream to print to.
   */

  virtual void print(ostream& os = cout) const = 0;

};

//extern map < string , Cell* > SMap;

//extern map < string , Cell* >::iterator SMap_it;

extern Cell* const nil;

#include "IntCell.hpp"
#include "DoubleCell.hpp"
#include "SymbolCell.hpp"
#include "ConsCell.hpp"
#include "ProcedureCell.hpp"

#endif // CELL_HPP
