#include "field.h"

void allocField (field_t *f) {
  f->field = malloc(f->width * f->height * sizeof(int));
}

void clearField (field_t *f){
  for (int i = 0; i < (f->width * f->height); i++) {
    f->field[i] = 0;
  }  
}

void displayField (field_t *f) {
  for (int y = 0; y < f->height; y++) {
    for (int x = 0; x < f->width; x++) {
      printf("%d ", f->field[(f->height -1) * y + x]);
    }
    putchar('\n');
  }
  putchar('\n');
}

void freeField (field_t *f) {
  free(f);
}