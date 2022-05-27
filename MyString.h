#pragma once
#include<iostream>
using namespace std;

class MyString {
private:
	char* data;
	size_t size;
	void copyFrom(const MyString&);
	void freeMemory();
	
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString(MyString&&);
	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&);
	~MyString();
	void setString(const char*);
	MyString* clone() const;

	const char* getString() const;
	const size_t getSize() const;

	
	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>>(istream&, MyString&);

};
bool operator==(const MyString&, const MyString&);
bool operator<=(const MyString&, const MyString&);
bool operator>=(const MyString&, const MyString&);
bool operator<(const MyString&, const MyString&);
bool operator>(const MyString&, const MyString&);