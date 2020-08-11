#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
	int i = 4;
	std::string s = "four";
	std::vector<int> v;
	std::map<int,std::string> m;
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	m.insert(std::make_pair(2,"two"));
	m.insert(std::make_pair(1,"one"));
	m.insert(std::make_pair(3,"three"));
	return 0;
}