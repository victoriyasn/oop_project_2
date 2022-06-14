#include "Rectangle.h"

Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}
void Rectangle::print() {
	cout << "Rectangle " << getAxisX() << " " << getAxisY() << " " << width << " " << height << " " << getColor() << endl;
}

void Rectangle::translate(size_t addY, size_t addX) {
	setAxisX(getAxisX() + addX);
	setAxisY(getAxisY() + addY);
}
Rectangle::Rectangle(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const MyString& newColor) :
	Shape(newX, newY, newColor) {
	width = newWidth;
	height = newHeight;

}

void Rectangle::setWidth(size_t newWidth) {
	width = newWidth;
}
void Rectangle::setHeight(size_t newHeight) {
	height = newHeight;
}

size_t Rectangle::getWidth() const {
	return width;
}
size_t Rectangle::getHeight() const {
	return height;
}
bool Rectangle::isWithinRect(size_t checkAxisX, size_t checkAxisY, size_t checkWidth, size_t checkHeight) const {
	bool isIn = false;

	if (getAxisX() >= checkAxisX && getAxisX() < (checkAxisX + checkWidth) && getAxisY() >= checkAxisY && getAxisY() < (checkAxisY + checkHeight)) {
		if ((getAxisX() + width) < checkAxisX + checkWidth && (getAxisY() + height) < checkAxisY + checkHeight) {
			isIn = true;
		}
	}

	return isIn;
}


bool Rectangle::isWithinCircle(size_t checkAxisX, size_t checkAxisY, size_t checkRadius) const {
	return pointInCircle(checkAxisX, checkAxisY, checkRadius, getAxisX(), getAxisY()) 
		&& pointInCircle(checkAxisX, checkAxisY, checkRadius, getAxisX() + width, getAxisY() + height);
}

void Rectangle::putInFile(ofstream& out) {
	// <rect x="5" y="5" width="10" height="10" fill="green" />
	out << "<rect x=\"" << getAxisX() << "\" y=\"" << getAxisY() << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << getColor() << "\" />";
}
