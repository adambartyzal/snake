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
    f->field[f->width * tmp->pos->x + tmp->pos->y] = 1;
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
    if (s->head->pos->y-- == -1) s->head->pos->y = f->height;
    break;

  case down:
    if (s->head->pos->y++ == f->height + 1) s->head->pos->y = 0;
    break;

  case left:
    if (s->head->pos->x-- == -1) s->head->pos->x = f->width;
    break;

  case right:
    if (s->head->pos->x++ == f->width + 1) s->head->pos->x = 0;
    break;
  
  default:
    printf ("Direction Error!");
    break;
  } 
}