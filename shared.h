/*
 * shared.h
 *
 *  Created on: Jan 27, 2013
 *      Author: azk
 */

#ifndef SHARED_H_
#define SHARED_H_

#include <string>
#include <list>

typedef enum
{
	BOOL_T,
	INT_T,
	NIS_T,
	AGORA_T
} Type;

typedef enum
{
	GE_R,
	SE_R,
	EQ_R,
	NEQ_R,
	GT_R,
	ST_R
} RelOp;

typedef	struct
{
	std::list<int> trueList;
	std::list<int> falseList;
	std::list<int> nextList;
	struct
	{
		std::string	idName;
		Type varType;
		int numValue;
		bool boolValue;
	}	varTraits;
	int memoryOffset;

	bool isConst;
} ExpTraits;

typedef union
{
	struct
	{
		std::string	idName;
		Type varType;
		int numValue;
	}	varTraits;
	ExpTraits expTraits;
	struct
	{
		std::list<int> nextList;
	} statementList;

	Type typeTrait;
	int numValue;
	std::string stringValue;

	int bufferLocation;

	RelOp relOp;
} STYPE;

#define YYTYPE STYPE

#endif /* SHARED_H_ */
