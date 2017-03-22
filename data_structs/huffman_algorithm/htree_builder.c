#include <stdio.h>
#include <malloc.h>

#include "tree_node.h"
#include "hnode.h"
#include "hpriority_queue.h"
#include "huffman_tree.h"


int int_get ()
{
	char c = '\0';
	int res = 0;
	//while ( (c = fgetc (stdin)) < '0' || c > '9');
	while (  (c = fgetc (stdin)) >= '0' && c <= '9')
	{
		res = res * 10 + atoi (&c);
		//c  = fgetc (stdin);
	}
	printf ("%d\n", res);
	puts("");
	return res;
}

void read_data_to_queue(hp_queue *queue)
{
	char c = '\0';
	while ( (c = fgetc (stdin) ) != '\n')
	{
		int freq = int_get ();
		hp_queue_push (queue, tree_node_init (c, freq)); 
	}
}

void build_tree_from_queue (huffman_tree *tree, hp_queue *queue)
{
	tree_node *tn1 = 0;
	tree_node *tn2 = 0;
	while ( (tn1 = hp_queue_pop (queue)) && (tn2 = hp_queue_pop (queue)))
	{
		printf ("tn1 : %c , %d\ntn2 : %c , %d\n", tn1 -> symbol, tn1 -> frequency, tn2 -> symbol, tn2 -> frequency) ;
		tree_node *curr = tree_node_init ('s', tn1 -> frequency + tn2 -> frequency);
		curr -> child_left = tn1;
		curr -> child_right = tn2;
		printf ("current : %c , %d", curr -> symbol, curr -> frequency) ;
		puts("");
		hp_queue_push (queue, curr);
	}
	tree->root = tn1;
}

int main ()
{
	hp_queue *queue = hp_queue_init();
	puts("1");
	read_data_to_queue(queue);
	puts("2");
	huffman_tree *tree = htree_init();
	puts("3");
	build_tree_from_queue(tree, queue);
	puts("4");
	htree_print (tree -> root);
	return 0;
}