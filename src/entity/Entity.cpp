#include <string>
#include "Entity.h"

enum EntityType { HOSTILE, FRIENDLY, PLAYER };

Entity::Entity(const string& name,
		double maxHealth,
		double protection,
		EntityType type,
		Location location)
	:
    	name(name),
		maxHealth(maxHealth),
		protection(protection),
		type(type),
		location(location),
		alive(true),
		health(maxHealth) {
}

string Entity::getName() {
	return name;
}

double Entity::getHealth() {
	return health > 0 ? health : 0;
}

double Entity::getProtection() {
	return protection;
}

bool Entity::isAlive() {
	return alive;
}

bool Entity::isDead() {
	return !alive;
}

Location Entity::getLocation() {
	return location;
}

void Entity::attack(Entity& entity, double damage) {
	entity.hit(*this, damage);
}

void Entity::addProtection(double protection) {
	protection = Entity::getProtection() + protection;
	if(protection > 1 || protection < 0) return;

	Entity::setProtection(protection);
}

void Entity::hit(Entity& damager, double damage) {
	if(!alive) return;

	damage = damage - (damage * damager.getProtection());
	health -= damage;
	alive = health > 0;
}

void Entity::setProtection(double protection) {
	this -> protection = protection;
}

void Entity::setHealth(double health) {
	this -> health = health;
}
