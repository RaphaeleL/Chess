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
} 

void printCoords() {
  printf("From:\t (%c-%c)\nTo:\t (%c-%c)", fromX, fromY, toX, toY);
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
  printf("\n%s from-x \t> ", side);
  scanf("%c", &fromX);
  getchar();
  printf("%s from-y \t> ", side);
  scanf("%c", &fromY);
  getchar();
  printf("%s to-x \t> ", side);
  scanf("%c", &toX);
  getchar();
  printf("%s to-y \t> ", side);
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
}

int hasWinner() {
   return 1;
}

void checkWinner() {

}

void handleWinner() {

}

