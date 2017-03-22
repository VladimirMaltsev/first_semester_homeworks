/******************************\
* © Maltsev Vladimir | SPbU    *
*   28 November 2016  		   *
\******************************/

#include <stdio.h>
#include <malloc.h>
#include "StackNode.h"
#include "CharStack.h"
#include "OperatorTools.h"

int operator_compare ( char op1 , char op2 )
{
	int op1_prior = 0;
	int op2_prior = 0;
	if ( op1 == '+' || op1 == '-' )
		op1_prior = 1;
	else 
		op1_prior = 2;
	
	if ( op2 != '(' )
		if ( op2 == '+' || op2 == '-' )
			op2_prior = 1;
		else 
			op2_prior = 2;
	return op1_prior - op2_prior;
	
}

void operator_manager ( CStack *cs , char op )
{
	switch ( op )
	{
		case '+':
		case '-':
		case '*':
		case '/':
			while ( cs_pick ( cs ) != -1 && operator_compare ( op , cs_pick ( cs ) ) <= 0 )
				printf ("%c " , cs_pop ( cs ) );
			cs_push ( cs, op );
			break;
		
		case '(':
			cs_push ( cs , op );
			break;
		case ')':
			while ( ( op = cs_pop ( cs ) ) != '(')
				printf ("%c " , op );
			break;
		default:
			printf("wrong input %c" , op );
	}
}
