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

void str_swap  ( Array *str_arr, int j, int i ) 
{
	char *tmp = str_arr -> a[j]; 
	str_arr -> a[j] = str_arr -> a[i]; 
	str_arr -> a[i] = tmp; 
}

int int_max (int n1 , int n2 )
{
	if ( n1 > n2 )
		return n1;
	return n2;
}

int str_cmp(char *s1, char *s2)
{
	
	int n;
	
	while ((n = *s2 - *s1) == 0)
	{
		if (*s1 == '\n')
			if (*s2 == '\n')
				return 0;
			else 
				return 1;
		if (*s2 == '\n')
			return -1;
		s1++;
		s2++;
	}
	return n;
}

void sort ( Array *str_arr )
{
	int key = 0;
	puts ("Select sorting :") ;
	puts ("   0 - all sorts \n   1 - quick sort \n   2 - merge sort \n   3 - insertion sort \n   4 - bubble sort " );
	scanf ( "%d" , &key );
	
	Array *arr_insert;  
	Array *arr_quick;  
	Array *arr_merge; 
	switch ( key )
	{
		case 0: 
			arr_insert = arr_copy ( str_arr );  
			arr_quick = arr_copy ( str_arr );  
			arr_merge = arr_copy ( str_arr ); 
			
			sort_quick ( arr_quick, 0, arr_quick -> size );  
			sort_merge ( arr_merge, 0, arr_merge -> size );  
			sort_insert ( arr_insert );  
			sort_bubble ( str_arr ); 
			
			arr_clean ( arr_merge );  
			arr_clean ( arr_insert );  
			arr_clean ( arr_quick  ); 
			break;
			
		case 1:
			sort_quick ( str_arr , 0 , str_arr -> size );
			break;
			
		case 2:
			sort_merge ( str_arr , 0 , str_arr -> size );
			break;
		
		case 3 :
			sort_insert ( str_arr );
			break;
			
		case 4 :
			sort_bubble ( str_arr );
			break;
			
		default :
			puts ( ">Wrong input<\n Try again :" );
			sort ( str_arr ) ;
			break;
	}
}
	
