/*
 * \file global_map.cpp
 *
 *  The implementation of the global symbol map
 *
 *  Created on: Oct 23, 2011
 *      Author: ben
 */

#include <map>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "global_map.hpp"
#include "cons.hpp"

typedef map <string , Cell*> symbol_map ;

/**
 * \brief The global map that store the reference from a string to a Cell
 */

symbol_map SMap;

/**
 * \brief Iterator of the global map
 */

symbol_map::iterator SMap_it;

/**
 * \brief The symbol map that declare in the function
 * (act as Activation Record)
 */

vector<symbol_map> AR_vector;

/**
 * \brief The searching function of the map
 * \param s The search string
 * \param expected Whether the caller is expected to find this symbol
 * \return The corresponding Cell*
 */

Cell* search_symbol(string s, bool expected)
{
  //stack<symbol_map> temp_AR_stack;
  symbol_map curr_map;
  symbol_map::iterator curr_map_it;
  bool exist = false;
  Cell* linked_symbol = NULL;

/*  while (!(AR_stack.empty()))
  {
    curr_map = AR_stack.top();
    curr_map_it = curr_map.find(s);
    // Check if the current record (map) has the mapped value
    if (curr_map_it != curr_map.end())
    {
      linked_symbol = curr_map_it->second;
      exist = true;
      break;
    }
    else
    {
      temp_AR_stack.push(curr_map);
      AR_stack.pop();
    }
  }
*/
  for (int i = AR_vector.size()-1; i>=0; i--)
  {
    curr_map = AR_vector[i];
    curr_map_it = curr_map.find(s);
    //Check if the current record (map) contains the mapped value
   if (curr_map_it != curr_map.end())
   {
     linked_symbol = curr_map_it->second;
     exist = true;
     break;
   }
  }
  /*
   * after searching the symbol map, if it is still not found,
   * check the global variable record
   */
  if (!exist)
  {
    SMap_it = SMap.find(s);
    if ((SMap_it == SMap.end())&&expected)
    {
      //if (!Symbol_operator_finder(s))
        throw runtime_error("attempt to reference an undefined symbol \"" + s
        +"\"");
      //return make_symbol(s.c_str());
    }
    else if (SMap_it == SMap.end())
    	linked_symbol = NULL;
    else
        linked_symbol = SMap_it->second;
  }

  return linked_symbol;
}

/**
 * \brief Insert the mapping into the latest symbol_map
 * \param s The string that want to map
 * \param map_cell The cell that want to map to the string s
 */

void insert_element(string s, Cell* map_cell)
{

  //check if there is any local symbol table
  if (!(AR_vector.empty()))
  {
    symbol_map curr_map = AR_vector.back();
    AR_vector.pop_back();
    symbol_map::iterator curr_map_it = curr_map.find(s);

    //check if it is defined before
    if (curr_map_it != curr_map.end())
    {
      AR_vector.push_back(curr_map);
      throw runtime_error(s + " cannot be redefined.");
    }
    curr_map[s] = map_cell;
    AR_vector.push_back(curr_map);
  }
  else
  {
    SMap_it = SMap.find(s);

    //check if it is defined before
    if (SMap_it != SMap.end())
      throw runtime_error(s + " cannot be redefined.");
    SMap.insert( pair< string, Cell*>(s,map_cell));
  }
}

/**
 * \brief Insert the map into the stack (act as local variable)
 * \param local_symbol_map The symbol map that is going to push into the stack
 */

void insert_map(symbol_map local_symbol_map)
{
  AR_vector.push_back(local_symbol_map);
}

/**
 * \brief Remove the top map in the stack (ERROR if empty)
 */

void remove_map()
{
  if (AR_vector.empty())
    throw runtime_error("No map to remove");
  AR_vector.pop_back();
}
