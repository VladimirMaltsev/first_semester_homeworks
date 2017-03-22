 /***********************************\
 * © Maltsev Vladimir 171 , spbu     *
 * Simple calculator		 		 * 
 \***********************************/
#include <stdio.h>
#include <malloc.h>

#include "IntNode.h"
#include "ListNumber.h"
#include "StackNode.h"
#include "VStack.h"
 
 IntNode *lnum_addfirst ( ListNumber *list , IntNode *node ) 
 {
	if ( !list -> first ) 
	{
		list -> first = node ;
		list -> last = list -> first ;
		return list -> first ;
	}
	list -> first -> prev = node ;
	list -> first -> prev -> next = list -> first ;
	list -> first = list -> first -> prev ;
	return list -> first ;
 }
 
 IntNode *lnum_addlast ( ListNumber *list , IntNode *node ) 
 {
	if ( !list -> last ) 
	{
		list -> first = node ;
		list -> last = list -> first ;
		return list -> last ;
	}
	list -> last -> next = node ;
	list -> last -> next -> prev = list -> last ;
	list -> last = list -> last -> next ;
	return list -> last ;
 }
 
 ListNumber *lnum_init ( ) 
 {
	 ListNumber *nl = ( ListNumber * ) malloc ( sizeof ( ListNumber ) ) ;
	 nl -> first = 0 ;
	 nl -> last = 0 ;
	 nl -> sign = 0 ;
	 return nl ;
 }
 
ListNumber *lnum_del ( ListNumber *ln ) 
 {
	IntNode *curr = ln -> first ;
	while ( curr ) 
	{
		if ( curr -> next ) 
		{
			curr = curr -> next ;
			curr -> prev = node_del ( curr -> prev ) ;
		} else
			curr = node_del ( curr ) ;
	}
	free ( ln ) ;
	ln = 0 ;
	
	return ln ;
 }
 
 ListNumber *lnum_read ( char dig ) 
 {
	ListNumber *ln = lnum_init ( ) ;

	while ( dig >= '0' && dig <= '9' ) {
		IntNode *node = node_init ( dig - 48 ) ;
		lnum_addfirst ( ln , node ) ;
		dig = fgetc ( stdin ) ;
	}
	if ( lnum_getlen ( ln ) == 1 && ln -> first -> value == 0 ) 
	ln -> sign = 0 ;
	return ln ;
 }
 
 void lnum_dellast ( ListNumber *num ) 
 {
	if ( num -> last ) 
	{
		if ( num -> last -> prev ) 
			num -> last = num -> last -> prev ;
		if ( num -> last -> next ) 
			num -> last -> next = node_del ( num -> last -> next ) ;
	}
 }
 void lnum_print ( ListNumber *ln ) 
 {
	if ( ln -> sign ) 
		printf ( "-" ) ;
	IntNode *current = ln -> last ;
	do{
		printf ( "%d" , current -> value ) ;
		current = current -> prev ;
	}while ( current != 0 ) ;
	puts ( "" ) ;
 }
 
 int lnum_getlen ( ListNumber *ln ) 
 {
	int len = 0 ;
	IntNode *ln_curr = ln -> last ;
	while ( ln_curr ) 
	{
		len++ ;
		ln_curr = ln_curr -> prev ;
	}
	
	return len ;
 }
 
 int lnum_compare ( ListNumber *ln1 , ListNumber *ln2 ) 
 {	
	int delta = lnum_getlen ( ln1 ) - lnum_getlen ( ln2 ) ;
	if ( delta ) 
		return delta ;
	
	delta = 0 ;
	IntNode *ln1_curr = ln1 -> last ;
	IntNode *ln2_curr = ln2 -> last ;
	while ( ln1_curr && ln2_curr ) 
	{
		if ( ( ln1_curr -> value - ln2_curr -> value ) && !delta ) 
		{
			delta = ln1_curr -> value - ln2_curr -> value ;
			return delta ;
		}
		
		ln1_curr = ln1_curr -> prev ;
		ln2_curr = ln2_curr -> prev ;
	}
	
	
	return delta ;
 }
 
 ListNumber *int_to_lnum ( int n ) 
 {
	ListNumber *ln = lnum_init ( ) ;
	lnum_addlast ( ln , node_init ( n % 10 ) ) ;
	n /= 10 ;
	while ( n > 0 ) 
	{
		lnum_addlast ( ln , node_init ( n % 10 ) ) ;
		n /= 10 ;
	}
	return ln ;
 }
 ListNumber *lnum_add_simple ( ListNumber *res , ListNumber *ln2 ) 
 {
	IntNode *ln2_curr = ln2 -> first ;
	IntNode *res_curr = res -> first ;
	
	while ( res_curr && ln2_curr ) 
	{
		if ( ( res_curr -> value + ln2_curr -> value ) / 10 ) 
		{
			if ( !res_curr -> next ) 
				lnum_addlast ( res , node_init ( 0 ) ) ;
			res_curr -> next -> value += 1 ;
		}
		res_curr -> value = ( res_curr -> value + ln2_curr -> value ) % 10 ;
		ln2_curr = ln2_curr -> next ;
		res_curr = res_curr -> next ;
	}
	while ( ln2_curr ) 
	{
		if ( !res_curr ) 
			res_curr = lnum_addlast ( res , node_init ( 0 ) ) ;
		res_curr -> value = ln2_curr -> value ;
		ln2_curr = ln2_curr -> next ;
		res_curr = res_curr -> next ;
	}
	return res ;
 }
 
 //first number is bigger then second one
 ListNumber *lnum_sub_simple ( ListNumber *res , ListNumber *ln2 ) 
 {
	IntNode *ln2_curr = ln2 -> first ;
	IntNode *res_curr = res -> first ;
	
	while ( ln2_curr ) 
	{
		res_curr -> value -= ln2_curr -> value ;
		while ( res_curr -> value < 0 ) 
		{
			res_curr -> value += 10 ;
			res_curr -> next -> value -= 1 ;
		}
		ln2_curr = ln2_curr -> next ;
		res_curr = res_curr -> next ;
	}
	while ( res_curr -> value < 0 )
	{
		res_curr -> value += 10 ;
		res_curr -> next -> value -= 1 ;
		res_curr = res_curr -> next ;
	}
	res_curr = res -> last ;
	while ( !res_curr -> value && res -> first != res -> last ) 
	{
		res_curr = res_curr -> prev ;
		lnum_dellast ( res ) ;
	}
	return res ;
 }
 ListNumber *lnum_mult_simple ( ListNumber *ln1 , ListNumber *ln2 ) 
 {
	ListNumber *res = lnum_init ( ) ;
	
	IntNode *ln2_curr = ln2 -> first ;
	IntNode *res_curr = res -> first ;
	
	while ( ln2_curr ) 
	{
		if ( !res_curr ) 
			res_curr = lnum_addlast ( res , node_init ( 0 ) ) ;
		
		IntNode *curr_st = res_curr ;
		IntNode *ln1_curr = ln1 -> first ;
		
		while ( ln1_curr ) 
		{
			int dig = ln2_curr -> value * ln1_curr -> value ;
		
			if ( !curr_st ) 
				curr_st = lnum_addlast ( res , node_init ( 0 ) ) ;
				
			curr_st -> value += dig ;
				
			
				
			if ( curr_st -> value / 10 ) 
			{
				if ( !curr_st -> next ) 
					curr_st -> next = lnum_addlast ( res , node_init ( 0 ) ) ;
				curr_st -> next -> value += curr_st -> value / 10 ;
			}
			
			curr_st -> value %= 10 ;			
			ln1_curr = ln1_curr -> next ;
			curr_st = curr_st -> next ;
			
		}
		res_curr = res_curr -> next ;
		ln2_curr = ln2_curr -> next ;
	}
	
	if ( res -> last -> value > 9 ) 
	{
		lnum_addlast ( res , node_init ( res -> last -> value / 10 ) ) ;
		res -> last -> prev -> value %= 10 ;
	}
	
	res_curr = res -> last ;
	while ( !res_curr -> value && res -> first != res -> last ) 
	{
		res_curr = res_curr -> prev ;
		lnum_dellast ( res ) ;
	}
	//lnum_del ( ln1 ) ;
	//lnum_del ( ln2 ) ;
	return res ;
 }
	
 ListNumber *lnum_mult_int ( ListNumber *ln1 , int n ) 
 {
	ListNumber *ln2 = int_to_lnum ( n ) ;
	ListNumber *res = lnum_mult_simple ( ln1 , ln2 ) ;
	ln2 = lnum_del ( ln2 ) ;
	return res ;
 }

int lnum_getqout ( ListNumber *ln1 , ListNumber *ln2 ) 
{
	int qout = 0 ;
	for ( ; qout < 10 ; qout ++ ) 
	{
		if ( ( lnum_compare ( lnum_mult_int ( ln2 , qout ) , ln1 ) <= 0 ) && ( lnum_compare ( lnum_mult_int ( ln2 , qout + 1 ) , ln1 ) > 0 ) ) 
			return qout ;
	}	
	return 1 ;
}

 ListNumber *lnum_div_simple ( ListNumber *ln1 , ListNumber *ln2 ) 
 {
	ListNumber *res = lnum_init ( ) ;
	if ( lnum_compare ( ln1 , ln2 ) < 0 ) 
	{
		lnum_addlast ( res , node_init ( 0 ) ) ;
		return res ;
	}
	
	ListNumber *subRes = lnum_init ( ) ;
	lnum_addfirst ( subRes , node_init ( ln1 -> last -> value ) ) ;
	
	IntNode *ln1_curr = ln1 -> last ;
	
	while ( lnum_compare ( subRes , ln2 ) < 0 ) 
	{
		ln1_curr = ln1_curr -> prev ;
		lnum_addfirst ( subRes , node_init ( ln1_curr -> value ) ) ;
	}
	do	{
		int qout = lnum_getqout ( subRes , ln2 ) ;
		//lnum_print ( subRes ) ;
		lnum_addfirst ( res , node_init ( qout ) ) ;
		
		subRes = lnum_sub_simple ( subRes , lnum_mult_int ( ln2 , qout ) ) ;
		ln1_curr = ln1_curr -> prev ;
		if ( ln1_curr ) 
		{
			lnum_addfirst ( subRes , node_init ( ln1_curr -> value ) ) ;
			
		}
	} while ( ln1_curr ) ;

	subRes = lnum_del ( subRes ) ;
	return res ;
 }
 
 
 ListNumber* lnum_add ( ListNumber *res , ListNumber *sop ) 
{
	ListNumber *ans ;
	int negSh = res -> sign + sop -> sign * 2 ;
	switch ( negSh ) 
	{
		case 0:
			ans = lnum_add_simple ( res , sop ) ;
			sop = lnum_del ( sop ) ;
			break ;
		case 3:
			ans = lnum_add_simple ( res , sop ) ;
			sop = lnum_del ( sop ) ;
			ans -> sign = 1 ;
			break ;
		case 1:
						
			if ( lnum_compare ( res , sop ) > 0 ) 
			{
				ans = lnum_sub_simple ( res , sop ) ;
				sop = lnum_del ( sop ) ;
				ans -> sign = 1 ;
			}else
			{
				ans = lnum_sub_simple ( sop , res ) ;
				res = lnum_del ( res ) ;
				ans -> sign = 0 ;
			}
			break ;
					
		case 2:
			if ( lnum_compare ( res , sop ) > 0 ) 
			{
				ans = lnum_sub_simple ( res , sop ) ;
				sop = lnum_del ( sop ) ;
				ans -> sign = 0 ;
			}else
			{
				ans = lnum_sub_simple ( sop , res ) ;
				res = lnum_del ( res ) ;
				ans -> sign = 1 ;
			}
			break ;
						
		default:
			puts ( "you have a problem" ) ;
			break ;					
	}
	if ( lnum_getlen ( ans ) == 1 && ans -> first -> value == 0 ) 
	ans -> sign = 0 ;
	return ans ;
}

ListNumber* lnum_sub ( ListNumber *res , ListNumber *sop ) 
{
	ListNumber *ans ;
	int negSh = res -> sign + sop -> sign * 2 ;
	switch ( negSh ) 
	{
		case 0:
			if ( lnum_compare ( res , sop ) > 0 ) 
			{
				ans = lnum_sub_simple ( res , sop ) ;
				sop = lnum_del ( sop ) ;
				ans -> sign = 0 ;
			}else
			{
				ans = lnum_sub_simple ( sop , res ) ;
				res = lnum_del ( res ) ;
				ans -> sign = 1 ;
				lnum_print (ans);
			}
			break ;
			
		case 3:
			if ( lnum_compare ( res , sop ) > 0 ) 
			{
				ans = lnum_sub_simple ( res , sop ) ;
				sop = lnum_del ( sop ) ;
				ans -> sign = 1 ;
			}else
			{
				ans = lnum_sub_simple ( sop , res ) ;
				res = lnum_del ( res ) ;
				ans -> sign = 0 ;
			}
			break ;
		case 1:
						
			ans = lnum_add_simple ( res , sop ) ;
			sop = lnum_del ( sop ) ;
			ans -> sign = 1 ;
			break ;
					
		case 2:
			ans = lnum_add_simple ( res , sop ) ;
			sop = lnum_del ( sop ) ;
			ans -> sign = 0 ;
			break ;
						
		default:
			puts ( "you have a problem" ) ;
			break ;					
	}
	if ( lnum_getlen ( ans ) == 1 && ans -> first -> value == 0 ) 
	ans -> sign = 0 ;
	return ans ;
}

ListNumber* lnum_mult ( ListNumber *res , ListNumber *sop ) 
{
	ListNumber *ans ;
	int negRes = ( res -> sign + sop -> sign ) % 2 ;
	
	if ( !negRes ) 
	{
		ans = lnum_mult_simple ( res , sop ) ;
		ans -> sign = 0 ;
		res = lnum_del ( res ) ;
		sop = lnum_del ( sop ) ;
		return ans ;
	}
	else
	{
		ans = lnum_mult_simple ( res , sop ) ;
		ans -> sign = 1 ;
		res = lnum_del ( res ) ;
		sop = lnum_del ( sop ) ;
		return ans ;
	}
	if ( lnum_getlen ( ans ) == 1 && ans -> first -> value == 0 ) 
	ans -> sign = 0 ;
}

ListNumber* lnum_div ( ListNumber *res , ListNumber *sop ) 
{
	ListNumber *ans ;
	if ( lnum_getlen ( sop ) == 1 && sop -> first -> value == 0 ) 
	{
		puts ( "Division by zero!" ) ;
		return 0 ;
	}
	int negRes = ( res -> sign + sop -> sign ) % 2 ;
	
	if ( !negRes ) 
	{
		ans = lnum_div_simple ( res , sop ) ;
		ans -> sign = 0 ;
		res = lnum_del ( res ) ;
		sop = lnum_del ( sop ) ;
		return ans ;
	}
	else
	{
		ans = lnum_div_simple ( res , sop ) ;
		ans -> sign = 1 ;
		res = lnum_del ( res ) ;
		sop = lnum_del ( sop ) ;
		return ans ;
	}
	if ( lnum_getlen ( ans ) == 1 && ans -> first -> value == 0 ) 
	ans -> sign = 0 ;
}
 