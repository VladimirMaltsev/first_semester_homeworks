/******************************\
* © Maltsev Vladimir | SPbU    *
*   28 November 2016  		   *
\******************************/
#include <stdio.h>
#include <malloc.h>
#include "StackNode.h"
#include "CharStack.h"
#include "OperatorTools.h"

int main () 
{
	char op = '\0';
	CStack *cs = cs_init ( );
	while ( ( op = fgetc ( stdin ) ) != '\n' && op >= 0)
	{
		
		if ( op >= '0' && op <= '9' || op == ' ')
		{
			if ( op != ' ' )	
				printf ("%c" , op );
			continue;
		}
		printf (" ");
		operator_manager ( cs , op );
	}
	while ( cs_pick ( cs ) >= 0 )
		printf (" %c " , cs_pop ( cs ) );
	cs_del ( cs );
	return 0;
}