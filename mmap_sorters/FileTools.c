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

int file_get_descriptor ( char * f_name ) 
{
	int f_descriptor = open ( f_name , O_RDWR );
	
	if ( f_descriptor == -1 ) {
		fprintf (stderr, "programm mmap_sorters can not get f_descriptor of file <%s>\n"	, f_name );
		exit( 1 );
	}
	return f_descriptor;
}

struct stat * file_get_statistic ( int f_descriptor )
{
	struct stat *f_stat = ( struct stat * ) malloc ( sizeof ( struct stat ) );
	fstat (f_descriptor, f_stat );
	if ( f_descriptor == -1) {
		fprintf (stderr, "programm mmap_sorters can not get statistic in fstat()\n");
		exit( 1 );
	}
	
	if ( f_stat -> st_size == 0 ) {
		fprintf (stderr, "input file is empty\n");
		exit( 1 );
	}
	return f_stat;
}

char * file_display_vmem ( int f_descriptor , struct stat *stat ) 
{
	char * f_buffer;
	if ( (f_buffer = ( char * ) mmap ( 0 , stat -> st_size + 1, PROT_READ | PROT_WRITE , MAP_PRIVATE, f_descriptor , 0 ) ) == MAP_FAILED ){
		fprintf (stderr, "mmap() error, could not display the file in virtual memory\n");
		exit( 1 );
	}
	f_buffer[ stat -> st_size ] = '\n';
	return f_buffer;
}

void file_parse_to_array ( char * f_buffer , struct stat *f_stat , Array * arr )
{
	int str_index = 0;
	arr -> a [ str_index ++ ] = f_buffer;
	int i = 0; 
	for (; i < f_stat -> st_size; i ++ )
	{
		if (str_index == arr -> size )
			break;
		if ( f_buffer [ i ] == '\n' )
		{
			arr -> a [ str_index ++ ] = f_buffer + i + 1;
		}
	}
	arr -> size = str_index;
	puts ("" );
}


