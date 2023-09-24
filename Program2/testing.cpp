#include <string>
//#include <regex>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string testing = "This is a line\n";
	string testing2 = "This is\nTwo lines\n";
	string testing3 = "This is new line\n";
	//regex newlines_re("\n+");

	cout << testing << "-----------------------------\n" << testing2 << "-----------------------------\n" << testing3 << "-----------------------------\n";  

	/*testing = regex_replace(testing, newlines_re, "");
	testing2 = regex_replace(testing2, newlines_re, "");
	testing3 = regex_replace(testing3, newlines_re, "");*/

	/*testing.erase(remove(testing.begin(), testing.end(), "\n"), testing.end());
	testing2.erase(remove(testing2.begin(), testing2.end(), "\n"), testing2.end());
	testing3.erase(remove(testing3.begin(), testing3.end(), "\n"), testing3.end());*/

	testing = testing.substr(0, testing.length());
	testing2 = testing2.substr(0, testing2.length());
	testing3 = testing3.substr(0, testing3.length());

	cout << testing << "-----------------------------\n" << testing2 << "-----------------------------\n" << testing3 << "-----------------------------\n";  

	return 0;
}
