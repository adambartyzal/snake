#include "buttons.h"

void getDirection (direction_t *d) {

  while( SDL_PollEvent( &event ) ){
    switch( event.type ){
      /* Look for a keypress */
      case SDL_KEYDOWN:
        /* Check the SDLKey values and move change the coords */
        switch( event.key.keysym.sym ){
        case SDLK_LEFT:
          *d = left;
          break;
        case SDLK_RIGHT:
          *d = right;
          break;
        case SDLK_UP:
          *d = up;
          break;
        case SDLK_DOWN:
          *d = down;
          break;
        default:
          break;
      }
    }
  }
}