# ifndef LOCATION_H
# define LOCATION_H

class Location {

	public:
		Location(int x, int y);
		double distance(Location target);
		int getX();
		int getY();

	private:
		int x, y;
};

# endif // LOCATION_H
