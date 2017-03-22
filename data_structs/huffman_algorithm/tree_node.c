#include <stdio.h>
#include <malloc.h>

#include "tree_node.h"
#include "hnode.h"
#include "hpriority_queue.h"
#include "huffman_tree.h"

tree_node *tree_node_init(char symbol, int frequency)
{
	tree_node *mint = (tree_node *) malloc (sizeof (tree_node));
	mint -> parent = 0;
	mint -> child_left = 0;
	mint -> child_right = 0;
	mint -> symbol = symbol;
	mint -> frequency = frequency;
	return mint;
}

tree_node *tree_node_remove (tree_node *victim)
{
	free (victim -> parent);
	free (victim -> child_left);
	free (victim -> child_right);
	victim = 0;
	return victim;
}