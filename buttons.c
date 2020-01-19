#include "buttons.h"

void getButton (direction_t *d, control_t *control) {

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
        case SDLK_e:
          control->exit = true;
          break;
        case SDLK_ESCAPE:
          control->exit = true;
          break;
        case SDLK_p:
          control->picture = true;
          break;
        default:
          break;
      }
    }
  }
}