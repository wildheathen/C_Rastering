#pragma once
#include "SDL.h"
#include "color.h"

typedef struct
{
    int width;
    int height;
    SDL_Renderer* renderer;
    SDL_Texture* texture; 
    Uint8* color_buffer;
    size_t color_buffer_size;
} screen_t;


screen_t* screen_new(int w, int h, SDL_Renderer* r);
screen_t* screen_free(screen_t* s);
void screen_blit(screen_t* screen);
void screen_put_pixel(screen_t* screen, int x, int y, color_t color);

