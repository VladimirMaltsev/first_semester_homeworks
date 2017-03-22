 /***************************************************\
 * CStack - stack on lists by © Maltsev Vladimir     *
 *                                                   *
 \***************************************************/
#include <stdio.h>
#include <malloc.h>
#include "StackNode.h"
#include "CharStack.h"
#include "OperatorTools.h"
 
 CStack *cs_init ( )
 {
	CStack *cs = ( CStack * ) malloc ( sizeof ( CStack ) );
	cs -> top = 0;
 }
 
 CStack *cs_del ( CStack *cs )
 {
	 while (cs -> top )
	 {
		cs_pop ( cs );
	 }
	 free ( cs );
	 cs = 0;
	 return cs;
 }
 
 void cs_push ( CStack *cs , char c )
 {
	StackNode *curr = snode_init( c );
	if ( ! cs -> top )
	{
		cs -> top = curr;
		return;
	}
	curr -> prev = cs -> top;
	cs -> top = curr;
 }
 
 char cs_pick ( CStack *cs )
 {
	if ( cs -> top )
		return cs -> top -> data;
	return -1;
 }
 
 char cs_pop ( CStack *cs )
 {
	if ( ! cs -> top )
		return -1;
	char data = cs -> top -> data;
	StackNode *condemned = cs -> top;
	cs -> top = cs -> top -> prev;
	
	snode_del ( condemned );
	return data;
 }
 