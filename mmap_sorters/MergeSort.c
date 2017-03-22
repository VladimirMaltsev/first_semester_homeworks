/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Procedures sort_merge					  *
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

Array* merge ( Array *arr, int l, int r, int mid ) 
{
	if  ( l >= r || mid < l || mid > r ) 
		return arr; 
	
	if  ( r - l == 1 && str_cmp ( arr -> a[l], arr -> a[r] )  < 0 ) 
	{
		str_swap ( arr, l, r );  
		return arr; 
	}
	
	int len = r - l + 1; 
	Array tmp = {.a =  ( char** )  malloc  ( len * sizeof ( char* )  )  , .size = len}; 
	for  ( int i = 0;  i < tmp.size;  i ++ ) 
	{
		tmp.a[i] = arr -> a[l + i]; 
	}
	
	int k = mid - l + 1; 
	int d = 0; 
	int i = 0; 
	while  ( d <= mid - l && k <= r - l ) 
		arr -> a[l +  ( i++ ) ] =  ( str_cmp ( tmp.a[d], tmp.a[k] )  > 0  )  ? tmp.a[d++] : tmp.a[k++]; 
	
	if  ( d > mid - l ) 
		while  ( k <= r - l ) 
			arr -> a[l +  ( i++ ) ] = tmp.a[k++]; 
		
	else
		while  ( d <= mid - l ) 
			arr -> a[l +  ( i++ ) ] = tmp.a[d++]; 
	free ( tmp.a );  
	return arr; 
}

Array* sort_merge ( Array *arr, int left, int right ) 
{
	right --;
	if  ( left >= right ) 
	{
		return arr; 
	}
	
	int middle = left +  ( right - left )  / 2; 
	
	sort_merge  ( arr, left, middle + 1);  
	sort_merge  ( arr, middle + 1, right + 1);  
	//return '\0'; 
	return merge ( arr, left, right, middle );  
}