/*
 * symbol_table.h
 *
 *  Created on: Jan 28, 2013
 *      Author: azk
 */

#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <map>
#include <string>
#include <deque>
#include <utility>

#include "shared.h"

typedef std::pair<int,Type> SymbolInfo;
typedef std::map<std::string,SymbolInfo> SymbolTable;
typedef std::deque<SymbolTable> ScopedST;

extern ScopedST scopedSymTable;

int addToSymbolTable(std::string symName, Type symType, int memLocation);
int getSymbolOffset(std::string symName);
Type getSymbolType(std::string symName);

void addSymbolScope();
void removeSymbolScope();

#endif /* SYMBOL_TABLE_H_ */
