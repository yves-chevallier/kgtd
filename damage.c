#include "damage.h"

#if 0
/* all are /128 */
static int damage_table[][] = {
	{}, /* ATTR_MASS_KINETIC */
	{}, /* ATTR_MASS_KINETIC_APCR */
	{}, /* ATTR_MASS_KINETIC_APFSDS */
	{}, /* ATTR_MASS_KINETIC_DU */
};
#endif

void damage_calc(noob_t *noob, int damage, int dt, attr_t attr)
{
	switch(attr) {
	case ATTR_MASS_KINETIC:
	case ATTR_MASS_KINETIC_APCR:
	case ATTR_MASS_KINETIC_APFSDS:
	case ATTR_MASS_KINETIC_DU:
	case ATTR_MASS_EXPLOSIVE_HE:
	case ATTR_MASS_EXPLOSIVE_HEAT:
		noob->hp -= damage;
		break;
	case ATTR_MASS_EXPLOSIVE_HESH:
	case ATTR_ENERGY_LASER_PULSE:
		noob->hp -= damage;
		break;
	case ATTR_ENERGY_PARTICLE_LIGHTNING:
		noob->stun_time = 50;
	case ATTR_ENERGY_PARTICLE_PLASMA:
	case ATTR_ENERGY_LASER_CW:
		noob->hp -= (damage * dt) / 1000;
		break;
	case ATTR_NONE:
		printf("ATTR_NONE: fail?\n");
	}

}

int damage_not_worthwhile(noob_t *noob, attr_t attr)
{
	if(noob == NULL || noob->hp <= 0 || noob->is_dead ||
	   ((noob->future_stun || noob->stun_time) &&
	    attr == ATTR_ENERGY_PARTICLE_LIGHTNING))
		return 1;

	return 0;
}

