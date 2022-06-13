#include "Circle.h"

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