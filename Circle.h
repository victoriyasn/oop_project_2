#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "ShapeBase.h"

class Circle : public Shape {
public:
	Circle(size_t, size_t, size_t, size_t, const MyString&);
	Shape* clone() const override;
	void print() override;
	void translate(size_t, size_t) override;
	bool isWithin(size_t, size_t, size_t, size_t) override;
};

#endif