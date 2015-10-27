/**
 * \file ProcedureCell.cpp
 *
 *  The implementation of Function apply for the ProcedureCell
 *
 *  Created on: Nov 2, 2011
 *      Author: ben
 */

#include "ProcedureCell.hpp"
#include <iostream>
#include <stdexcept>
#include <map>
#include "global_map.hpp"
#include "eval.hpp"

/**
 * \brief Apply the function with some arguments
 * \param arguments The arguments that will pass into the
 * parameters of the function
 * \return The cell contains the value after evaluated the body
 */

Cell* ProcedureCell::apply(Cell* arguments) const
{
  /**
   * create a local symbol map first
   * get all values in arguments match the one in formal
   * eval the body
   * push the map into the vector<map>
   * when leaving, remove the map (ERROR calls counts)
   */

  map<string, Cell*> local_symbol_map;

  Cell* formal_curr_ptr = formals;
  Cell* argument_curr_ptr = arguments;

  while ((argument_curr_ptr != NULL)&&(formal_curr_ptr != NULL))
  {
    string s = formal_curr_ptr->get_car()->get_symbol();

    Cell* formal_eval = eval(argument_curr_ptr->get_car());

    Cell* target_actually_cell ;
    if (formal_eval == NULL)
        target_actually_cell = formal_eval;
    else if (formal_eval->is_symbol())
        target_actually_cell = search_symbol(formal_eval->get_symbol(),false);
    else target_actually_cell = formal_eval;

    local_symbol_map.insert(pair<string, Cell*>(s,target_actually_cell));

    formal_curr_ptr = formal_curr_ptr->get_cdr();
    argument_curr_ptr = argument_curr_ptr->get_cdr();
  }

  if ((formal_curr_ptr != NULL)||(argument_curr_ptr != NULL))
  {
    throw runtime_error("Number of parameters does not match "
                        "with the function");
  }

  insert_map(local_symbol_map);

  try
  {
    Cell* body_curr_ptr = body;
    Cell* apply_result;
    while (body_curr_ptr != nil)
    {
      apply_result = eval(body_curr_ptr->get_car());
      body_curr_ptr = body_curr_ptr->get_cdr();
    }
    remove_map();
    return apply_result;
  }
  catch (runtime_error& ex)
  {
    /*
     * try to remove the map from the vector before leaving the
     * program to prevent error
     */
    if (ex.what()!="No map to remove")
       remove_map();
    throw ex;
  }

}
