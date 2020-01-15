#ifndef FIELD_H
#define FIELD_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

// allocates memory for field struct
void allocField (field_t *f);

// set all values in filed in field struct to 0
void clearField (field_t *f);

// display field to console
void displayField (field_t *f);

// deallocs field struct
void freeField (field_t *f);

#endif