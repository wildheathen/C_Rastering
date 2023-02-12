﻿#include "triangle-raster.h"


int min3(int v1, int v2, int v3)
{
    int result = v1;
    if (v2 < result) result = v2;
    if (v3 < result) result = v3;
    return  result;
}

int max3(int v1, int v2, int v3)
{
    int result = v1;
    if (v2 > result) result = v2;
    if (v3 > result) result = v3;
    return  result;    
}

int det(vector2_t p, vector2_t v1, vector2_t v2)
{
    //A->
    int vx = v2.x - v1.x;
    int vy = v2.y - v1.y;

    //B->
    int px = p.x - v1.x;
    int py = p.y - v1.y;

    return vx * py - vy * px;
}

bool bbox_is_point_in_triangle(vector2_t P, vector2_t A, vector2_t B, vector2_t C)
{
    bool b1,b2,b3;
    b1 = det(P,A,B) < 0;
    b2 = det(P,B,C) < 0;
    b3 = det(P,C,A) < 0;

    return (b1 == b2) && (b2 == b3);    
}


void bbox_trinagle_raster(screen_t* screen, vector2_t p1, vector2_t p2, vector2_t p3, color_t color)
{
    int x_min = min3(p1.x, p2.x, p3.x);
    int y_min = min3(p1.y, p2.y, p3.y);

    int x_max = max3(p1.x, p2.x, p3.x);
    int y_max = max3(p1.y, p2.y, p3.y);

    for (int x = x_min; x <= x_max; ++x)
    {
        for (int y = y_min; y <= y_max; ++y)
        {
            vector2_t point = {x, y};
            if (bbox_is_point_in_triangle(point, p1, p2, p3))
            {
                screen_put_pixel(screen, x, y, color);
            }
        }
    }
}
