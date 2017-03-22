/*************************************
 * © Maltsev Vladimir 171, spbu  *
 * Simple calculator		   * '0' = 48
 *************************************/
 #pragma once
 
 typedef struct IntNode{
	struct IntNode* next ;
	struct IntNode* prev ;
	short value ;
 }IntNode ;
 
 IntNode* node_init ( short value ) ;
 IntNode* node_del ( IntNode* num ) ;