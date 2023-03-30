#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of integers
 *
 * @root: double pointer to the root node of heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
int value;
heap_t *last, *temp;

if (!root || !(*root))
return 0;

last = (*root);
while (last->right)
last = last->right;

if (last == (*root))
{
value = last->n;
free(*root);
*root = NULL;
return value;
}

temp = (*root);
while (temp->right != last)
temp = temp->right;

value = (*root)->n;
(*root)->n = last->n;
temp->right = NULL;
free(last);

for (temp = (*root); temp; temp = temp->left)
{
if (temp->right && temp->right->n > temp->n)
{
swap_nodes(temp, temp->right);
temp = temp->right;
}
if (temp->left && temp->left->n > temp->n)
swap_nodes(temp, temp->left);
}

return value;
}
