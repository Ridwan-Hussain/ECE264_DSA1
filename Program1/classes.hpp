#include <string>

class Foobar { 
	int position, power;
	std::string name;
public:
	Foobar(std::string nam, int pos=0) {
		position = pos;
		power = pos;
		name = nam;
	}
	virtual int get_power() { return power;}
	std::string get_name() { return name; }
protected:
	int get_position() { return position; }
};

class Foo: public Foobar {
	int position, power;
	std::string name;
public:
	Foo(std::string nam, int pos=0) : Foobar(nam, pos) {
		position = pos;
		power = pos * 3;
		name = nam;
	}
};

class Bar: public Foobar {
	int position, power;
	std::string name;
public:
	Bar(std::string nam, int pos=0) : Foobar(nam, pos) {
		position = pos;
		power = pos + 15;
		name = nam;
	}
};
