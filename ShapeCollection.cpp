#include "ShapeCollection.h"
#include"ShapeBase.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
void ShapeCollection::copyFrom(const ShapeCollection& other) {
	size = other.size;
	capacity = other.capacity;
	collection = new Shape * [capacity];
	for (size_t i = 0; i < size; i++) {
		collection[i] = other.collection[i]->clone();
	}
}
void ShapeCollection::freeMemory() {
	for (size_t i = 0; i < size; i++) {
		delete collection[i];
	}
	delete[]collection;
}
void ShapeCollection::resize() {
	capacity *= 2;
	Shape** resizedCollection = new Shape * [capacity];
	for (size_t i = 0; i < size; i++) {
		resizedCollection[i] = collection[i];
	}
	delete[]collection;
	collection = resizedCollection;
}
void ShapeCollection::addShape(Shape* newShape) {
	if (size == capacity) resize();
	if(newShape != nullptr)
	collection[size++] = newShape;
}

ShapeCollection::ShapeCollection() {
	capacity = 10;
	size = 0;
	collection = new Shape * [capacity];
}
ShapeCollection::ShapeCollection(const ShapeCollection& other) {
	copyFrom(other);
}
ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
ShapeCollection::~ShapeCollection() {
	freeMemory();
}

void ShapeCollection::printShapes() {
	size_t count = 1;
	for (size_t i = 0; i < size; i++) {
		cout << count << ". ";
		collection[i]->print();
		count++;
	}
}

void ShapeCollection::translateShapes(size_t addY, size_t addX, size_t index ) {
	if (index <= size) {
		if (index != 0) {
			collection[index]->translate(addY, addX);
		}
		else {
			for (size_t i = 0; i < size; i++) {
				collection[i]->translate(addY, addX);
			}
		}
	}
	
}

void ShapeCollection::addCircle(size_t newX, size_t newY, size_t newRadius, const MyString& newColor) {
	if (size == capacity) resize();
	Circle* newCircle = new Circle(newX, newY, newRadius, newColor);
	addShape(newCircle);

}
void ShapeCollection::addRectangle(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const MyString& newColor) {
	if (size == capacity) resize();
	Rectangle* newRectangle = new Rectangle(newX, newY, newWidth, newHeight, newColor);
	addShape(newRectangle);

}
void ShapeCollection::addLine(size_t newX, size_t newY, size_t newEndAxisX, size_t newEndAxisY, size_t newStrokeWidth, const MyString& newColor) {
	if (size == capacity) resize();
	Line* newLine = new Line(newX, newY, newEndAxisX, newEndAxisY, newStrokeWidth, newColor);
	addShape(newLine);

}

void ShapeCollection::removeShape(size_t index) {
	if (index > size) cout << "Invalid input!";
	else {
		delete collection[index-1];
		for (size_t i = index; i < size-1; i++) {
			collection[i] = collection[i + 1];
		}
		size--;
		cout << "Erased figure num." << index << endl;
	}
}

void ShapeCollection::shapesWithinRectangle(size_t checkAxisX , size_t checkAxisY, size_t checkWidth, size_t checkHeight) {
	size_t count = size;
	for (size_t i = 0; i < size; i++) {
		if (collection[i]->isWithinRect(checkAxisX, checkAxisY, checkWidth, checkHeight)) {
			collection[i]->print();
			count--;
		}
	}
	if(count==size) cout<<"No figures are located within the rectangle!"<<endl;
}
void ShapeCollection::shapesWithinCircle(size_t checkAxisX, size_t checkAxisY, size_t checkRadius) {
	size_t count = size;
	for (size_t i = 0; i < size; i++) {
		if (collection[i]->isWithinCircle(checkAxisX, checkAxisY, checkRadius)) {
			collection[i]->print();
			count--;
		}
	}
	if (count == size) cout << "No figures are located within the circle!" << endl;
}

int validateBegText(ifstream& in) {
	char buff[1024];
	bool invalid = false;
	in.getline(buff, 1024);
	if (strcmp(buff, "<?xml version=\"1.0\" standalone=\"no\"?> ") == 0) {
		
		in.getline(buff, 1024);
		if (strcmp(buff, " <!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ") == 0) {
			in.getline(buff, 1024);
			if (strcmp(buff, " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\" > ") == 0) {
				in.getline(buff, 1024);
				if (strcmp(buff, "<svg> ") == 0) {
					return in.tellg();
					}
					else invalid = true;
				}
				else invalid = true;
			}
			else invalid = true;
		}
	else invalid = true;
	
	if (invalid) cout << "Theres invalid information!" << endl;

	return in.tellg();
}


Rectangle readRect(ifstream& in) {
	char buff[1028];
	Rectangle r;
	char ch;
	in.getline(buff, 1028, '\"');
	if (strcmp(buff, "x=") == 0) {
		in.getline(buff, 1028, '\"');
		r.setAxisX(atoi(buff));
		in.ignore();
		in.getline(buff, 1028, '\"');

		if (strcmp(buff, "y=") == 0) {
			in.getline(buff, 1028, '\"');
			r.setAxisY(atoi(buff));
			in.ignore();
			in.getline(buff, 1028, '\"');

			if (strcmp(buff, "width=") == 0) {
				in.getline(buff, 1028, '\"');
				r.setWidth(atoi(buff));
				in.ignore();
				in.getline(buff, 1028, '\"');

				if (strcmp(buff, "height=") == 0) {
					in.getline(buff, 1028, '\"');
					r.setHeight(atoi(buff));
					in.ignore();
					in.getline(buff, 1028, '\"');

					if (strcmp(buff, "fill=") == 0) {
						in.getline(buff, 1028, '\"');
						r.setColor(buff);
						
						
					}
				}
			}
		}
	}

	return r;

}
Circle readCircle(ifstream& in) {
	char buff[1028];
	char ch;
	Circle c;
	in.getline(buff, 1028, '\"');
		if (strcmp(buff, "cx=") == 0) {
			in.getline(buff, 1028, '\"');
			c.setAxisX(atoi(buff));
			in.ignore();
			in.getline(buff, 1028, '\"');
	
			if (strcmp(buff, "cy=") == 0) {
				in.getline(buff, 1028, '\"');
				c.setAxisY(atoi(buff));
				in.ignore();
				in.getline(buff, 1028, '\"');

				if (strcmp(buff, "r=") == 0) {
					in.getline(buff, 1028, '\"');
					c.setRadius(atoi(buff));
					in.ignore();
					in.getline(buff, 1028, '\"');
					
					if (strcmp(buff, "fill=") == 0) {
						in.getline(buff, 1028, '\"');
						c.setColor(buff);
						
					}
				}
			}
		}
	
	return c;
}
Line readLine(ifstream& in) {
	char buff[1028];
	char ch;
	Line l;
		in.getline(buff, 1028, '\"');
		if (strcmp(buff, "x1=") == 0) {
			in.getline(buff, 1028, '\"');
			l.setAxisX(atoi(buff));
			in.ignore();
			in.getline(buff, 1028, '\"');

			if (strcmp(buff, "y1=") == 0) {
				in.getline(buff, 1028, '\"');
				l.setAxisY(atoi(buff));
				in.ignore();
				in.getline(buff, 1028, '\"');

				if (strcmp(buff, "x2=") == 0) {
					in.getline(buff, 1028, '\"');
					l.setEndAxisX(atoi(buff));
					in.ignore();
					in.getline(buff, 1028, '\"');

					if (strcmp(buff, "y2=") == 0) {
						in.getline(buff, 1028, '\"');
						l.setEndAxisY(atoi(buff));
						in.ignore();
						in.getline(buff, 1028, '\"');

						if (strcmp(buff, "stroke-width = ") == 0) {
							in.getline(buff, 1028, '\"');
							l.setStrokeWidth(atoi(buff));
							
						}
					}
				}
			}
		}

		return l;
}
void ShapeCollection::readFromFileCollection(ifstream& in) {
	
	char ch;
	char buff[1028];
	bool timeToExit = false;
	int curr = validateBegText(in);
	if (curr != -1) {
		do {
			in.get(ch);
			if (ch == '<') {
				
				in.getline(buff, 1028, ' ');
				if (strcmp(buff, "rect") == 0) {
					Rectangle newRect = readRect(in);
					addRectangle(newRect.getAxisX(), newRect.getAxisY(), newRect.getWidth(), newRect.getHeight(), newRect.getColor());
					in.ignore();
					in.ignore();
				}
				else if (strcmp(buff, "circle") == 0) {
					Circle newCircle = readCircle(in);
					addCircle(newCircle.getAxisX(), newCircle.getAxisY(), newCircle.getRadius(), newCircle.getColor());
					in.ignore();
					in.ignore();
				}
				else if (strcmp(buff, "line") == 0) {
					Line newLine = readLine(in);
					addLine(newLine.getAxisX(), newLine.getAxisY(), newLine.getEndAxisX(), newLine.getEndAxisY(), newLine.getStrokeWidth(), "Unknown");
					in.ignore();
					in.ignore();
				}
				else timeToExit = true;

			}

		} while (timeToExit == false);
	}
	else cout << "There's a problem with the file" << endl;
}
void ShapeCollection::putInFileCollection(ofstream& out) {
	out<<"<?xml version=\"1.0\" standalone=\"no\"?> \n <!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \n \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\" > \n";
	out << "<svg> \n";
	for (size_t i = 0; i < size;i++) {
		collection[i]->putInFile(out);
		out << "\n";
	}
	out << "</svg> \n";

	
}