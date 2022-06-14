#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "ShapeBase.h"

class Circle : public Shape {
	size_t radius;
public:
	Circle() = default;
	Circle(size_t, size_t, size_t, const MyString&);
	void setRadius(size_t);
	size_t getRadius() const;
	Shape* clone() const override;
	void print() override;
	void translate(size_t, size_t) override;
	bool isWithinRect(size_t, size_t, size_t, size_t) const override;
	bool isWithinCircle(size_t, size_t, size_t) const override;
	void putInFile(ofstream&) override;
};

#endif