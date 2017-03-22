 /************************************************\
 * VStack - stack on lists by © Maltsev Vladimir  *
 *                                                *
 \************************************************/
# pragma once
 
 typedef struct VStack
 {
	StackNode *top ;
 } VStack;
 
 VStack *vs_init ( ) ;
 
 VStack *vs_del ( VStack *vs ) ;
 
 void vs_push ( VStack *vs , ListNumber *ln ) ;
 
 ListNumber *vs_pick ( VStack *vs ) ;
 
 ListNumber *vs_pop (VStack *vs ) ;
 