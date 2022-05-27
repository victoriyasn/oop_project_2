#include "MyString.h"
#include<iostream>
#include<cstring>
using namespace std;

MyString* MyString::clone() const {
	return new MyString(*this);
}
void MyString::copyFrom(const MyString& other) {
	size = other.size;
	data = new char[size + 1];
	strcpy_s(data, size + 1, other.data);
}
void MyString::freeMemory() {
	delete[]data;
}

MyString::MyString() {
	size = 0;
	data = new char[1];
	data[0] = '\0';
}
MyString::MyString(const char* other) {
	if (other == nullptr) {
		size = 0;
		data = new char[1];
		data[0] = '\0';
	}
	else {
		size = strlen(other) ;
		data = new char[size + 1];
		strcpy_s(data, size + 1, other);
	}
	
}
MyString::MyString(const MyString& other) {
	copyFrom(other);
}
MyString::MyString(MyString&& other) {
	data = other.data;
	size = other.size;
	other.data = nullptr;
}
MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
MyString& MyString::operator=(MyString&& other) {
	if (this != &other) {
		freeMemory();
		data = other.data;
		size = other.size;
		other.data = nullptr;
	}
	return *this;
}
MyString::~MyString() {
	freeMemory();
}
void MyString::setString(const char* other) {
	size = strlen(other) + 1;
	data = new char[size];
	strcpy_s(data, size, other);
}

const char* MyString::getString() const {
	return data;
}
const size_t MyString::getSize() const {
	return size;
}

ostream& operator<<(ostream& out, const MyString& printStr) {
	out << printStr.getString();
	return out;
}
istream& operator>>(istream& in, MyString& inStr) {
	delete[]inStr.data;
	char temp[1024];
	in.getline(temp, 1024);
	inStr.setString(temp);
	return in;
}

bool operator==(const MyString& rhs, const MyString& lhs) {
	return strcmp(rhs.getString(), lhs.getString()) == 0;
}

bool operator<=(const MyString& rhs, const MyString& lhs) {
	return strcmp(rhs.getString(), lhs.getString()) <= 0;
}
bool operator>=(const MyString& rhs, const MyString& lhs) {
	return strcmp(rhs.getString(), lhs.getString()) >= 0;
}

bool operator<(const MyString& rhs, const MyString& lhs) {
	return strcmp(rhs.getString(), lhs.getString()) < 0;
}
bool operator>(const MyString& rhs, const MyString& lhs) {
	return strcmp(rhs.getString(), lhs.getString()) > 0;
}
