#pragma once

typedef struct hnode {
	struct hnode *next;
	tree_node *data;
} hnode;

hnode *hnode_init (tree_node *data);

hnode *hnode_remove (hnode *victim);