#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "field.h"
#include "snake.h"

int main()
{
  int fieldSize = 9;
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

  snake_t snake;
  snake.head = head;
  snake.tail = tail;
  snake.size = 2;
  snake.dir = initDir;

  for (int i = 0; i < 4; i++) {
    clearField(&field);
    placeSnake(&snake,&field);
    displayField(&field);
    moveSnake(&snake,&field);
    enlargeSnake(&snake);
  }

    snake.dir = right;

  for (int i = 0; i < 4; i++) {
    clearField(&field);
    placeSnake(&snake,&field);
    displayField(&field);
    moveSnake(&snake,&field);
  }
  

  return(0);
}
