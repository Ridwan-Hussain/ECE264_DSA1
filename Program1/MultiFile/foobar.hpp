#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Foobar { 
	int position;
	std::string name;
public:
	Foobar(std::string nam, int pos=0) {
		position = pos;
		name = nam;
	}
	void set_position(int pos) { 
		position = pos; 
	}	
	virtual int get_power() { return position;}
	std::string get_name() { return name; }
protected:
	int get_position() { return position; }
};

class Foo: public Foobar {
public:
	Foo(std::string nam, int pos=0) : Foobar(nam, pos) { }
	int get_power() { return get_position() * 3; }
};

class Bar: public Foobar {
public:
	Bar(std::string nam, int pos=0) : Foobar(nam, pos) { }
	int get_power() { return get_position() + 15; }
};
