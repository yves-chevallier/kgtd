#pragma once

#include "bullet.h"

void tower_upd_normal(tower_t *tower, int dt);
void tower_upd_cw(tower_t *tower, int dt);

void bullet_upd_cw(bullet_t *bullet, float dt, int idt);
void bullet_upd_proj(bullet_t *bullet, float dt, int idt);
void bullet_upd_pulse(bullet_t *bullet, float dt, int idt);

void bullet_draw_proj(bullet_t *bullet);
void bullet_draw_beam(bullet_t *bullet);
void bullet_draw_area(bullet_t *bullet);
