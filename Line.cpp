#include "Line.h"

Shape* Line::clone() const {
	return new Line(*this);
}
void Line::print() {
	cout << "Line " << getAxisX() << " " << getAxisY() << " " << endAxisX << " " <<endAxisY << " " << getColor() << endl;
}

void Line::translate(size_t addY, size_t addX) {
	setAxisX(getAxisX() + addX);
	setAxisY(getAxisY() + addY);
}

Line::Line(size_t newX, size_t newY, size_t newEndAxisX, size_t newEndAxisY, size_t newStrokeWidth, const MyString& newColor) :
	Shape(newX, newY, newColor) {
	endAxisX = newEndAxisX;
	endAxisY = newEndAxisY;
	strokeWidth = newStrokeWidth;
}
bool Line::isWithinRect(size_t checkAxisX, size_t checkAxisY, size_t checkWidth, size_t checkHeight) {
	bool isIn = false;


	return isIn;
}