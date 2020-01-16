#include "field.h"

void allocField (field_t *f) {
  f->field = malloc(f->height * sizeof(int*));
  for (int y = 0; y < f->height; y++) {
    f->field[y] = malloc(f->height * sizeof(int));
  }
}

void clearField (field_t *f){
  for (int y = 0; y < f->height; y++) {
    for (int x = 0; x < f->width ; x++) {
      f->field[y][x] = 0;
    }
  }  
}

void displayField (field_t *f) {
  for (int y = 0; y < f->height; y++) {
    for (int x = 0; x < f->width; x++) {
      printf("%d ", f->field[y][x]);
    }
    putchar('\n');
  }
  putchar('\n');
}

void freeField (field_t *f) {
  free(f);
}