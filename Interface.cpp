#include"Interface.h"
#include <fstream>
#include<iostream>
using namespace std;
void Interface::printHelp() {

	cout << "The commands are: " << endl;
	cout << "Open <file> - opens a file" << endl;
	cout << "Close - closes current file" << endl;
	cout << "Save - saves the current file" << endl;
	cout << "SaveAs <file> - saves the current file in <file>" << endl;
	cout << "Help - prints this information" << endl;
	cout << "Exit - exits the program" << endl;
	cout << "Print - prints all the shapes" << endl;
	cout << "Create - creates a new figure" << endl;
	cout << "Erase <index> - removes a figure form given index"<<endl;
	cout << "Translate <index> - translates the figure at given index, if index is not given translates all figures" << endl;
	cout << "Within <option> - prints all the figures with a region (by <option> you choose whether the region is a circle or a rectangle)" << endl;
}

void Interface::start() {
	char command[128];
	char fileName[128];
	strcpy_s(fileName, 9, "Unknown");
	bool closeTime = false;
	bool closedFile = true;
	bool thereIsChange = false;

	do {
		cin.getline(command, 128);
		if (strcmp(command, "Help") == 0) printHelp();
		if (strcmp(command, "Exit") == 0) {
			closeTime = true;
			if (thereIsChange) {
				cout << "Don't forget to save the changes you made with commands Save and SaveAs" << endl;
			}
		} 
		if (strcmp(command, "Open") == 0) {
		cin.getline(fileName, 128);
		ifstream inFile(fileName);
		closedFile = false;
		iCollection.readFromFileCollection(inFile);
		cout << "Successfully read info from file: " << fileName << endl;
		inFile.close();
		}
		//clean the information?
		if (strcmp(command, "Close") == 0) {
			closedFile = true;
		}
		if (strcmp(command, "Save") == 0) {
			thereIsChange = false;
			if (closedFile == false) {
				if (strcmp(fileName, "Unknown") != 0) {
					ofstream outFile(fileName);
					iCollection.putInFileCollection(outFile);
					outFile.close();
					cout << "Succesfully put in file with the name:" << fileName << endl;
				}
				else cout << "There isn't an open file" << endl;
			}
			else cout << "File is currently closed you can only open files rn"<<endl;
			
		}
		if (strcmp(command, "SaveAs") == 0) {
			thereIsChange = false;
			if (closedFile == false) {
				char newFileName[128];
				cin.getline(newFileName, 128);
				ofstream outFile(newFileName);
				iCollection.putInFileCollection(outFile);
				outFile.close();
				cout << "Succesfully put in file with the name:" << newFileName << endl;
			} else cout << "File is currently closed you can only open files rn" << endl;
		}
		if (strcmp(command, "Print") == 0) iCollection.printShapes();
		if (strcmp(command, "Create") == 0) {
			thereIsChange = true;
			cin.getline(command, 128);
			if (strcmp(command, "Circle") == 0) {
				cin.getline(command, 128);
				size_t axisX = atoi(command);
				cin.getline(command, 128);
				size_t axisY = atoi(command);
				cin.getline(command, 128);
				size_t radius = atoi(command);
				cin.getline(command, 128);
				MyString color;
				color.setString(command);
				iCollection.addCircle(axisX, axisY, radius, color);
				cout << "Succesfully created a circle!" << endl;
			}
			else if (strcmp(command, "Rectangle") == 0) {
				cin.getline(command, 128);
				size_t axisX = atoi(command);
				cin.getline(command, 128);
				size_t axisY = atoi(command);
				cin.getline(command, 128);
				size_t height = atoi(command);
				cin.getline(command, 128);
				size_t width = atoi(command);
				cin.getline(command, 128);
				MyString color;
				color.setString(command);
				iCollection.addRectangle(axisX, axisY, height, width, color);
				cout << "Succesfully created a rectangle!" << endl;
			}
			else if (strcmp(command, "Line") == 0) {
				cin.getline(command, 128);
				size_t axisX = atoi(command);
				cin.getline(command, 128);
				size_t axisY = atoi(command);
				cin.getline(command, 128);
				size_t endAxisX = atoi(command);
				cin.getline(command, 128);
				size_t endAxisY = atoi(command);
				cin.getline(command, 128);
				size_t stroke = atoi(command);
				cin.getline(command, 128);
				MyString color;
				color.setString(command);
				iCollection.addLine(axisX, axisY, endAxisX, endAxisY, stroke, color);
				cout << "Succesfully created a line!" << endl;
			}
			else cout << "Invalid Input" << endl;
		}
		if (strcmp(command, "Erase") == 0) {
			thereIsChange = true;
			cin.getline(command, 128);
			size_t index = atoi(command);
			iCollection.removeShape(index);
		}
		if (strcmp(command, "Translate") == 0) {
			thereIsChange = true;
			cin.getline(command, 128);
			size_t vertical = atoi(command);
			cin.getline(command, 128);
			size_t horizontal = atoi(command);
			iCollection.translateShapes(vertical, horizontal, 0);
			cout << "Translated!" << endl;
		}
		if (strcmp(command, "Within") == 0) {
			cin.getline(command, 128);
			if (strcmp(command, "Rectangle") == 0) {
				cin.getline(command, 128);
				size_t axisX = atoi(command);
				cin.getline(command, 128);
				size_t axisY = atoi(command);
				cin.getline(command, 128);
				size_t width = atoi(command);
				cin.getline(command, 128);
				size_t height = atoi(command);
				iCollection.shapesWithinRectangle(axisX, axisY, width, height);
			}
			else if (strcmp(command, "Circle") == 0) {
				cin.getline(command, 128);
				size_t axisX = atoi(command);
				cin.getline(command, 128);
				size_t axisY = atoi(command);
				cin.getline(command, 128);
				size_t radius = atoi(command);
				iCollection.shapesWithinCircle(axisX, axisY, radius);
			}
			else cout << "Invalid input!" << endl;
		}
	} while (closeTime != true);

}