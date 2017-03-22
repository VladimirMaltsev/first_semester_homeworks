 /*************************************
 * © Maltsev Vladimir 171, spbu       *
 * Simple calculator		          *
 *************************************/
 
#include <stdio.h>
#include <malloc.h>

#include "IntNode.h"
#include "ListNumber.h"
#include "StackNode.h"
#include "VStack.h"


int main (  ) 
{
	VStack *vs = vs_init ( ) ;
	ListNumber *ln1 = 0 ;
	ListNumber *ln2 = 0 ;
	char curchar = '\0' ;
	int flag = 1 ;
	while  ( flag ) 
	{
		curchar = fgetc ( stdin ) ;
		
		switch  ( curchar ) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				ln1 = lnum_read ( curchar ) ;
				vs_push ( vs , ln1 ) ;
				break ;
				
			case '=':
				if ( vs_pick ( vs ) )
					lnum_print ( vs_pick ( vs ) ) ;
				break ;
			case EOF:
			case 'q':
				vs_del ( vs );
				flag = 0;
				break ;
			
			case ' ' :
			case '\n':
				break;
			
			default:
				if ( curchar == '-' ){
					curchar = fgetc (stdin);
					if (curchar == '\n' || curchar == ' ' )
						curchar = '-';
					else{
						ln1 = lnum_read ( curchar ) ;
						ln1 -> sign = 1;
						vs_push ( vs , ln1 ) ;
						continue;
					}
				}
				ln2 = vs_pop ( vs ) ;
				ln1 = vs_pop ( vs ) ;
				if (!ln1 || !ln2)
				{
					if (ln2)
						vs_push ( vs , ln2 ) ;
					fprintf(stderr, "empty stack\n");
					continue;
				}

				switch  ( curchar ) {
					case '+':				
						vs_push ( vs , lnum_add ( ln1, ln2 ) ) ;
						break ;

					case '-':
							vs_push ( vs , lnum_sub ( ln1, ln2 ) );
						break ;
					case '*':
						vs_push ( vs , lnum_mult ( ln1, ln2 ) ) ;
						break ;
					case '/':
						vs_push ( vs , lnum_div ( ln1, ln2 ) ) ;
						if  ( !vs_pick ( vs ) ) 
							return 1 ;
						break ;
					default:
						vs_push ( vs , ln1 );
						vs_push ( vs , ln2 );
						break ;
				}
				break ;	
		}
		
		
	}
	return 0 ;
}