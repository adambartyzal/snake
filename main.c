#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "field.h"
#include "snake.h"
#include "images.h"
#include "buttons.h"

#define RESOLUTION_X 640
#define RESOLUTION_Y 640

int main()
{
  printf("A game of snake: end with pressing 'e', control with arrow keys, take a picture with 'p'\n");

  int width = RESOLUTION_X;
  int height = RESOLUTION_Y;

  control_t *control = malloc(sizeof(control_t));


  char filename[20] = "snake.ppm";
  image_t *image = malloc(sizeof(image_t));
  image = initImage(image, width, height, filename);

  int fieldSize = 55;
  field_t *field = malloc(sizeof(field_t));
  //field_t field;
  field->height = fieldSize;
  field->width = fieldSize;
  allocField(field);

  position_t *headPos = malloc(sizeof(position_t));
  headPos->x = field->width / 2;
  headPos->y = field->height / 2;

  position_t *tailPos = malloc(sizeof(position_t));
  tailPos->x = field->width / 2;
  tailPos->y = field->height / 2;
  tailPos->y++;

  dot_t *head = malloc(sizeof(dot_t));
  head->prev = NULL;
  head->pos = headPos;

  dot_t *tail = malloc(sizeof(dot_t));
  tail->pos = tailPos;
  tail->prev = head;
  tail->next = NULL;

  head->next = tail;

  direction_t *dir = malloc(sizeof(direction_t));
  *dir = right;

  snake_t *snake = malloc(sizeof(snake_t));
  snake->head = head;
  snake->tail = tail;
  snake->size = 2;
  snake->dir = *dir;

  position_t *foodPos = malloc(sizeof(position_t));
  food_t *food = malloc(sizeof(food_t));
  food->pos = foodPos;
  moveFood(food,field);
  
  initWindow(image);

  // infinite loop goes here

  for (;;) {
    //input
    getButton(dir,control);

    //update
    if (control->exit) break;
    if(crash(snake)) break;
    if(eating(snake,food)) {
      moveFood(food,field);
      enlargeSnake(snake);
      if (snake->size > 10) break;
    }
    if(control->picture) {
      saveImage(image);
      control->picture = false;
    } 
    changeDirection(snake,dir);
    moveSnake(snake,field);
    clearField(field);
    placeFood(food,field);
    placeSnake(snake,field);   
    //show
    generateImage(image,field);
    showImage(image);  
  } 

  return(0);
}
