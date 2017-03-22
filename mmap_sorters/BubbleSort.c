/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Procedures sort_bubble					  *
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

Array* sort_bubble ( Array* arr ) 
{
	for  ( int i = 0;  i < arr -> size;  i ++ ) 
	{
		for  ( int j = arr -> size - 1;  j > i;  j -- ) 
		{ 
			//printf  ( "before: %s %s\n", arr.a[j - 1], arr.a[j] );  
			int check = 0; 
			if  (  ( check = str_cmp  ( arr -> a[j - 1], arr -> a[j] )  )  < 0 ) 
			{
				str_swap ( arr, j - 1, j );  
			}
			//printf  ( "after : %s %s because check = %d\n", arr.a[j - 1], arr.a[j], check );  
		}
	}
	
	return arr; 
}
