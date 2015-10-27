/**
 * \file SymbolDecider.hpp
 *
 * An interface that decides what symbol it is and pass back for further action
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#ifndef SYMBOLDECIDER_HPP_
#define SYMBOLDECIDER_HPP_

#include <iostream>
#include "SymbolCell.hpp"
#include "SymbolOperator.hpp"

using namespace std;

/**
 * \brief An interface that decides what symbol it is.
 * \return A SymbolOperator that can use to call its perform
 */

SymbolOperator* Symbol_operator_decider(string);

/**
 * \brief A helper function to decide whether the given string
 * represents a pre-defined function
 * \return True if there is a operator match with the given string,
 * false otherwise
 */

bool Symbol_operator_finder(string);

#endif /* SYMBOLDECIDER_HPP_ */
