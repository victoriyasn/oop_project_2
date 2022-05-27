#include "Line.h"

Shape* Line::clone() const {
	return new Line(*this);
}
void Line::print() {
	cout << "Line " << getAxisX() << " " << getAxisY() << " " << getWidth() << " " << getHeight() << " " << getColor() << endl;
}

void Line::translate(size_t addY, size_t addX) {
	setAxisX(getAxisX() + addX);
	setAxisY(getAxisY() + addY);
}

Line::Line(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const MyString& newColor) :
	Shape(newX, newY, newWidth, newHeight, newColor) {
}