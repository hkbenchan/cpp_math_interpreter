/**
 * \file Cell.cpp
 *
 * Define the nil Cell in this file to avoid linker error.
 *
 *  Created on: Oct 10, 2011
 *      Author: ben
 */

#include <iostream>
#include <stdexcept>
#include "Cell.hpp"

using namespace std;

Cell* const nil = 0 ;


/**
 * \brief Check if this is an int cell.
 * \return True iff this is an int cell.
 */

bool Cell::is_int() const
{
  return false;
}

/**
 * \brief Check if this is a double cell.
 * \return True iff this is a double cell.
 */

bool Cell::is_double() const
{
  return false;
}

/**
 * \brief Check if this is a symbol cell.
 * \return True iff this is a symbol cell.
 */

bool Cell::is_symbol() const
{
  return false;
}

/**
 * \brief Check if this is a conspair cell.
 * \return True iff this is a conspair cell.
 */

bool Cell::is_cons() const
{
  return false;
}

/**
 * \brief Check if this is a procedure cell.
 * \return True iff this is a procedure cell.
 */

bool Cell::is_procedure() const
{
  return false;
}

/**
 * \brief Accessor of IntCell
 * \return Default ERROR, because it is not specific cell
 */

int Cell::get_int() const
{
  throw runtime_error("Accessing a non-integer cell.");
}

/**
 * \brief Accessor of DoubleCell
 * \return Default ERROR, because it is not specific cell
 */

double Cell::get_double() const
{
  throw runtime_error("Accessing a non-double cell.");
}

/**
 * \brief Accessor of SymbolCell
 * \return Default ERROR, because it is not specific cell
 */

string Cell::get_symbol() const
{
  throw runtime_error("Accessing a non-symbol cell.");
}

/**
 * \brief Accessor of ConsCell's car
 * \return Default ERROR, because it is not specific cell
 */

Cell* Cell::get_car() const
{
  throw runtime_error("Accessing a non-conspair cell.");
}

/**
 * \brief Accessor of ConsCell's cdr
 * \return Default ERROR, because it is not specific cell
 */

Cell* Cell::get_cdr() const
{
  throw runtime_error("Accessing a non-conspair cell.");
}

/**
 * \brief Accessor of ProcedureCell's formals
 * \return Default ERROR, because it is not specific cell
 */

Cell* Cell::get_formals() const
{
  throw runtime_error("Accessing a non-procedure cell.");
}

/**
 * \brief Accessor of ProcedureCell's body
 * \return Default ERROR, because it is not specific cell
 */

Cell* Cell::get_body() const
{
  throw runtime_error("Accessing a non-procedure cell.");
}

/**
 * \brief Evaluator of cons list given a SymbolCell
 * \return Default ERROR, because only SymbolCell can do operation
 */

Cell* Cell::perform_op(Cell* operand) const
{
  throw runtime_error("Accessing a cell that does not support operation.");
}

/**
 * \brief Apply the function with some arguments
 * \return Default ERROR, because only ProcedureCell can do operation
 */

Cell* Cell::apply(Cell* arguments) const
{
  throw runtime_error("Non-procedure cell does not support 'apply'.");
}
