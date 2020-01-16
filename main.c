#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "field.h"
#include "snake.h"
#include "images.h"

#define RESOLUTION_X 640
#define RESOLUTION_Y 480

int main()
{

  int width = RESOLUTION_X;
  int height = RESOLUTION_Y;

  char filename[20] = "image.ppm";
  image_t *image = malloc(sizeof(image_t));
  image = initImage(image, width, height, filename);

  int fieldSize = 35;
  field_t field;
  field.height = fieldSize;
  field.width = fieldSize;
  allocField(&field);
  clearField(&field);

  position_t *headInitPos = malloc(sizeof(position_t));
  headInitPos->x = field.width / 2;
  headInitPos->y = field.height / 2;

  position_t *tailInitPos = malloc(sizeof(position_t));
  tailInitPos->x = field.width / 2;
  tailInitPos->y = field.height / 2;
  tailInitPos->y++;

  dot_t *head = malloc(sizeof(dot_t));
  head->prev = NULL;
  head->pos = headInitPos;

  dot_t *tail = malloc(sizeof(dot_t));
  tail->pos = tailInitPos;
  tail->prev = head;
  tail->next = NULL;

  head->next = tail;

  direction_t initDir = up;
\
  snake_t snake;
  snake.head = head;
  snake.tail = tail;
  snake.size = 2;
  snake.dir = initDir;
  
  enlargeSnake(&snake);
  moveSnake(&snake,&field);

  initWindow(image);
  //changeDirection(&snake,right);

  for (int i = 0; i < 8; i++) {
    clearField(&field);
    placeSnake(&snake,&field);   
    //displayField(&field);
    generateImage(image,&field);
    showImage(image);    
    moveSnake(&snake,&field);
  } 

  changeDirection(&snake,right);

  for (int i = 0; i < 8; i++) {
    clearField(&field);
    placeSnake(&snake,&field);   
    //displayField(&field);
    generateImage(image,&field);
    showImage(image);    
    moveSnake(&snake,&field);
  } 


  return(0);
}
