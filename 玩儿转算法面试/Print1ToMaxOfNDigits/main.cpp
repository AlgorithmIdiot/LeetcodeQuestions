#include"StringCalculation.h"
#include<vector>
#include<string>
int main() {
	std::vector<std::string> v;
	std::string str = "example is like this";
	auto m = str.find("pl");
	std::cout << str.substr(str.find("pl"));
	std::cin.get();

}