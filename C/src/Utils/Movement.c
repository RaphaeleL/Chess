#include <stdio.h>
#include "Movement.h"

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

int chooseColor() {
  char color; 
  printf("Hint: CChess is still in development, so currently the \nboard does not rotate with the choice of color.\n");
  printf("\nWhich color? (W/b) > ");
  scanf("%c", &color);
  printf("\n=========================================================\n");
  printf("=========================================================\n");
  return color;
}

