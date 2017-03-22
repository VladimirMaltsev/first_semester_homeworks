#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

void key_call();

char * str_copy ( char * str , char * copystr )
{
	int i = 0;
	while ( (str [ i ] = copystr [ i ++ ] ) != '\0' ) ;
	return str ;
} 

int str_cmp ( char *s1, char *s2 ) 
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

void key_flat ()
{
	char c = '\0';
	int i = 0;
	char ** str_arr = ( char ** ) malloc ( sizeof ( char * ) * 20 ) ;
	for ( ; i < 20 ; i ++ ){
		str_arr [ i ] = ( char * ) malloc ( sizeof ( char ) * 20 ) ;
	}
	
	while ( (c = fgetc ( stdin )) >= 0 && c != '%'){
		if ( c == '\n' )
			printf("%c" , c ) ;
		printf("%c" , c ) ;
	}
	for ( i = 0 ; i < 11 ; i ++ )
		scanf ("%s" , str_arr [ i ] ) ;
	printf (" %s | %s %s | %s %s | %s | %s %s | %s %s | %s \n" , 
			str_arr [ 4 ] , str_arr [ 0 ] , str_arr [ 5 ] , str_arr [ 1 ] , 
			str_arr [ 6 ] , str_arr [ 7 ] , str_arr [ 2 ] , str_arr [ 8 ] , 
			str_arr [ 3 ]  , str_arr [ 9 ]  , str_arr [ 10 ] ) ;
	
	printf ("------ | ------ | ------ | ------ | ------ | ------ | ------ \n") ;
	char * str_curr = ( char * ) malloc ( sizeof ( char ) * 100 ) ;
	char * str_need = "Call" ;
	int count = 0;
	while ( 1 )
	{
		
		if ( scanf ( "%s" , str_curr ) == -1)
			return;
		if ( !str_cmp ( str_curr , str_need ) )
		{
			puts("");
			break;
		}
		count ++ ;
		if ( str_curr [ 0 ] > '9' || str_curr [ 0 ] < '0' ){
			while ( count != 7 ){
				printf ( " | " ) ;
				count ++ ;
			}
			printf (" %s " , str_curr ) ;
		}
		else
			printf (" %s | " , str_curr ) ;
		
		//scanf ( "%s" , str_curr );
		if ( count == 7 ){
			printf ( "\n" ) ;
			count = 0;
		}
	}
	puts("");
	printf ( "%s" , str_need ) ;
	
	for ( ; i < 20 ; i ++ ){
		free (str_arr [ i ] );
	}
	free ( str_arr ) ;
	key_call ();
	
}

void key_call ()
{
	char * str_curr = ( char * ) malloc ( sizeof ( char ) * 100 ) ;
	do{
		fgets ( str_curr , 100 , stdin ) ;	
		printf ( "%s\n" , str_curr ) ;
	} while ( str_curr [ 0 ] != 'g' ) ;
	puts ( "" );
	char ** str_arr = ( char ** ) malloc ( sizeof ( char * ) * 20 ) ;
	int i = 0; 
	for ( ; i < 20 ; i ++ ){
		str_arr [ i ] = ( char * ) malloc ( sizeof ( char ) * 50 ) ;
	}
	i = 0;
	for ( ; i < 8 ; i++ )
		scanf ("%s" , str_arr [i] );
	printf (" %s | %s %s | %s | %s | %s | %s %s \n" , str_arr [0] , 
			str_arr [1] , str_arr [2] , str_arr [3] , str_arr [4] , 
			str_arr [5] , str_arr [6] , str_arr [7] );
	printf ("------ | ------ | ------ | ------ | ------ | ------ \n") ;
	char * str_need = "Index" ;
	int arr_ind = 0;
	int count = 0;
	int maxr = 300;
	while ( 1)
	{
		if ( scanf ( "%s" , str_curr ) == -1)
			break;
		if ( !str_cmp ( str_curr , str_need ) )
		{
			puts("");
			break;
		}
		//printf ("<<<< %s >>>> \n" , str_curr ) ;
		if ( str_curr [0] != '-' ){
			//printf ("%d \n" , count ) ;
			count ++ ;
			if ( (str_curr [ 0 ] > '9' || str_curr [ 0 ] < '0' ) && str_curr[0] != '['){
				i = 0;
				if ( str_arr [ 0 ][ 0 ] == '[' )
				{
					i++ ;
					printf (" %s | " , str_arr [ 0 ] );
				}
				while ( count != 6 ){
					printf ( " | " ) ;
					count ++ ;
				}
				for ( ; i < arr_ind ; i ++ )
					printf (" %s | " , str_arr [i] ) ;
				printf (" %s " , str_curr ) ;
				scanf ("%s" , str_curr ) ;
				printf (" %s" , str_curr ) ;
			}
			
			else
				 str_copy ( str_arr [ arr_ind ++ ] , str_curr );
		
			if ( count == 6 ){
				printf ( "\n" ) ;
				count = 0;
				arr_ind = 0;
			}
		}
	}
	puts("");
	for ( ; i < 20 ; i ++ ){
		free (str_arr [ i ] );
	}
	free ( str_arr ) ;
}

int main ()
{
	char * key = ( char * ) malloc ( sizeof ( char ) * 20 ) ;
	while ( scanf ( "%s" , key ) != -1	){
		
		switch ( key [0] ){
			case 'F' :
			case 'E' :
				printf("%s " , key );
				key_flat ();
				break;
			case 'C' :
				printf("%s " , key );
				key_call ();
				break;
			default :
				break;
		}
	}
}