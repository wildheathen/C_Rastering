#pragma once

#include "vector.h"
#include "color.h"
#include "screen.h"
#include <stdbool.h>

void bbox_trinagle_raster(screen_t* screen, vector2_t p1, vector2_t p2, vector2_t p3, color_t color);

bool bbox_is_point_in_triangle(vector2_t P, vector2_t A, vector2_t B, vector2_t C);

int det(vector2_t p, vector2_t v1, vector2_t v2);
