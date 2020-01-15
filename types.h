#ifndef TYPES_H
#define TYPES_H

typedef struct {
  int width, 
      height;
  int *field;
}field_t;

typedef struct {
  int x;
  int y;
}position_t;

typedef struct dot_t dot_t;

struct dot_t{
  position_t *pos;
  dot_t *prev;
  dot_t *next;
};

typedef struct{
  position_t *pos;
}food_t;

typedef enum{
  up,down,left,right
}direction_t;

typedef struct{
  dot_t *head;
  dot_t *tail;
  int size;
  direction_t dir;
}snake_t; 

#endif