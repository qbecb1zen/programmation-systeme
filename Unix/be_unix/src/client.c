#include <stdio.h>
#include "utils.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
  int socket_client, valread;
  struct sockaddr_in serv_addr;
  char *cmd = "ADD Lancelot padel lundi 113";
  char buffer[1024] = {0};
  socket_client = socket(AF_INET, SOCK_STREAM, 0);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERVER_PORT);

  inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

  if (connect(socket_client, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    printf("\nConnection Failed \n");
    return -1;
  }
  send(socket_client, cmd, strlen(cmd), 0);
  // valread = read(socket_client, buffer, 1024);
  // printf("%s\n", buffer);
  return 0;
}
