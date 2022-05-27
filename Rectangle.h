#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include "ShapeBase.h"

class Rectangle : public Shape {
public:
	Rectangle(size_t, size_t, size_t, size_t, const MyString&);
	Shape* clone() const override;
	void print() override;
	void translate(size_t, size_t) override;
	bool isWithin(size_t, size_t, size_t, size_t) override;
};

#endif