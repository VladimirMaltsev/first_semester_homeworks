 /************************************************\
 * VStack - stack on lists by © Maltsev Vladimir  *
 *                                                *
 \************************************************/
 # pragma once 
 
 typedef struct StackNode {
	char data;
	struct StackNode *prev;
 } StackNode;
 
 StackNode *snode_init ( char c );
 
 StackNode * snode_del ( StackNode *sn );