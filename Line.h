#ifndef __LINE_H
#define __LINE_H
#include "ShapeBase.h"

class Line : public Shape {
	size_t endAxisX;
	size_t endAxisY;
	size_t strokeWidth;
public:
	Line(size_t, size_t, size_t, size_t, size_t, const MyString&);
	Shape* clone() const override;
	void print() override;
	void translate(size_t, size_t) override;
	bool isWithinRect(size_t, size_t, size_t, size_t) override;
};
#endif