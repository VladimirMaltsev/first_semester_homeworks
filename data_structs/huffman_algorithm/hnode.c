#include <stdio.h>
#include <malloc.h>

#include "tree_node.h"
#include "hnode.h"
#include "hpriority_queue.h"
#include "huffman_tree.h"


hnode *hnode_init (tree_node *data)
{
		hnode *mint = (hnode *) malloc (sizeof (hnode));
		mint -> next = 0;
		mint -> data = data;
		return mint;
}

hnode *hnode_remove (hnode *victim)
{
	//tree_node_remove(victim -> data);
	free (victim);
	victim = 0;
	return victim;
}