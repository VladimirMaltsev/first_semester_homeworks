/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Procedures sort_insert				  *
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

void sort_insert ( Array *arr ) 
{
	for  ( int i = 1 ;  i < arr -> size ;  i ++ ) 
	{
		int target_i = i ; 
		char *tmp = arr -> a[i] ; 
		
		while  ( target_i > 0 && cmpStr ( arr -> a[target_i - 1], tmp )  < 0 ) 
		{
			arr -> a[target_i] = arr -> a[target_i - 1] ; 
			target_i -- ; 
		}
		
		arr -> a[target_i] = tmp ; 
	}
}