#pragma once

typedef struct hp_queue{
	hnode *first;
	hnode *last ;
}hp_queue;

hp_queue *hp_queue_init();

void hp_queue_push (hp_queue *queue, tree_node *data);

hnode *hp_queue_pick (hp_queue *queue);

tree_node *hp_queue_pop (hp_queue *queue);