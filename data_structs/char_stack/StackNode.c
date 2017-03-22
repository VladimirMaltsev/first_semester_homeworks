 /************************************************\
 * VStack - stack on lists by © Maltsev Vladimir  *
 *                                                *
 \************************************************/
#include <stdio.h>
#include <malloc.h>
#include "StackNode.h"
#include "CharStack.h"
#include "OperatorTools.h"

 StackNode *snode_init ( char c )
 {
	StackNode *sn = ( StackNode * ) malloc ( sizeof ( StackNode ) );
	sn -> data = c;
	sn -> prev = 0;
	return sn;
 }
 
 StackNode * snode_del ( StackNode *sn )
 {
	free ( sn );
	sn = 0;
	return sn;
 }