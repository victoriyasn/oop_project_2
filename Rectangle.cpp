#include "Rectangle.h"

Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}
void Rectangle::print() {
	cout << "Rectangle " << getAxisX() << " " << getAxisY() << " " << getWidth() << " " << getHeight() << " " << getColor() << endl;
}

void Rectangle::translate(size_t addY, size_t addX) {
	setAxisX(getAxisX() + addX);
	setAxisY(getAxisY() + addY);
}
Rectangle::Rectangle(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const MyString& newColor) :
	Shape(newX, newY, newWidth, newHeight, newColor) {
}

bool Rectangle::isWithin(size_t checkAxisX, size_t checkAxisY, size_t checkWidth, size_t checkHeight) {
	bool isIn = false;

	if (getAxisX() >= checkAxisX && getAxisX() < (checkAxisX + checkWidth) && getAxisY() >= checkAxisY && getAxisY() < (checkAxisY + checkHeight)) {
		if ((getAxisX() + getWidth()) < checkAxisX + checkWidth && (getAxisY() + getHeight()) < checkAxisY + checkHeight) {
			isIn = true;
		}
	}

	return isIn;
}