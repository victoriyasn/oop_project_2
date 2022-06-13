#include "ShapeCollection.h"
#include"ShapeBase.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
void ShapeCollection::copyFrom(const ShapeCollection& other) {
	size = other.size;
	capacity = other.capacity;
	collection = new Shape * [capacity];
	for (size_t i = 0; i < size; i++) {
		collection[i] = other.collection[i]->clone();
	}
}
void ShapeCollection::freeMemory() {
	for (size_t i = 0; i < size; i++) {
		delete collection[i];
	}
	delete[]collection;
}
void ShapeCollection::resize() {
	capacity *= 2;
	Shape** resizedCollection = new Shape * [capacity];
	for (size_t i = 0; i < size; i++) {
		resizedCollection[i] = collection[i];
	}
	delete[]collection;
	collection = resizedCollection;
}
void ShapeCollection::addShape(Shape* newShape) {
	if (size == capacity) resize();
	if(newShape != nullptr)
	collection[size++] = newShape;
}

ShapeCollection::ShapeCollection() {
	capacity = 10;
	size = 0;
	collection = new Shape * [capacity];
}
ShapeCollection::ShapeCollection(const ShapeCollection& other) {
	copyFrom(other);
}
ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
ShapeCollection::~ShapeCollection() {
	freeMemory();
}

void ShapeCollection::printShapes() {
	size_t count = 1;
	for (size_t i = 0; i < size; i++) {
		cout << count << ". ";
		collection[i]->print();
		count++;
	}
}

void ShapeCollection::translateShapes(size_t addY, size_t addX, size_t index = 0) {
	if (index <= size) {
		if (index != 0) {
			collection[index]->translate(addY, addX);
		}
		else {
			for (size_t i = 0; i < size; i++) {
				collection[i]->translate(addY, addX);
			}
		}
	}
	
}

void ShapeCollection::addCircle(size_t newX, size_t newY, size_t newRadius, const MyString& newColor) {
	if (size == capacity) resize();
	Circle* newCircle = new Circle(newX, newY, newRadius, newColor);
	addShape(newCircle);
}
void ShapeCollection::addRectangle(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const MyString& newColor) {
	if (size == capacity) resize();
	Rectangle* newRectangle = new Rectangle(newX, newY, newWidth, newHeight, newColor);
	addShape(newRectangle);
}
void ShapeCollection::addLine(size_t newX, size_t newY, size_t newEndAxisX, size_t newEndAxisY, size_t newStrokeWidth, const MyString& newColor) {
	if (size == capacity) resize();
	Line* newLine = new Line(newX, newY, newEndAxisX, newEndAxisY, newStrokeWidth, newColor);
	addShape(newLine);
}

void ShapeCollection::removeShape(size_t index) {
	if (index > size) cout << "Invalid input!";
	else {
		delete collection[index];
		for (size_t i = index; i < size - 1; i++) {
			collection[i] = collection[i + 1];
		}
		size--;
	}
}