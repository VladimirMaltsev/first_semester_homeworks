/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 **********************************************/
#pragma once 


typedef struct Array
{
	char ** a ; 
	int size ; 
} Array ; 

Array arr_read  ( int n, FILE * outStream ) ;  

void arr_clean ( Array *arr ) ;  

void arr_print ( Array *arr ) ;  

Array arr_copy ( Array arr, int n ) ;  
