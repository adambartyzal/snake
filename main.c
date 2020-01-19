#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "field.h"
#include "snake.h"
#include "images.h"
#include "buttons.h"

#define RESOLUTION_X 640
#define RESOLUTION_Y 640

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("A game of snake!\nUsage: ./snake [size of field]:\nEnd game with pressing 'e' or 'esc', control with arrow keys, take a picture with 'p'\n");
    return 0;
  }

  int width = RESOLUTION_X;
  int height = RESOLUTION_Y;

  int fieldSize;
  fieldSize = (argc == 2) ? atoi(argv[1]) : 10;

  field_t *field = malloc(sizeof(field_t));
  initField(field, fieldSize);
 
  control_t *control = malloc(sizeof(control_t));

  direction_t dir = right;

  char filename[20] = "snake.ppm";
  image_t *image = malloc(sizeof(image_t));
  image = initImage(image, width, height, filename);

  snake_t *snake = malloc(sizeof(snake_t));
  initSnake(snake,field);

  position_t *foodPos = malloc(sizeof(position_t));
  food_t *food = malloc(sizeof(food_t));
  food->pos = foodPos;
  moveFood(food,field);
  
  initWindow(image);

  // infinite loop goes here

  for (;;) {
    //input
    getButton(&dir,control);

    //update
    if (control->exit) break;
    if(eating(snake,food)) {
      moveFood(food,field);
      enlargeSnake(snake);
      if (snake->size > fieldSize * fieldSize) break;
    }
    if(control->picture) {
      saveImage(image);
      control->picture = false;
    } 
    changeDirection(snake,&dir);
    moveSnake(snake,field);
    if(crash(snake)) break;
    clearField(field);
    placeFood(food,field);
    placeSnake(snake,field);   
    //show
    generateImage(image,field);
    showImage(image);  
  } 

  printf("Score: %d\n",snake->size);

  freeSnake(snake);
  freeField(field);
  freeImage(image);
  freeFood(food);
  free(control);

  return(0);
}
