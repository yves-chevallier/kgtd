#include "grid_objs.h"

grid_t grid[GRID_Y][GRID_X];

void grid_init() {
    for (int i = 0; i < GRID_Y; i++) {
        for (int j = 0; j < GRID_X; j++) {
            grid[i][j].g = GRID_TYPE_NONE;
        }
    }
}
