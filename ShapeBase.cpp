#include "ShapeBase.h"

Shape::Shape() {
	axisX = 0;
	axisY = 0;
	color.setString("Unknown");
}
Shape::Shape(size_t newX, size_t newY,  const MyString& newColor) {
	axisX = newX;
	axisY = newY;
	color = newColor;
}

size_t Shape::getAxisX() const {
	return axisX;
}
size_t Shape::getAxisY() const {
	return axisY;
}

MyString Shape::getColor() const {
	return color;
}
void Shape::setAxisX(size_t newX) {
	axisX = newX;
}
void Shape::setAxisY(size_t newY)  {
	axisY = newY;
}

void Shape::setColor(const MyString& newColor)  {
	color = newColor;
}