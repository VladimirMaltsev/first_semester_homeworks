/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Procedures Tools for sortings			  *
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

void swap  ( Array *arr, int j, int i ) 
{
	char *tmp = arr -> a[j] ; 
	arr -> a[j] = arr -> a[i] ; 
	arr -> a[i] = tmp ; 
	
}

int cmpStr ( char *s1, char *s2 ) 
{
	
	int n ; 
	
	while  (  ( n = *s2 - *s1 )  == 0 ) 
	{ 	
		if  ( *s1 == 0 ) 
			if  ( *s2 == 0 ) 
				return 0 ; 
			else 
				return 1 ; 
		if  ( *s2 == 0 ) 
			return -1 ; 
		s1++ ; 
		s2++ ; 
	}
	return n ; 
}
