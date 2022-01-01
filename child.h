#ifndef CHILD_H_
#define CHILD_H_
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Child
{
public:

	Child();
	Child(string first_name, string last_name, int age);

	void set_child(string first_name, string last_name, int age);


	bool operator<(Child other_child);
	bool operator>(Child other_child);
	bool operator==(Child other_child);
	bool operator!=(Child other_child);
	bool operator<=(Child other_child);
	bool operator>=(Child other_child);
	friend ostream& operator<<(ostream& stream, Child& child);
	friend istream& operator>>(istream& stream, Child& child);

	string first_name_;
	string last_name_;
	int age_;

};

#endif // !CHILD_H_
