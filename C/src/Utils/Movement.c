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
  printf("Hint: CChess is still in development, so there might be any issues \n ");
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

int checkWinner(int board[8][8]) {
   int blackCount = 0; 
   int whiteCount = 0; 
   for (int i = 0; i < 8; i++) {
     for (int j = 0; j < 8; j++) {
        int piece = board[i][j];
        if (piece > 0) {
          blackCount++;
        } else if (piece < 0) {
          whiteCount++;
        }
     }
   }
   if (blackCount == 0) {
     handleWinner(1); 
    return 0;
   } else if (whiteCount == 0) {
     handleWinner(2);
    return 0;
   }
  return 1;
}

void handleWinner(int side) {
  printf("======================================================\n");
  if (side == 1) {
    printf("Black won\n");
  } else if (side == 2) {
    printf("White won\n");
  }
  printf("======================================================\n");
}

