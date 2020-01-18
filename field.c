#include "field.h"

void allocField (field_t *field) {
  field->field = malloc(field->height * sizeof(int*));
  for (int y = 0; y < field->height; y++) {
    field->field[y] = malloc(field->height * sizeof(int));
  }
}

void clearField (field_t *field){
  for (int y = 0; y < field->height; y++) {
    for (int x = 0; x < field->width ; x++) {
      field->field[y][x] = 0;
    }
  }  
}

void displayField (field_t *field) {
  for (int y = 0; y < field->height; y++) {
    for (int x = 0; x < field->width; x++) {
      printf("%d ", field->field[y][x]);
    }
    putchar('\n');
  }
  putchar('\n');
}

void freeField (field_t *field) {
  free(field);
}