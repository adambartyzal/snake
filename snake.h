#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

// Returns false if something fails
bool enlargeSnake (snake_t *s);

// Place snake on the field. Goes through snake from tail to head.
void placeSnake (snake_t *s, field_t *f);

// Moving in direction
void moveSnake (snake_t *s, field_t *f);

// Put new dot in field in random place
void placeFood (snake_t *s, field_t *f);

#endif