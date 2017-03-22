/*************************************
 * © Maltsev Vladimir 171 , spbu   *
 * Simple calculator		   * 
 *************************************/
#pragma once
 
typedef struct ListNumber{
	IntNode *first ;
	IntNode *last ;
	int sign ;
} ListNumber ;
 
IntNode *lnum_addfirst ( ListNumber *list , IntNode *node ) ;
IntNode *lnum_addlast ( ListNumber *list , IntNode *node ) ;
ListNumber *lnum_init (  ) ;
ListNumber *lnum_read ( char dig ) ;
 
void lnum_dellast ( ListNumber *num ) ;
void lnum_print ( ListNumber *ln ) ;
ListNumber *lnum_del ( ListNumber *ln ) ;
int lnum_getlen  ( ListNumber *ln ) ;
int lnum_compare ( ListNumber *ln1 , ListNumber *ln2 ) ;
int lnum_getqout ( ListNumber *ln1  , ListNumber *ln2 ) ;
 
ListNumber *int_to_lnum ( int n ) ;
ListNumber *lnum_add_simple ( ListNumber *res , ListNumber *ln2 ) ;
ListNumber *lnum_sub_simple ( ListNumber *res , ListNumber *ln2 ) ;
ListNumber *lnum_mult_simple (  ListNumber *ln1 , ListNumber *ln2 ) ;
ListNumber *lnum_div_simple (  ListNumber *ln1 , ListNumber *ln2 ) ;
ListNumber* lnum_add ( ListNumber *res , ListNumber *sop ) ;
ListNumber* lnum_sub ( ListNumber *res , ListNumber *sop ) ;
ListNumber* lnum_mult ( ListNumber *res , ListNumber *sop ) ;
ListNumber *lnum_mult_int ( ListNumber *ln1  , int n ) ;
ListNumber* lnum_div ( ListNumber *res , ListNumber *sop ) ;
 