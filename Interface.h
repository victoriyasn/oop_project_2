#ifndef __INTERFACE_H
#define __INTERFACE_H
#include"ShapeCollection.h"

class Interface {
private:
	ShapeCollection iCollection;
	void printHelp();
public:
	void start();
};

#endif