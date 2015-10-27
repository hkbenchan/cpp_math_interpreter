/*
 * \file global_map.hpp
 *
 *  The interface that store the global symbol map
 *
 *  Created on: Oct 23, 2011
 *      Author: ben
 */

#ifndef GLOBAL_MAP_HPP_
#define GLOBAL_MAP_HPP_

#include "Cell.hpp"
#include <iostream>
#include <map>
#include <vector>

typedef map <string , Cell*> symbol_map ;

/**
 * \brief A map that store the reference from a string to a Cell
 */

extern symbol_map SMap;

/**
 * \brief Iterator of the map
 */

extern symbol_map::iterator SMap_it;

/**
 * \brief The symbol map that declare in the function
 * (act as Activation Record)
 */

extern vector<symbol_map> AR_vector;

/**
 * \brief The searching function of the map
 * \return The corresponding Cell*
 */

extern Cell* search_symbol(string,bool);

/**
 * \brief Insert the mapping into the latest symbol_map
 */

extern void insert_element(string, Cell*);

/**
 * \brief Insert the map into the stack (act as local variable)
 */

extern void insert_map(symbol_map);

/**
 * \brief Remove the top map in the stack (ERROR if empty)
 */

extern void remove_map();

#endif /* GLOBAL_MAP_HPP_ */
