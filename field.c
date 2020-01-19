#include "field.h"

void initField (field_t *field, int fieldSize) {
  field->width = fieldSize;
  field->height = fieldSize;
  field->field = malloc(field->height * sizeof(int**));
  for (int y = 0; y < field->width; y++) {
    field->field[y] = malloc(field->height * sizeof(int*));
    for (int x = 0; x < field->width ; x++) {
      field->field[y][x] = malloc(field->height * sizeof(int));
    }
  }
}

void clearField (field_t *field){
  for (int y = 0; y < field->height; y++) {
    for (int x = 0; x < field->width ; x++) {
      for (int c = 0; c < 3 ; c++) {
        field->field[y][x][c] = 0xF;
      }
    }
  }  
}

//void displayField (field_t *field) {
//  for (int y = 0; y < field->height; y++) {
//    for (int x = 0; x < field->width; x++) {
//      printf("%d ", field->field[y][x]);
//    }
//    putchar('\n');
//  }
//  putchar('\n');
//}

void freeField (field_t *field) {
  for (int y = 0; y < field->width; y++) {
    for (int x = 0; x < field->width ; x++) {
      free(field->field[y][x]);
    }
    free(field->field[y]);
  }
  free(field->field);
  free(field);
}