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

 StackNode *snode_init ( ListNumber *ln )
 {
	StackNode *sn = ( StackNode * ) malloc ( sizeof ( StackNode ) ) ;
	sn -> data = ln ;
	sn -> prev = 0 ;
	return sn;
 }
 
 StackNode * snode_del ( StackNode *sn )
 {
	if ( sn -> data )
		lnum_del ( sn -> data ) ;
	free ( sn ) ;
	sn = 0;
	return sn ;
 }