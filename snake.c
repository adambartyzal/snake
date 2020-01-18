#include "snake.h"

void placeSnake (snake_t *snk, field_t *fld) {
  dot_t *tmp = snk->head;
  for (int i = 0; i < snk->size; i++) {
    for (int c = 0; c < 3; c++) {  
      fld->field[tmp->pos->y][tmp->pos->x][c] = 0XFF;
    }
    tmp = tmp->next;
  }
}

void moveSnake (snake_t *snk, field_t *fld) {

  // bubble douwn positions
  dot_t *tmp = snk->tail;
  for (int i = 0; i < snk->size - 1; i++) {
    tmp->pos->x = tmp->prev->pos->x;
    tmp->pos->y = tmp->prev->pos->y;
    tmp = tmp->prev;
  }

  // new head pos
  switch (snk->dir)
  {
  case up:
    if (snk->head->pos->y-- <= 0) 
      snk->head->pos->y = fld->height-1;
    break;

  case down:
    if (snk->head->pos->y++ >= fld->height-1) 
      snk->head->pos->y = 0;
    break;

  case left:
    if (snk->head->pos->x-- <= 0) 
      snk->head->pos->x = fld->width-1;
    break;

  case right:
    if (snk->head->pos->x++ >= fld->width-1) 
      snk->head->pos->x = 0;
    break;

  default:
    printf ("Direction Error!");
    break;
  } 
}

bool enlargeSnake (snake_t * snk) {
  dot_t* dot = malloc(sizeof (dot_t));
  if (dot == NULL) {
    return false;
  }
  position_t *new = malloc (sizeof (position_t));
  if (new == NULL) {
    return false;
  }
  snk->size++;
  dot->pos = new;
  dot->pos->x = 0;
  dot->pos->y = 0;
  dot->next = NULL;
  dot->prev = snk->tail;
  snk->tail->next = dot;
  snk->tail = dot;
  return true;
}

void changeDirection (snake_t *snk, direction_t dir) {
  
  switch (dir)
  {
  case up:
    if (snk->dir != down) 
      snk->dir = dir;
    break;

  case down:
    if (snk->dir != up) 
      snk->dir = dir;
    break;

  case left:
    if (snk->dir != right) 
      snk->dir = dir;
    break;

  case right:
    if (snk->dir != left) 
      snk->dir = dir;
    break;
  
  default:
    printf ("Direction Error!");
    break;
  } 
}

void placeFood (food_t *fd, field_t *fld) {
  fld->field[fd->pos->y][fd->pos->x][0] = 0xFF;
}

void moveFood (food_t *fd, field_t *fld) {
  fd->pos->x = fld->width * (double) rand() / (double) RAND_MAX;
  fd->pos->y = fld->width * (double) rand() / (double) RAND_MAX;
}

bool eating(snake_t *snk, food_t *fd) {
  return (snk->head->pos->x == fd->pos->x && snk->head->pos->y == fd->pos->y) ? true : false;
}

bool crash(snake_t *snk) {
    dot_t *tmp = snk->tail;
  for (int i = 0; i < snk->size - 1; i++) {
    if (snk->head->pos->x == tmp->pos->x && snk->head->pos->y == tmp->pos->y) {
      return true;
    }
    tmp = tmp->prev;
  }
  return false;
}