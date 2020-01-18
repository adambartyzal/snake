#include "images.h"
#define MAX_COLOR_VALUE 255

image_t *initImage(image_t *img, int width, int height, char *name) {
  img->name = name;
  img->width = width;
  img->height = height;
  int i = 0;
  int size = 20;
  img->name = malloc(size*sizeof(char));
  while (name[i] != 0) {
    if (i == size) {
      size *= 2;
      name = realloc(name, size*sizeof(char));
    }
    img->name[i] = name[i];
    i++;
  }
  img->name[i] = 0;
  img->data = malloc(sizeof(char) * width * height * 3);
  return img;
}

bool generateImage(image_t *img, field_t *f) {
  int ptr = 0,
      fieldPosX = 0,
      fieldPosY = 0, 
      condition = 0;
  unsigned char one = 255, zero = 0;

  // more vars for better readibility
  for(int y = 0; y < img->height; y++) {
    for(int x = 0; x < img->width; x++) {
      fieldPosY = y / ( (double) img->height / (double) (f->height));
      fieldPosX = x / ((double) img->width / (double) (f->width)); 
      condition = f->field[fieldPosY][fieldPosX]; // Snake or not
      img->data[ptr] = condition ? one : zero; // R
      img->data[ptr+1] = condition ? one : zero; // G
      img->data[ptr+2] = condition ? one : zero; // B
      ptr += 3;
    }
  }

  return true;
}

bool saveImage(image_t *img) {
  FILE *f = fopen(img->name,"w");
  if (f == NULL) return false;
  fprintf(f, "P6\n %s\n %d\n %d\n %d\n", img->name, img->width, img->height, MAX_COLOR_VALUE);
  for (int i = 0; i < (3*img->width * img->height); i++) {
    fwrite(img->data+i,sizeof(char),1,f);
  }  
  fclose(f);
  return true;
}

bool loadImage(image_t *img) {

  FILE *f = fopen(img->name,"r");
  if (f == NULL) return false;
  char tmp;

  for (int i = 0; i < 29; i++) {
    if (fread(&tmp,sizeof(char),1,f) != 1){
      printf("Header reading error!\n");
      return false;
    }
  }
  
  for (int i = 0; i < (3*img->width * img->height); i++) {
    if (fread(img->data+i,sizeof(char),1,f) != 1){
      printf("Image reading error!\n");
      return false;
    }
  }
  fclose(f);
  return true;
}

void freeImage(image_t *img) {
  free(img->data);
  free(img->name);
  free(img);
}

void initWindow(image_t *img){
  xwin_init(img->width, img->height); /*open window*/
}

void showImage(image_t *img){
  xwin_redraw(img->width, img->height, img->data); /* draw the image to the window */
  delay(100);
}

void saveJpeg(image_t *img){

}