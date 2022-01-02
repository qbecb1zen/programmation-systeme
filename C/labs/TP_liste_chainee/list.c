#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define TRUE 1
#define FALSE 0
/*******************************************************
 * Function Name: newList
 * Arguments    : none
 * Description  : Allocate and initialise a list structure
 * Returns      : a pointer on the list allocated, or null if the allocation has failed
 *******************************************************/
struct tList *newList()
{
  struct tList *tmpList = malloc(sizeof(struct tList));
  if (tmpList != NULL)
  {
    tmpList->nEntries = 0;
    tmpList->first = NULL;
    tmpList->last = NULL;
  }
  return tmpList;
}

/*******************************************************
 * Function Name: freeList
 * Arguments    : a pointer on a list structure
 * Description  : frees all linked items in the list structure
 * Returns      : nothing, exits if the provided pointer is NULL
 *******************************************************/
void freeList(struct tList *list)
{
  struct tNode *node, *next;

  node = list->first;

  for (int i = 0; i < list->nEntries; i++)
  {
    next = node->next;
    free(node);
    node = next;
  }
  list->first = NULL;
  list->last = NULL;
  list->nEntries = 0;
}

/*******************************************************
 * Function Name: addListNode
 * Arguments    : a pointer on a list, a pointer on the item to add
 * Description  : add an item to a list (in last position)
 * Returns      : a pointer on the allocated node, or NULL if allocation failed
 *                Exits if the provided list pointer is NULL
 *******************************************************/
struct tNode *addListNode(struct tList *list, int *item)
{
  struct tNode *tmpNode;

  tmpNode = malloc(sizeof(struct tNode));

  tmpNode->item = item;
  tmpNode->next = NULL;

  if (list->nEntries == 0)
  {
    list->first = tmpNode;
    list->last = tmpNode;
  }
  else
  {
    list->last->next = tmpNode;
    list->last = tmpNode;
  }
  list->nEntries++;

  return tmpNode;
}

/*******************************************************
 * Function Name: applyFunctionToList
 * Arguments    : a list, and a pointer on the function to apply
 * Description  : Applies a function on all nodes of a list. Useful for example to display all entries in a list. If the list is empty, the function returns without doing anything
 * Returns      : nothing.
 *                Program Exits if the arguments are incorrect.
 *******************************************************/
void applyFunctionToList(struct tList *list, void (*fctPtr)(int *))
{
  struct tNode *node, *next;

  node = list->first;
  for (int i = 0; i < list->nEntries; i++)
  {
    next = node->next;
    (*fctPtr)(node->item);
    node = node->next;
  }
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
  struct tNode *current = list->first;
  struct tNode *prev = NULL;

  // if the list has only one element, then we will clear it!
  if ((list->first == list->last) && (current == node))
  {
    list->first = NULL;
    list->last = NULL;
    free(current);
    list->nEntries = 0;
  }
  else
  {
    for (int i = 0; i < list->nEntries; i++)
    {
      if (current == node)
      {
        if (prev) // if the previous exists
          prev->next = current->next;
        else // if all elements between the first and the current one are NULL
          list->first = current->next;

        if (current == list->last) // if it's the last element of the list
          list->last = prev;

        list->nEntries = list->nEntries - 1;
        free(current);
        break;
      }
      prev = current;
      current = current->next;
    }
  }
}
