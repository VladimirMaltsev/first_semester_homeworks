 /*********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *********************************************/
#pragma once 


typedef struct Array
{
	char ** a; 
	int size; 
} Array; 

Array *arr_read  ( int n, FILE * outStream );

Array *arr_init ( );

void arr_del ( Array * arr );

void arr_clean ( Array *arr );  

void arr_print ( Array *arr );  

Array *arr_copy ( Array *arr ); 

int arr_getMedian ( Array *arr, int left, int right );  
