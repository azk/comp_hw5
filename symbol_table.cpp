/*
 * symbol_table.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: azk
 */

#include "symbol_table.h"

using namespace std;

ScopedST scopedSymTable;


int addToSymbolTable(std::string symName, Type symType, int memLocation)
{
	SymbolInfo tempData(memLocation,symType);
	scopedSymTable.front().insert(make_pair(symName,tempData));

	return memLocation;
}

int getSymbolOffset(std::string symName)
{
	SymbolTable::iterator resIt;
	for (ScopedST::iterator it = scopedSymTable.begin(); it != scopedSymTable.end() ; it++)
	{
		resIt = (*it).find(symName);
		if (resIt != (*it).end())
		{
			return (*resIt).second.first;
		}
	}

	return 0;
}

Type getSymbolType(std::string symName)
{
	SymbolTable::iterator resIt;
	for (ScopedST::iterator it = scopedSymTable.begin(); it != scopedSymTable.end() ; it++)
	{
		resIt = (*it).find(symName);
		if (resIt != (*it).end())
		{
			return (*resIt).second.second;
		}
	}

	return INT_T;
}

void addSymbolScope()
{
	scopedSymTable.push_front(SymbolTable());
}
void removeSymbolScope()
{
	scopedSymTable.pop_front();
}




