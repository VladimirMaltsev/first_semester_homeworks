#pragma once

typedef struct tree_node {
	struct tree_node *parent;
	struct tree_node *child_left;
	struct tree_node *child_right;
	char symbol;
	int frequency;	
} tree_node;

tree_node *tree_node_init(char symbol, int frequency);
tree_node *tree_node_remove (tree_node *victim);