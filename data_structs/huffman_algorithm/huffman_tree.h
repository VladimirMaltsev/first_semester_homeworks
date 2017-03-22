#pragma once

typedef struct huffman_tree{
	tree_node *root;	
}huffman_tree;

huffman_tree *htree_init();

void htree_print( tree_node *curr);