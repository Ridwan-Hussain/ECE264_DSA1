/* Things to-do
 * Open File
 * Count # of lines in the file <== len_line
 * Read the input to see if the item is Foobar, foo, or bar. Place that into the correct class, with the name * correct position # (len_line - index + 1)
 * After putting it into the class, do total_power += get_pow()
 * print it and add it to an array/multidim array/vector w/ the item name & power
 * 	Put this into an output file
 *
 * For the class:
 * 	Super Class FooBar
 * 		int name, pow, pos
 * 	public:
 * 		Foobar(name, pos) // constructor
 * 		get_name();
 * 		get_pow();
 *
 * 	Subclass Foo:
 * 		same
 * 	public:
 * 		same
 * 		same
 * 		get_pow() = pos*3;
 * 	...
 */

#include <iostream>
#include <string>
#include <classes>

int main() {
	std::cout << "Hello World" << "\n";
	std::string dummy = "Hello World 2";
	std::cout << dummy << "\n";
	Foobar test = Foobar(3, "dummy");
	std::cout << test.get_pow() << "\n";
	return 0;
}
