#include "level.h"
#include "noob.h"

// Path format is distance in x, distance in y, distance in x, ...
// no builtin intersection detection or out of bounds detection
static int path1[] = {5, -3, 4, 4, -3, 6, 12, -10};
static int path2[] = {8, 5, 2, -10, 2, 5, 9};

// Define waves for level 1
static wave_t waves_level1[] = {
    {NULL, 10, NOOB_DEFAULT_HP, 0, 500, NOOB_DEFAULT_SPEED, 0},
    {NULL, 20, NOOB_DEFAULT_HP * 2, 0, 500, NOOB_DEFAULT_SPEED / 2, 0},
    {NULL, 20, NOOB_DEFAULT_HP * 2, 0, 500, NOOB_DEFAULT_SPEED, 0},
    {NULL, 30, NOOB_DEFAULT_HP, NOOB_DEFAULT_HP * 3, 500, NOOB_DEFAULT_SPEED, 0},
    {NULL, 40, NOOB_DEFAULT_HP * 2, NOOB_DEFAULT_HP, 500, NOOB_DEFAULT_SPEED, ARMOR_COMPOSITE},
    {NULL, 50, NOOB_DEFAULT_HP, NOOB_DEFAULT_HP * 2, 500, NOOB_DEFAULT_SPEED, ARMOR_REFLECTIVE},
    {NULL, 60, NOOB_DEFAULT_HP * 2, NOOB_DEFAULT_HP, 500, NOOB_DEFAULT_SPEED, ARMOR_COMPOSITE | ARMOR_REFLECTIVE},
    {NULL, 70, NOOB_DEFAULT_HP * 2, NOOB_DEFAULT_HP, 500, NOOB_DEFAULT_SPEED, ARMOR_COMPOSITE},
    {NULL, 1, NOOB_DEFAULT_HP * 100, NOOB_DEFAULT_HP * 100, 0, NOOB_DEFAULT_SPEED / 2, ARMOR_COMPOSITE | ARMOR_REFLECTIVE}
};

// Define waves for level 2
static wave_t waves_level2[] = {
    {NULL, 10, NOOB_DEFAULT_HP * 5, NOOB_DEFAULT_HP, 500, NOOB_DEFAULT_SPEED / 2, 0},
    {NULL, 20, NOOB_DEFAULT_HP * 2, NOOB_DEFAULT_HP, 500, NOOB_DEFAULT_SPEED * 2, 0},
    {NULL, 40, NOOB_DEFAULT_HP * 5, NOOB_DEFAULT_HP, 500, NOOB_DEFAULT_SPEED, 0},
    {NULL, 50, NOOB_DEFAULT_HP * 6, NOOB_DEFAULT_HP, 500, NOOB_DEFAULT_SPEED, ARMOR_COMPOSITE}
};

// Initialize levels with waves
static level_t level1 = {NULL, {path1, sizeof(path1) / sizeof(*path1), 3, 6}, waves_level1};
static level_t level2 = {NULL, {path2, sizeof(path2) / sizeof(*path2), 2, 8}, waves_level2};

level_t *levels = &level1;

// Linking levels and waves
void link_levels_and_waves() {
    level1.next = &level2;
    level2.next = NULL;

    // Link waves within levels
    for (int i = 0; i < sizeof(waves_level1) / sizeof(wave_t) - 1; i++) {
        waves_level1[i].next = &waves_level1[i + 1];
    }
    waves_level1[sizeof(waves_level1) / sizeof(wave_t) - 1].next = NULL;

    for (int i = 0; i < sizeof(waves_level2) / sizeof(wave_t) - 1; i++) {
        waves_level2[i].next = &waves_level2[i + 1];
    }
    waves_level2[sizeof(waves_level2) / sizeof(wave_t) - 1].next = NULL;
}
