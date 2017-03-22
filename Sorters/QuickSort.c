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

int getMedian ( Array *arr, int left, int right ) 
{
	if  ( cmpStr ( arr -> a[left +  ( right - left )  / 2], arr -> a[left] )  < 0 && cmpStr ( arr -> a[right], arr -> a[left] )  < 0 ) 
	{
		if  ( cmpStr ( arr -> a[left +  ( right - left )  / 2], arr -> a[right] )  > 0 ) 
			return left +  ( right - left )  / 2 ; 
		else
			return right ; 
	}else
	{
		if  ( cmpStr ( arr -> a[left +  ( right - left )  / 2], arr -> a[left] )  > 0 && cmpStr ( arr -> a[right], arr -> a[left] )  > 0 ) 
		{
			if  ( cmpStr ( arr -> a[left +  ( right - left )  / 2], arr -> a[right] )  < 0 ) 
				return left +  ( right - left )  / 2 ; 
			else
				return right ; 
		}else
			return left ; 
	}
}

void sort_quick ( Array *arr, int left, int right ) 
{
	int l = left, r = right - 1; 
	int mid = getMedian ( arr, left, right - 1) ; 
	
	while  (  l <= r  ) 
	{
		while  ( cmpStr  ( arr -> a[l], arr -> a[mid] )  > 0 ) 
			l++ ; 
		
		while  ( cmpStr  ( arr -> a[r], arr -> a[mid] )  < 0 ) 
			r-- ; 
		
		if  ( l <= r ) 
			swap  ( arr, l++, r-- ) ;  
	}
		
	if  ( l < right  )  
		sort_quick  ( arr, l, right ) ;  
	if  ( r > left ) 
		sort_quick  ( arr, left, r + 1) ;  
	
}