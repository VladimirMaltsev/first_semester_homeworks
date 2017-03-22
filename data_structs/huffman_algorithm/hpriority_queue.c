#include <stdio.h>
#include <malloc.h>

#include "tree_node.h"
#include "hnode.h"
#include "hpriority_queue.h"
#include "huffman_tree.h"


hp_queue *hp_queue_init()
{
	hp_queue *mint = (hp_queue *) malloc ( sizeof (hp_queue));
	mint -> first = 0;
	mint -> last = 0;
	return mint;
}

void hp_queue_push (hp_queue *queue, tree_node *data)
{
	hnode *mint = hnode_init (data);
	if (queue -> first == 0)
	{
		queue -> first = mint;
		queue -> last = mint;
		return;
	}
	hnode *curr = queue -> first;
	hnode *prev = 0;
	
	while (curr && curr -> data -> frequency <= mint -> data -> frequency ){
		prev = curr;
		curr = curr -> next;
	}
	puts("minoval");
	if (!curr) {
		queue -> last -> next = mint;
		queue -> last = queue -> last -> next;
		return;
	}
	mint -> next = curr;
	if (prev)
	{
		prev -> next = mint;
	}else
		queue -> first = mint;
}

hnode *hp_queue_pick (hp_queue *queue)
{
	return queue -> first;
}

tree_node *hp_queue_pop (hp_queue *queue)
{
	puts("beging pop");
	if ( !queue -> first)
		return 0;
	tree_node *ret = queue -> first -> data;
	hnode *victim = queue -> first;
	queue -> first = queue -> first -> next;
	hnode_remove ( victim );
	puts("end pop");
	return ret;
}