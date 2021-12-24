#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define MAX_NB 1000

int main()
{
  srand(time(NULL));
  char *answer = malloc(SIZE);
  int secret = rand() % MAX_NB;
  int value = 5;

  printf("Guess the value of the secret (between 0 and %d)!\n", MAX_NB);
  printf("Your answer: ");

  while (fgets(answer, SIZE, stdin) != NULL)
  {
    printf("You answered: ");
    printf("%s", answer);
    if (sscanf(answer, "%d", &value) == 1)
    {
      if (value == secret)
      {
        printf("Yay! you found it =)\n");
        break;
      }
      else if (value < secret)
      {
        printf("Too low, try again\n\n");
      }
      else if (value > secret)
      {
        printf("Too high, try again\n\n");
      }
    }
    else
    {
      printf("Error, answer must be an integer\n\n");
    }
    printf("Your answer: ");
  }

  free(answer);
  return 0;
}
