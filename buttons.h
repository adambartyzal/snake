#ifndef BUTTONS_H
#define BUTTONS_H

#include <SDL.h>
#include "types.h"

SDL_Event event;

void getDirection (direction_t *);
void getControls (void);

#endif