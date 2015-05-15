#pragma once
#include <sstream>
#include <vector>
using namespace std;
class StringMethods
{
public:
	static vector<string> TokenizeWithSpaces(string input);
	static string VectToStr(vector<string> input);
	static string ReplaceStr(string input, string to_replace, string replacer);
};

