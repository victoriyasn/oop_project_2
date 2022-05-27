#ifndef __LINE_H
#define __LINE_H
#include "ShapeBase.h"

class Line : public Shape {
public:
	Line(size_t, size_t, size_t, size_t, const MyString&);
	Shape* clone() const override;
	void print() override;
	void translate(size_t, size_t) override;
	bool isWithin(size_t, size_t, size_t, size_t) override;
};
#endif