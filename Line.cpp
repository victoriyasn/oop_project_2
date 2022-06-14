#include "Line.h"
#include<fstream>
using namespace std;

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

void Line::setEndAxisX(size_t newEndX) {
	endAxisX = newEndX;
}
void Line::setEndAxisY(size_t newEndY) {
	endAxisY = newEndY;
}
void Line::setStrokeWidth(size_t newStrokeWidth) {
	strokeWidth = newStrokeWidth;
}
size_t Line::getEndAxisX() const {
	return endAxisX;
}
size_t Line::getEndAxisY() const {
	return endAxisY;
}
size_t Line::getStrokeWidth()const {
	return strokeWidth;
}
bool Line::isWithinRect(size_t checkAxisX, size_t checkAxisY, size_t checkWidth, size_t checkHeight) const {
	bool isIn = false;

	if (getAxisX() >= checkAxisX && getAxisX() < (checkAxisX + checkWidth) && getAxisY() >= checkAxisY && getAxisY() < (checkAxisY + checkHeight)) {
		if (endAxisX < checkAxisX + checkWidth && endAxisY < checkAxisY + checkHeight) {
			isIn = true;
		}
	}

	return isIn;
}


bool Line::isWithinCircle(size_t checkAxisX, size_t checkAxisY, size_t checkRadius) const {
	return pointInCircle(checkAxisX, checkAxisY, checkRadius, getAxisX(), getAxisY())
		&& pointInCircle(checkAxisX, checkAxisY, checkRadius, endAxisX, endAxisY);
}

void Line::putInFile(ofstream & out) {
	// <line x1="900" y1="300" x2="1100" y2="100" stroke-width = "25" />
	out << "<line x1=\"" << getAxisX() << "\" y1=\"" << getAxisY() << "\" x2=\"" << endAxisX << "\" y2=\"" << endAxisY<<"\" stroke-width=\"" <<strokeWidth<< "\" />";

}
