 /************************************************\
 * VStack - stack on lists by © Maltsev Vladimir  *
 *                                                *
 \************************************************/
 # pragma once 
 
 typedef struct StackNode {
	ListNumber *data;
	struct StackNode *prev;
 } StackNode ;
 
 StackNode *snode_init ( ListNumber *ln );
 
 StackNode * snode_del ( StackNode *sn );	