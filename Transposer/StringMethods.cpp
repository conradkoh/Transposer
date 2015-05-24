#include "StringMethods.h"
#include <iostream>
vector<string> StringMethods::TokenizeWithSpaces(string input){
	int startIdx = 0;
	int endIdx = 0;
	int found = 0;
	char firstchar = NULL;
	string word;
	string space;
	vector<string> output;
	if (input.length() > 0){
		firstchar = input[0];
	}
	if (firstchar != NULL){
		if (firstchar == ' '){
			endIdx = input.find_first_not_of(" ");
			int length = endIdx;
			space = input.substr(0, length);
			startIdx = endIdx + 1;
			output.push_back(space);
		}
	}
	istringstream in(input);

	string remainder = input;
	
	while (in >> word){
		output.push_back(word);

		//adding the spaces
		string buffer;
		istringstream in2(remainder);
		in2 >> buffer;
		remainder = ""; //clearing the buffer
		getline(in2, remainder);
		endIdx = remainder.find_first_not_of(" ");

		space = ""; //reintialization

		if (endIdx != string::npos){
			int length = endIdx;
			space = remainder.substr(0, length);
		}
		else{
			startIdx = remainder.find_first_of(" ");
			endIdx = remainder.find_last_of(" ");
			if (startIdx != string::npos && endIdx != string::npos){
				int length = endIdx - startIdx + 1;
				space = remainder.substr(startIdx, length);
			}
			
		}
		output.push_back(space);

	}

	return output;
}

string StringMethods::VectToStr(vector<string> input){
	vector<string>::iterator iter;
	ostringstream out;
	for (iter = input.begin(); iter != input.end(); ++iter){
		out << (*iter);
	}

	return out.str();
}

string StringMethods::ReplaceStr(string input, string to_replace, string replacer){
	int found = 0;
	int startIdx = 0;
	do{

		found = input.find(to_replace, startIdx);
		int length = to_replace.length();
		if (found != string::npos && to_replace != ""){
			input.replace(found, length, replacer);
			startIdx = found + replacer.length();
		}
		else{
			found = string::npos;
		}
	} while (found != string::npos);

	return input;
}

string StringMethods::RemoveNewlines(string input){
	string output = input;
	int found = 0;
	do{
		found = output.find_first_of("\n");
		if (found != string::npos){
			int length = output.length();
			string prefix = input.substr(0, found);
			string suffix = "";

			if (found + 1 < length){
				suffix = input.substr(found + 2, length - found);
			}
			output = prefix + suffix;
		}
	} while (found != string::npos);
	return output;

}