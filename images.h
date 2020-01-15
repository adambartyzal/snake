#ifndef IMAGES_H
#define IMAGES_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <jpeglib.h>
#include "xwin_sdl.h"
#include "types.h"

// allocs dynamic structs name and data and fills image struct with called paramateres
image_t *initImage(image_t *img, int width, int height, char *name);

//fills image data
bool generateImage(image_t *img);

//opens xwindows and shows the image; flase if fail
void showImage(image_t *img);

//save image to file; flase if fail
bool saveImage(image_t *img);

//loads image from file; flase if fail
bool loadImage(image_t *img);

//deallocates dynamically allocated structs
void freeImage(image_t *img);

#endif