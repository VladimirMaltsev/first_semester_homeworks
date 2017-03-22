#include <stdio.h>
#include <malloc.h>

#include "tree_node.h"
#include "hnode.h"
#include "hpriority_queue.h"
#include "huffman_tree.h"


huffman_tree *htree_init()
{
	huffman_tree *tree = (huffman_tree *) malloc (sizeof (huffman_tree));
	tree -> root = 0;
	return tree;
}

void htree_print( tree_node *curr)
{
	if ( !curr -> child_left && !curr -> child_right )
	{
		printf ("%c - %d", curr -> symbol, curr -> frequency );
		puts("");
		return;
	}
	if (curr -> child_left)
		htree_print (curr -> child_left);
	if (curr -> child_right)
		htree_print (curr -> child_right);
}