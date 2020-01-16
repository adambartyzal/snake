#include "snake.h"

bool enlargeSnake (snake_t * s) {
  dot_t* dot = malloc(sizeof (dot_t));
  if (dot == NULL) {
    return false;
  }
  position_t *new = malloc (sizeof (position_t));
  if (new == NULL) {
    return false;
  }
  s->size++;
  dot->pos = new;
  dot->pos->x = 0;
  dot->pos->y = 0;
  dot->next = NULL;
  dot->prev = s->tail;
  s->tail->next = dot;
  s->tail = dot;
  return true;
}

void placeSnake (snake_t *s, field_t *f) {
  dot_t *tmp = s->head;
  for (int i = 0; i < s->size; i++) {
    f->field[tmp->pos->y][tmp->pos->x] = 1;
    tmp = tmp->next;
  }
}

void moveSnake (snake_t *s, field_t *f) {

  // bubble douwn positions
  dot_t *tmp = s->tail;
  for (int i = 0; i < s->size - 1; i++) {
    tmp->pos->x = tmp->prev->pos->x;
    tmp->pos->y = tmp->prev->pos->y;
    tmp = tmp->prev;
  }

  // new head pos
  switch (s->dir)
  {
  case up:
    if (s->head->pos->y-- <= 0) s->head->pos->y = f->height-1;
    break;

  case down:
    if (s->head->pos->y++ >= f->height) s->head->pos->y = 0;
    break;

  case left:
    if (s->head->pos->x-- <= 0) s->head->pos->x = f->width-1;
    break;

  case right:
    if (s->head->pos->x++ >= f->width) s->head->pos->x = 0;
    break;
  

  default:
    printf ("Direction Error!");
    break;
  } 
  //printf("%d,%d\n",s->head->pos->x,s->head->pos->y);
}

void changeDirection (snake_t *s, direction_t dir) {
  
  switch (dir)
  {
  case up:
    if (s->dir != down) s->dir = dir;
    break;

  case down:
    if (s->dir != up) s->dir = dir;
    break;

  case left:
    if (s->dir != right) s->dir = dir;
    break;

  case right:
    if (s->dir != left) s->dir = dir;
    break;
  
  default:
    printf ("Direction Error!");
    break;
  } 
}