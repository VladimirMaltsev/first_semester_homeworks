/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Procedures sort_quick					  *
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

void sort_quick ( Array *arr, int left, int right ) 
{
	int l = left, r = right - 1; 
	int mid = arr_getMedian ( arr, left, right - 1); 
	
	while  (  l <= r  ) 
	{
		while  ( str_cmp  ( arr -> a[l], arr -> a[mid] )  > 0 ) 
			l++; 
		
		while  ( str_cmp  ( arr -> a[r], arr -> a[mid] )  < 0 ) 
			r--; 
		
		if  ( l <= r ) 
			str_swap  ( arr, l++, r-- );  
	}
		
	if  ( l < right  )  
		sort_quick  ( arr, l, right);  
	if  ( r > left ) 
		sort_quick  ( arr, left, r + 1);  
	
}