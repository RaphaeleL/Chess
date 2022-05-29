#include <stdio.h>
#include "Movement.h"
#include <ctype.h>
#include <string.h>

char fromX = -1; 
char fromY = -1; 
char toX = -1; 
char toY = -1; 

void dearScreen() {
  printf(" ######   ######  ##     ## ########  ######   ######  \n");
  printf("##    ## ##    ## ##     ## ##       ##    ## ##    ## \n");
  printf("##       ##       ##     ## ##       ##       ##       \n");
  printf("##       ##       ######### ######    ######   ######  \n");
  printf("##       ##       ##     ## ##             ##       ## \n");
  printf("##    ## ##    ## ##     ## ##       ##    ## ##    ## \n");
  printf(" ######   ######  ##     ## ########  ######   ######  \n");
  printf("======================================================\n");
  printf("======================================================\n");
  printf("Hint: CChess is still in development, so currently the \n ");
  printf("board does not rotate with the choice of color.\n");
  printf("======================================================\n");
  printf("======================================================\n");
} 

int getPosition (char c) {
  int pos;
  const char * alphabet = "abcdefghijklmnopqrstuvwxyz";
  const char * found;
  c = tolower ((unsigned char)c);
  found = strchr (alphabet, c);
  pos = found - alphabet;
  if (!found)
      pos = 0;
  else if (pos == 26)
      pos = 0;
  else
      pos++;
  return pos;
}

int getFromX() {
  return getPosition(fromX) - 1;
}

int getFromY() {
  return (int) fromY - '0' - 1;
}

int getToX() {
  return getPosition(toX) - 1;
}

int getToY() {
  return (int) toY - '0' - 1;
}

void setCoords(int counter, int mod) {
  if (counter == 0) { 
    fromX = mod; 
  } else if (counter == 1) { 
    fromY = mod; 
  } else if (counter == 2) { 
    toX = mod; 
  } else if (counter == 3) { 
    toY = mod;
  }
}

void getInput(char* side) {
  printf("\n%s from-x > ", side);
  scanf("%c", &fromX);
  getchar();
  printf("%s from-y > ", side);
  scanf("%c", &fromY);
  getchar();
  printf("%s to-x   > ", side);
  scanf("%c", &toX);
  getchar();
  printf("%s to-y   > ", side);
  scanf("%c", &toY);
  getchar();
  //printCoords();
}

void getPlayerInput(int side) {
  if (side == 1) { 
    getInput("WHITE");
  } else if (side == -1) {
    getInput("BLACK");
  }
  printf("\n");
}

int hasWinner() {
   return 1;
}

void checkWinner() {

}

void handleWinner() {

}

