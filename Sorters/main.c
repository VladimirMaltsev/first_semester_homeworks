/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Basics of programming`s homework 		  *
 *  The most famouse sorters				  *
 *  main procedure 							  *
 **********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "Array.h"
#include "SortingTools.h"
#include "QuickSort.h"
#include "MergeSort.h"




int main  (  int argc, char **argv  ) 
{	
	
	char * fname = argv[2] ; 
	int count = atoi  ( argv[1] ) ;  
	//printf ("%s %d" , fname, count );
	FILE *inStream = fopen ( fname, "r" ) ;  
	Array arr = arr_read ( count, inStream ) ;  

	Array insArr = arr_copy ( arr, count ) ;  
	Array qckArr = arr_copy ( arr, count ) ;  
	Array mrgArr = arr_copy ( arr, count ) ;  
	Array bubArr = arr_copy ( arr, count ) ;  

	sort_quick ( &qckArr, 0, qckArr.size ) ;  
	sort_merge ( &mrgArr, 0, mrgArr.size ) ;  
	sort_insert ( &insArr ) ;  
	sort_bubble ( &bubArr ) ;  
	
	arr_print  ( &mrgArr ) ;  
	arr_clean ( &bubArr ) ;  
	arr_clean ( &insArr ) ;  
	arr_clean ( &qckArr ) ;  
	arr_clean ( &mrgArr ) ;  
	arr_clean ( &arr ) ;  
	
	fclose ( inStream ) ;  
	return 0 ; 
}
