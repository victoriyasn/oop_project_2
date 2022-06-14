#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include "ShapeBase.h"

class Rectangle : public Shape {
	size_t width;
	size_t height;
public:
	Rectangle() = default;
	Rectangle(size_t, size_t, size_t, size_t, const MyString&);
	void setWidth(size_t);
	void setHeight(size_t);
	size_t getWidth() const;
	size_t getHeight() const;
	Shape* clone() const override;
	void print() override;
	void translate(size_t, size_t) override;
	bool isWithinRect(size_t, size_t, size_t, size_t) const override;
	bool isWithinCircle(size_t, size_t, size_t) const override;
	void putInFile(ofstream&) override;

};

#endif