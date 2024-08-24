#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <math.h>

// Global constants
#define XRES 800
#define YRES 608
#define GRID_SIZE 32
#define TOWER_SIZE 26
#define GRID_X (XRES / GRID_SIZE)
#define GRID_Y (YRES / GRID_SIZE)

#define TOWER_DEFAULT_MAX_ENERGY 100000
#define TOWER_MAX_PWR 500

// Bullet constants
#define BULLET_SIZE 3            /* pixels */
#define BULLET_MAX_AGE 1000      /* ms */
#define BULLET_PULSE_MAX_AGE 100 /* ms */
#define BULLET_HIT_MAX_AGE 1000  /* ms */
#define BULLET_SPEED 320.1       /* pixels/s */

// Noob constants
#define NOOB_DEFAULT_HP 5827
#define NOOB_DEFAULT_SPEED 35.0 /* pixels/s */
#define NOOB_SIZE 15            /* pixels */
#define WAVE_DELAY 20           /* seconds */

// Some forward declarations
typedef struct noob_t noob_t;
typedef struct bullet_t bullet_t;
typedef struct tower_t tower_t;
typedef struct path_t path_t;
typedef struct state_t state_t;
typedef struct map_t map_t;
typedef struct wave_t wave_t;
typedef struct level_t level_t;

enum {
    DISPLAY_LIST_BEGIN = 1,
    // Various objects in vertex arrays
    DISPLAY_LIST_TOWER = 1,
    DISPLAY_LIST_NOOB = 2,
    DISPLAY_LIST_X = 3,
    DISPLAY_LIST_CTRL = 4,
    DISPLAY_LIST_WAVE = 5,
    DISPLAY_LIST_COMP = 6,
    DISPLAY_LIST_REFLECT = 7,
    DISPLAY_LIST_TOWER_BASE = 8,
    DISPLAY_LIST_TOWER_END = 18,

    // Controls
    DISPLAY_LIST_GRID = 19,
    DISPLAY_LIST_OCCLUDE = 20,
    DISPLAY_LIST_CIRCLE = 21,
    DISPLAY_LIST_GLOW = 22,

    // Tower individual graphics
    DISPLAY_LIST_PATH = 23,

    // font
    DISPLAY_LIST_FONT_BASE = 31
};
