#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int compteur = 1;
void show(int test, char *msg)
{
  char *res = test ? "OK" : "Fail";
  printf("TEST%d %s: %s\n", compteur, msg, res);
  compteur++;
  if (!test)
    exit(0);
}

void increment(int *v)
{
  int *u = v;
  *u = *u + 1;
}

int main(int argc, char **argv)
{
  int level = 1;
  if (argc < 2)
  {
    puts("Script requires an argument between 1 and 5");
    exit(0);
  }
  level = atoi(argv[1]);
  if (level < 1 || level > 5)
  {
    puts("Script requires an argument between 1 and 5");
    exit(0);
  }

  struct tList *l;
  struct tNode *n, *m, *o;
  int u = 1;
  int v = 2;
  int w = 3;

  // Test newlist
  l = newList();
  printf("### Tests de newList ###\n");
  show(l != NULL, "pointeur");
  show(l->nEntries == 0, "nEntries");
  show(l->first == NULL, "first");
  show(l->last == NULL, "last");

  // addListNode
  if (level < 2)
    return 0;
  l = newList();
  n = addListNode(l, &v);

  printf("\n### Test de addListNode ###\n");
  /*printf("Test%d null: ", compteur++);*/
  /*addListNode(NULL, NULL);*/
  /*printf("OK\n");*/
  show(l->nEntries == 1, "nEntries");
  show(l->first == n, "first");
  show(l->last == n, "last");

  m = addListNode(l, &u);
  show(l->nEntries == 2, "nEntries");
  show(l->first == n, "first");
  show(l->last == m, "last");
  show(l->first->next == m, "next");

  // freeList
  if (level < 3)
    return 0;
  freeList(l);
  printf("\n### Test de freeList ###\n");
  show(l != NULL, "pointeur");
  show(l->nEntries == 0, "nEntries");
  show(l->first == NULL, "first");
  show(l->last == NULL, "last");

  // applyFunctionToList
  if (level < 4)
    return 0;
  l = newList();
  n = addListNode(l, &u);
  m = addListNode(l, &v);
  applyFunctionToList(l, &increment);
  printf("\n### Test de applyFunctionToList ###\n");
  show(*((int *)(l->first->item)) == 2, "première valeur");
  show(*((int *)(l->last->item)) == 3, "seconde valeur");

  // deleteNodeFromList
  if (level < 5)
    return 0;
  printf("\n### Test de deleteNodeFromList ###\n");
  deleteFromList(l, m);
  show(l->last == n, "last");
  m = addListNode(l, &v);
  o = addListNode(l, &w);
  deleteFromList(l, m);
  show(l->first->next == o, "middle");
  deleteFromList(l, n);
  show(l->first == o, "first");
}
