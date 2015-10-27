/**
 * \file SymbolDecider.cpp
 *
 * The implementation that decides what symbol it is and pass back for 
 * further action
 *
 *  Created on: Oct 13, 2011
 *      Author: ben
 */

#include <iostream>
#include <map>
#include "SymbolCell.hpp"
#include "SymbolDecider.hpp"
#include "SymbolOperator.hpp"
#include "op_ceiling.hpp"
#include "op_if.hpp"
#include "op_plus.hpp"
#include "op_floor.hpp"
#include "op_substraction.hpp"
#include "op_multiply.hpp"
#include "op_division.hpp"
#include "op_quote.hpp"
#include "op_nullp.hpp"
#include "op_cons.hpp"
#include "op_car.hpp"
#include "op_cdr.hpp"
#include "op_lessthan.hpp"
#include "op_not.hpp"
#include "op_print.hpp"
#include "op_eval.hpp"
#include "op_define.hpp"
#include "op_lambda.hpp"
#include "op_apply.hpp"
#include "non_op.hpp"


using namespace std;

map<string, SymbolOperator*> op_map;


/**
 * \brief Initialize the operator map for function
 */

void initalize_map()
{
  if (op_map.empty())
  {
    op_map.insert(pair<string,SymbolOperator*>("ceiling",new op_ceiling()));
    op_map.insert(pair<string,SymbolOperator*>("if",new op_if()));
    op_map.insert(pair<string,SymbolOperator*>("+",new op_plus()));
    op_map.insert(pair<string,SymbolOperator*>("floor",new op_floor()));
    op_map.insert(pair<string,SymbolOperator*>("-",new op_substraction()));
    op_map.insert(pair<string,SymbolOperator*>("*",new op_multiply()));
    op_map.insert(pair<string,SymbolOperator*>("/",new op_division()));
    op_map.insert(pair<string,SymbolOperator*>("quote",new op_quote()));
    op_map.insert(pair<string,SymbolOperator*>("nullp",new op_nullp()));
    op_map.insert(pair<string,SymbolOperator*>("cons",new op_cons()));
    op_map.insert(pair<string,SymbolOperator*>("car",new op_car()));
    op_map.insert(pair<string,SymbolOperator*>("cdr",new op_cdr()));
    op_map.insert(pair<string,SymbolOperator*>("<",new op_lessthan()));
    op_map.insert(pair<string,SymbolOperator*>("not",new op_not()));
    op_map.insert(pair<string,SymbolOperator*>("print",new op_print()));
    op_map.insert(pair<string,SymbolOperator*>("eval",new op_eval()));
    op_map.insert(pair<string,SymbolOperator*>("define",new op_define()));
    op_map.insert(pair<string,SymbolOperator*>("lambda",new op_lambda()));
    op_map.insert(pair<string,SymbolOperator*>("apply",new op_apply()));
  }

}

/**
 * \brief An interface that decides what symbol it is.
 * \param s A string that contains the symbol
 * \return A SymbolOperator that can use to call its perform
 */

SymbolOperator* Symbol_operator_decider(string s)
{
  if (op_map.empty())
     initalize_map();
  map< string, SymbolOperator*>::iterator result_pair = op_map.find(s);
  SymbolOperator* symbol_op;

  if (result_pair != op_map.end())
    symbol_op = op_map.find(s)->second;
  else
     symbol_op = new non_op(s);
  return symbol_op;
}

/**
 * \brief A helper function to decide whether the given string
 * represents a pre-defined function
 * \param s The string that wants to find
 * \return True if there is a operator match with the given string,
 * false otherwise
 */

bool Symbol_operator_finder(string s)
{
  if (op_map.empty())
     initalize_map();
  if (op_map.find(s)->second!=NULL)
     return true;
  else return false;
}
