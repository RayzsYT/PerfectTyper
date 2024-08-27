# include "cmath"
# include "Location.h"

Location::Location(int x, int y) {
	this -> x = x;
	this -> y = y;
}

double Location::distance(Location location) {
	double dX = location.x - this -> x,
		   dY = location.y - this -> y;

	return sqrt((dX * dX) + (dY * dY));
}
