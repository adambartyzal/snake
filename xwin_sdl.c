/*
 * File name: xwin_sdl.c
 * Date:      2017/01/16 17:00
 * Author:    Jan Faigl
 */

#include <assert.h>

#include <SDL.h>

#include "xwin_sdl.h"

static SDL_Window *win = NULL;

int xwin_init(int w, int h)
{
   int r;
   r = SDL_Init(SDL_INIT_VIDEO);
   assert(win == NULL);
   win = SDL_CreateWindow("prp-exam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
   assert(win != NULL);
   SDL_SetWindowTitle(win, "PRP-EXAM");   
   return r;
}

void xwin_close()
{
   assert(win != NULL);
   SDL_DestroyWindow(win);
   SDL_Quit();
}

void xwin_redraw(int w, int h, unsigned char *img) 
{
   assert(img && win);
   SDL_Surface *scr = SDL_GetWindowSurface(win);
   for(int y = 0; y < scr->h; ++y) {
      for(int x = 0; x < scr->w; ++x) {
         const int idx = (y * scr->w + x) * scr->format->BytesPerPixel;
         Uint8 *px = (Uint8*)scr->pixels + idx;
         *(px + scr->format->Rshift / 8) = *(img++);
         *(px + scr->format->Gshift / 8) = *(img++);
         *(px + scr->format->Bshift / 8) = *(img++);
      }
   }
   SDL_UpdateWindowSurface(win);
}

void delay(int ms) 
{
   SDL_Delay(ms);
}

/* end of xwin_sdl.c */
