 /********************************************\
 *  © Maltsev Vladimir |Student Pi171| SPbU   *
 *  Basics of programming`s homework 	      *
 *  The most famouse sorters		      *
 *  main procedure 			      *
 \********************************************/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
#include <time.h>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "Array.h"
#include "SortingTools.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "FileTools.h"

int main  (  int argc, char **argv  ) 
{	
	int f_descriptor;
	int str_count = atoi  ( argv[1] );
	char *f_name = argv[2]; 
	char *f_buffer = NULL; 
	struct stat *f_stat = 0;
	Array *str_arr = arr_init ( );  
	str_arr -> size = str_count;
	str_arr -> a = ( char ** ) malloc ( sizeof ( char * ) * str_arr -> size );
	
	f_descriptor = file_get_descriptor ( f_name );
	f_stat = file_get_statistic ( f_descriptor );
	f_buffer = file_display_vmem ( f_descriptor, f_stat );
	file_parse_to_array ( f_buffer , f_stat , str_arr ); 
	
	sort ( str_arr );
		
	arr_print  ( str_arr );   
	arr_del ( str_arr );  
	
	free ( f_stat );
	close ( f_descriptor );  
	return 0; 
}
