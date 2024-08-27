# ifndef ENTITY_H
# define ENTITY_H

# include <string>
# include <functional>
# include "../world/Location.h"

using namespace std;

class Entity {

	public:

		enum EntityType {
			HOSTILE, FRIENDLY, PLAYER
		};

		Entity(const string& name, double maxHealth, double protection, enum EntityType type, Location location);

		void spawn();
		void onDeath(function<void()> action);

		void setHealth(double health);
		void hit(Entity& damager, double damage);
		void attack(Entity& entity, double damage);

		void addProtection(double protection);

		void setProtection(double protection);
		void setLocation(Location location);


		string getName();

		double getHealth();
		double getProtection();

		bool isAlive();
		bool isDead();

		Location getLocation();

	private:
		string name;

		bool alive;
		double health;
		double maxHealth;
		double protection;

		enum EntityType type;
		Location location;
};

# endif // ENTITY_H
