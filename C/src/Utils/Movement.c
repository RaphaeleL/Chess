#include <stdio.h>
#include "Movement.h"
#include <ctype.h>
#include <string.h>

int fromX = -1; 
int fromY = -1; 
int toX = -1; 
int toY = -1; 

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
  printf("From:\t (%d-%d)\nTo:\t (%d-%d)", fromX, fromY, toX, toY);
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

void prepare(int input) {
  int values[4];
  int counter = 3; 

  while(input > 0) { 
    int mod = input % 10;
    setCoords(counter, mod);
    values[counter] = mod; 
    input = input / 10;
    counter--;
  }

  printCoords();
}

int getPlayerInput(int side) {
  int input; 
  if (side == 1) { 
    printf("\nWHITE [From,To] > ");
  } else if (side == -1) {
    printf("\nBLACK [From,To] > ");
  }
  scanf("%d", &input);
  return input;
}

int hasWinner() {
   return 1;
}

void checkWinner() {

}

void handleWinner() {

}

