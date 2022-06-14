#ifndef __LINE_H
#define __LINE_H
#include "ShapeBase.h"

class Line : public Shape {
	size_t endAxisX;
	size_t endAxisY;
	size_t strokeWidth;
public:
	Line() = default;
	Line(size_t, size_t, size_t, size_t, size_t, const MyString&);
	void setEndAxisX(size_t);
	void setEndAxisY(size_t);
	void setStrokeWidth(size_t);
	size_t getEndAxisX() const;
	size_t getEndAxisY() const;
	size_t getStrokeWidth()const;
	Shape* clone() const override;
	void print() override;
	void translate(size_t, size_t) override;
	bool isWithinRect(size_t, size_t, size_t, size_t) const override;
	bool isWithinCircle(size_t, size_t, size_t) const override;
	void putInFile(ofstream&) override;

};
#endif