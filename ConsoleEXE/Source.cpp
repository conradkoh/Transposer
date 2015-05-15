#include <iostream>
#include "StringMethods.h"

int main(){
	string x = "    hello how are      you    ";
	vector<string> tokens = StringMethods::TokenizeWithSpaces(x);
	string output = StringMethods::VectToStr(tokens);
	cout << output;
	system("pause");
}