#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*******************************************************
 * Function Name: newList
 * Arguments    : none
 * Description  : Allocate and initialise a list structure
 * Returns      : a pointer on the list allocated, or null if the allocation has failed
 *******************************************************/
struct tList * newList(int n)
{
  return NULL;
}

/*******************************************************
 * Function Name: freeList
 * Arguments    : a pointer on a list structure
 * Description  : frees all linked items in the list structure
 * Returns      : nothing, exits if the provided pointer is NULL
 *******************************************************/
void freeList(struct tList *list)
{
}

/*******************************************************
 * Function Name: addListNode
 * Arguments    : a pointer on a list, a pointer on the item to add
 * Description  : add an item to a list (in last position)
 * Returns      : a pointer on the allocated node, or NULL if allocation failed
 *                Exits if the provided list pointer is NULL
 *******************************************************/
struct tNode * addListNode(struct tList * list, int * item)
{
  return NULL;
}

/*******************************************************
 * Function Name: applyFunctionToList
 * Arguments    : a list, and a pointer on the function to apply
 * Description  : Applies a function on all nodes of a list. Useful for example to display all entries in a list. If the list is empty, the function returns without doing anything
 * Returns      : nothing.
 *                Program Exits if the arguments are incorrect.
 *******************************************************/
void applyFunctionToList(struct tList *list, void (*fctPtr)(int*))
{
}

/*******************************************************
 * Function Name: deleteListNode
 * Arguments    : pointer on the list, pointer on the item
 *                to delete
 * Description  : it deletes the node that is passed as parameter
 *                from the list
 * Returns      : nothing
 *******************************************************/
void deleteFromList(struct tList *list, struct tNode *node)
{
}
