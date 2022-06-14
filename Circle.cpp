#include "Circle.h"
#include<fstream>
using namespace std;
Shape* Circle::clone() const {
	return new Circle(*this);
}
void Circle::print() {
	cout << "Circle " << getAxisX() << " " << getAxisY() << " " << radius << " " << getColor() << endl;
}

void Circle::translate(size_t addY, size_t addX) {
	setAxisX(getAxisX() + addX);
	setAxisY(getAxisY() + addY);
}
Circle::Circle(size_t newX, size_t newY, size_t newRadius, const MyString& newColor) :
	Shape(newX, newY, newColor) {
	radius = newRadius;
}
void Circle::setRadius(size_t newRad) {
	radius = newRad;
}
size_t Circle::getRadius() const {
	return radius;
}

bool Circle::isWithinRect(size_t checkAxisX, size_t checkAxisY, size_t checkWidth, size_t checkHeight) const {
	bool isIn = false;

	if (getAxisX() >= checkAxisX && getAxisX() < (checkAxisX + checkWidth) && getAxisY() >= checkAxisY && getAxisY() < (checkAxisY + checkHeight)) {
		if ((getAxisX() + radius) < checkAxisX + checkWidth && (getAxisY() + radius) < checkAxisY + checkHeight) {
			isIn = true;
		}
	}

	return isIn;
}


bool Circle::isWithinCircle(size_t checkAxisX, size_t checkAxisY, size_t checkRadius) const {
	return pointInCircle(checkAxisX, checkAxisY, checkRadius, getAxisX()+ radius, getAxisY())
		&& pointInCircle(checkAxisX, checkAxisY, checkRadius, getAxisX(), getAxisY() + radius);
}

void Circle::putInFile(ofstream& out) {
	// <circle cx="5" cy="5" r="10" fill="blue" />
	out << "<circle cx=\"" << getAxisX() << "\" cy=\"" << getAxisY() << "\" r=\"" << radius << "\" fill=\"" << getColor() << "\" />";
}