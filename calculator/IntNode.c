/*************************************
 * © Maltsev Vladimir 171, spbu  *
 * Simple calculator		   * '0' = 48
 *************************************/
#include <stdio.h>
#include <malloc.h>

#include "IntNode.h"
#include "ListNumber.h"
#include "StackNode.h"
#include "VStack.h"
 
 IntNode* node_init ( short value ) 
 {
	 IntNode* node =  ( IntNode* ) malloc ( sizeof ( IntNode )  ) ;
	 node -> value = value ;
	 node -> next = 0 ;
	 node -> prev = 0 ;
	 return node ;
 }
 
 IntNode* node_del ( IntNode *node ) 
 {
	 free ( node ) ;
	 node = 0 ;
	 return node ;
 }