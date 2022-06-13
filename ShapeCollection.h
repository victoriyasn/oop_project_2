#ifndef __SHAPECOLLECTION_H
#define __SHAPECOLLECTION_H
#include "ShapeBase.h"

class ShapeCollection {
private:
	Shape** collection;
	size_t size;
	size_t capacity;
	void copyFrom(const ShapeCollection&);
	void freeMemory();
	void resize();
	void addShape(Shape*);
public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection&);
	ShapeCollection& operator=(const ShapeCollection&);
	~ShapeCollection();
	void printShapes();
	void translateShapes(size_t, size_t, size_t);
	void addCircle(size_t, size_t, size_t,const MyString&);
	void addRectangle(size_t, size_t, size_t, size_t,const MyString&);
	void addLine(size_t, size_t, size_t, size_t, size_t,  const MyString&);
	void removeShape(size_t);
};

#endif 
