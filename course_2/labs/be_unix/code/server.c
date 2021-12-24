#include <string.h>
#include "utils.h"

char* bdd_bin = "./bdd";

//On prépare les arguments qui seront envoyés à bdd
//ADD toto poney lundi 3 -> { "./bdd", "ADD", "toto", "poney", lundi", "3", NULL }
char** parse(char* line) {
  char** res = malloc(7 * sizeof(char*));
  res[0] = bdd_bin;

  char* arg1 = strtok(line, " ");
  res[1] = arg1;

  char* arg2 = strtok(NULL, " ");
  res[2] = arg2;
  if (arg2 == NULL) {
    arg1[strlen(arg1)-1] = '\0';
    return res;
  }

  char* arg3 = strtok(NULL, " ");
  res[3] = arg3;
  if (arg3 == NULL) { 
    arg2[strlen(arg2)-1] = '\0';
    return res;
  }

  char* arg4 = strtok(NULL, " ");
  res[4] = arg4;
  if (arg4 == NULL) {
    arg3[strlen(arg3)-1] = '\0';
    return res;
  } 
  
  char* arg5 = strtok(NULL, "\n");
  res[5] = arg5;
  res[6] = NULL;
  return res;
}

//Configuration de la socket réseau, retourne le file descriptor de la socket
int configure_socket() {
  int socket_desc;
  return socket_desc;
}

// Passage des commandes à la base de données par un pipe
// Renvoi des réponses au client par la socket réseau
void process_communication(int socket_desc) {
}

int main(int argc, char** argv) {
  int socket_desc;
  int new_socket;

  // Configuration de la socket serveur
  socket_desc = configure_socket();

  // Réception des connections réseaux entrantes

  // Gestion des commandes entrantes dans la nouvelle socket
  process_communication(new_socket);

  /*end hide*/
  return 0;
}
