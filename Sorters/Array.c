/**********************************************
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Procedures for reading words from files   *
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

Array arr_read  ( int n, FILE *in ) 
{	
	char c ; 
	char **mas =  (  char**  )  malloc (  n * sizeof ( char * )  ) ;  
	int i = -1 ; 
	while  ( 1 ) 
	{
		i++ ; 
		n-- ; 
		int len = 0 ; 
		
		fpos_t pos ; 
		if  ( fgetpos ( in, &pos )  ) 
		{
			fprintf ( stderr, "%s", "Could not get position" ) ;  
			break ; 
		}
		//first reading take count of chars in line	
		while  (  ( c = fgetc ( in )  )  != '\n' && c >= 0 ) 
		{
			len ++ ; 
		}
		len++ ;  //for symbol '\0'
		* ( mas + i )  =  ( char*  )  malloc  ( len * sizeof  (  char  )  ) ;   
		int j = 0 ; 
		for  (  ;  j < len ;  j ++ ) 
			mas[i][j] = '\0' ; 
	
		fsetpos ( in, &pos ) ;  
		j = 0 ; 
		while  (  ( c = fgetc ( in )  )  != '\n' && c >= 0 ) 
		{
			 ( * ( mas + i )  ) [j ++] = c ; 
		}
	
		if  ( c <= 0 || n <= 0 ) 
			break ; 
	}
	mas = realloc ( mas,  ( i + 1 )  * sizeof ( char * )  ) ;  
	const Array arr = {.a = mas, .size = i + 1} ; 
	return arr ; 
}

void arr_clean ( Array *arr ) {
	for  ( int i = 0 ;  i < arr -> size ;  i ++ ) 
	{
		free ( * ( arr -> a + i )  ) ;  
	}
	free  ( arr -> a ) ;  
}

void arr_print ( Array *arr ) 
{
	for  ( int i = 0 ;  i < arr -> size ;  i ++ ) 
	{
		printf  ( "%s\n", arr -> a[i] ) ;   
	}
}

Array arr_copy  ( Array arr, int size ) 
{  
	int length = arr.size ; 
	if  ( size < length ) 
		length = size ; 
	
	char **mas =  (  char**  )  malloc (  length * sizeof ( char * )  ) ;  
	Array narr = {.a = mas, .size = length} ; 
	for  ( int i = 0 ;  i < length ;  i ++ ) 
	{
		int count = 0 ; 
		while  ( arr.a[i][count] != '\0' ) 
			count ++ ; 
		
		narr.a[i] =  ( char*  )  malloc  (  ( count + 1 )  * sizeof  (  char  )  ) ;  
		narr.a[i][count] = '\0' ; 
		int j = 0 ; 
		while  ( (narr.a[i][j] = arr.a[i][j++]) != '\0' ) ;  
	}
	return narr ; 
}
