#include "scene.h"
#include "SDL.h"
#include <stdlib.h>
#include "screen.h"


void dda_line_raster(screen_t* screen, int x1, int y1, int x2, int y2, color_t color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = (dx > dy) ? dx : dy;

    int sx = (x1 > x2) ? -1 : 1;
    int sy = (y1 > y2) ? -1 : 1;
    
    float step_x = (float)dx * (float)sx / (float)steps;
    float step_y = (float)dy * (float)sy / (float)steps;
    
    float x = x1;
    float y = y1;

    
    for (int i = 0; i <= steps; i++)
    {
        screen_put_pixel(screen, x, y, color);
        x += step_x;
        y += step_y;
    }
}

scene_t* scene_create(int screen_width, int screen_height, SDL_Renderer* r)
{
    scene_t* scene = (scene_t*)malloc(sizeof(scene_t));
    scene->screen = screen_new(screen_width, screen_height, r);
    return scene;
}

void scene_update(scene_t* s, float delta_time)
{
    color_t red = {255,0,0,255};

    static float x1 = 50;
    static float y1 = 50;
    static float x2 = 200;
    static float y2 = 250;

    dda_line_raster(s->screen, (int)x1, (int)y1, (int)x2, (int)y2, red);
    //dda_line_raster(s->screen, x1 + 10, y1, x2 + 10, y2, red);
    float speed = 1;
    
    x1 += speed * delta_time;
    x2 += speed * delta_time;

    vector2_t = () 
    bbox_trinagle_raster(s->screen, )

    screen_blit(s->screen);
}

void scene_destroy(scene_t* s)
{
    screen_free(s->screen);
    free(s);
}