 /***************************************************\
 * CStack - stack on lists by © Maltsev Vladimir  	 *
 *                                                   *
 \***************************************************/
# pragma once
 
 typedef struct CStack
 {
	StackNode *top;
 } CStack;
 
 CStack *cs_init ( );
 
 CStack *cs_del ( CStack *cs );
 
 void cs_push ( CStack *cs , char c );
 
 char cs_pick ( CStack *cs );
 
 char cs_pop (CStack *cs );
 