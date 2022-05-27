#include "ShapeBase.h"

Shape::Shape() {
	axisX = 0;
	axisY = 0;
	width = 0;
	height = 0;
	color.setString("Unknown");
}
Shape::Shape(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const MyString& newColor) {
	axisX = newX;
	axisY = newY;
	width = newWidth;
	height = newHeight;
	color = newColor;
}

size_t Shape::getAxisX() const {
	return axisX;
}
size_t Shape::getAxisY() const {
	return axisY;
}
size_t Shape::getWidth() const {
	return width;
}
size_t Shape::getHeight() const {
	return height;
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
void Shape::setWidth(size_t newWidth)  {
	width = newWidth;
}
void Shape::setHeight(size_t newHeight)  {
	height = newHeight;
}
void Shape::setColor(const MyString& newColor)  {
	color = newColor;
}