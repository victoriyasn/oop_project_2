#ifndef __SHAPECOLLECTION_H
#define __SHAPECOLLECTION_H
#include "ShapeBase.h"
#include<fstream>
using namespace std;

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
	void shapesWithinRectangle(size_t, size_t, size_t, size_t);
	void shapesWithinCircle(size_t, size_t, size_t);
	void readFromFileCollection(ifstream&);
	void putInFileCollection(ofstream&);
	void removeEverything();
};

#endif 
