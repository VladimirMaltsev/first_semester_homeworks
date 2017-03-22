 /************************************************\
 * VStack - stack on lists by © Maltsev Vladimir  *
 *                                                *
 \************************************************/
#include <stdio.h>
#include <malloc.h>

#include "IntNode.h"
#include "ListNumber.h"
#include "StackNode.h"
#include "VStack.h" 

 VStack *vs_init ( )
 {
	VStack *vs = ( VStack * ) malloc ( sizeof ( VStack ) ) ;
	vs -> top = 0;
 }
 
 VStack *vs_del ( VStack *vs )
 {
	 while (vs_pick( vs ) ){
		StackNode *next = vs -> top -> prev;
	 	snode_del ( vs -> top ) ;
		vs -> top = next;
	 }
	 free ( vs );
	 vs = 0;
	 return vs ;
 }
 
 void vs_push ( VStack *vs , ListNumber *ln )
 {
	StackNode *curr = snode_init( ln ) ;
	if ( ! vs -> top )
	{
		vs -> top = curr ;
		return ;
	}
	curr -> prev = vs -> top ;
	vs -> top = curr;
 }
 
 ListNumber *vs_pick ( VStack *vs )
 {
	if ( vs -> top )
		return vs -> top -> data;
	return 0;
 }
 
 ListNumber *vs_pop ( VStack *vs )
 {
	if ( ! vs -> top )
		return 0;
	ListNumber *data = vs -> top -> data;
	vs -> top -> data = 0;
	StackNode *condemned = vs -> top ;
	vs -> top = vs -> top -> prev;
	
	snode_del ( condemned ) ;
	return data ;
 }
 