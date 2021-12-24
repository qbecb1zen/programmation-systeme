/* A linked node in a list            */
/* This list is a one way linked list */
struct tNode
{
  void *item;         /* The data pointed by the node          */
  struct tNode *next; /* Link to the next node in the list     */
};

/* The list structure */
struct tList
{
  int nEntries;
  struct tNode *first; /* First node in the list */
  struct tNode *last;  /* Last node in the list  */
};

/* Function definitions */
struct tList *newList(void);
void freeList(struct tList *);
struct tNode *addListNode(struct tList *, int *);
void applyFunctionToList(struct tList *, void (*fctPtr)(int *));
void deleteFromList(struct tList *, struct tNode *);
void bubble(struct tList *);
