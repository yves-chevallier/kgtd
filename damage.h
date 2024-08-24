#pragma once

#include "tower_types.h"
#include "noob.h"
#include "bullet.h"

void damage_calc(bullet_t *bullet, int dt);
int damage_not_worthwhile(noob_t *noob, ttype_t type);
