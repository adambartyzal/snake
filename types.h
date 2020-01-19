#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

typedef struct {
  bool exit,
       picture;
}control_t;

typedef struct {
  int width, 
      height;
  int ***field; // adress as field[y][x][c] where y = height, x = width, c = color in format [0] = R(0-255),[1] G(0-255),[2] = B(0-255)
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

typedef struct {
  int width,
      height;
  char *name;
  unsigned char *data;  
}image_t;

#endif