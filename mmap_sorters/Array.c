 /********************************************\
 *  © Maltsev Vladimir |Student Pi171| SPbGU  *
 *  Procedures for reading words from files   *
 \********************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "Array.h"
#include "SortingTools.h"
#include "QuickSort.h"
#include "MergeSort.h"


Array *arr_init ( ){
	Array *arr = ( Array * ) malloc ( sizeof ( Array ) );
	return arr;
}

void arr_del ( Array * arr )
{
	free ( arr -> a );
	free ( arr );
}

Array *arr_read  ( int n, FILE * outStream )  
{	
	Array *arr = arr_init ();
	/*char *buffer = NULL; 
	
	int f_descriptor = open ( in , O_RDWR );
	if ( f_descriptor == -1 ) {
		fprintf (stderr, "programm mmap_sorters can not get f_descriptor of file <%s>\n"	, in );
		return NULL;
	}
	
	struct stat statist;
	fstat (f_descriptor, &statist );
	if ( f_descriptor == -1) {
		fprintf (stderr, "programm mmap_sorters can not get statistic in fstat()\n");
		return NULL;
	}
	
	if ( (buffer = ( char * ) mmap ( 0 , statist.st_size + 1, PROT_READ | PROT_WRITE , MAP_SHARED, f_descriptor , 0 ) == MAP_FAILED ){
		fprintf (stderr, "mmap() error for %s()\n" , in );
		return NULL;
	}
	buffer[*/
	return arr;
	
}

void arr_clean ( Array *arr ) 
{
	free  ( arr -> a );  
}

void arr_print ( Array *arr ) 
{
	for  ( int i = 0;  i < arr -> size;  i ++ ) 
	{
		int j = 0;
		do{
			printf  ( "%c", arr -> a[i][j] );   		
		}while ( arr -> a[i][j ++]  != '\n' );
		
	}
}

Array *arr_copy  ( Array *arr ) 
{  
	Array *arr_dupl = arr_init ();
	arr_dupl -> size = arr -> size;
	
	arr_dupl -> a = ( char ** ) malloc ( sizeof ( char * ) * arr_dupl -> size );
	int i = 0;
	for ( ; i < arr -> size ; i ++ )
	{
		arr_dupl -> a [i] = arr -> a [i] ;
	}
	return arr_dupl ;
}

int arr_getMedian ( Array *arr, int left, int right ) 
{
	if  ( str_cmp ( arr -> a[left +  ( right - left )  / 2], arr -> a[left] )  < 0 && str_cmp ( arr -> a[right], arr -> a[left] )  < 0 ) 
	{
		if  ( str_cmp ( arr -> a[left +  ( right - left )  / 2], arr -> a[right] )  > 0 ) 
			return left +  ( right - left )  / 2; 
		else
			return right; 
	}else
	{
		if  ( str_cmp ( arr -> a[left +  ( right - left )  / 2], arr -> a[left] )  > 0 && str_cmp ( arr -> a[right], arr -> a[left] )  > 0 ) 
		{
			if  ( str_cmp ( arr -> a[left +  ( right - left )  / 2], arr -> a[right] )  < 0 ) 
				return left +  ( right - left )  / 2; 
			else
				return right; 
		}else
			return left; 
	}
}
