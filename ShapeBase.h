#ifndef __SHAPEBASE_H
#define __SHAPEBASE_H
#include<fstream>
#include "MyString.h"
using namespace std;

class Shape {
private:
	size_t axisX;
	size_t axisY;
	size_t width;
	size_t height;
	MyString color;
public:
	Shape();
	Shape(size_t, size_t, size_t, size_t, const MyString&);
	virtual ~Shape() = default;
	virtual Shape* clone() const = 0;
	virtual void print() = 0;
	virtual void translate(size_t, size_t) = 0;
	virtual bool isWithin(size_t, size_t, size_t, size_t) = 0;
	size_t getAxisX() const;
	size_t getAxisY() const;
	size_t getWidth() const;
	size_t getHeight() const;
	MyString getColor() const;
	void setAxisX(size_t);
	void setAxisY(size_t);
	void setWidth(size_t);
	void setHeight(size_t);
	void setColor(const MyString&);
};

#endif 
