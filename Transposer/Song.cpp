#include "Song.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//enum KEY { C, D, E, F, G, A, B, INVALID };
const string Song::songDIR = ".\\Songs\\";
const string Song::saveDIR = ".\\Saved\\";

string Song::notes[12];
string Song::notes_alias[12];


Song::Song(void)
{
	Initialize();
}

Song::Song(string filename)
{
	Initialize();
	FILENAME = filename;
	title_visible = filename;

	ifstream lyricStream(songDIR + filename.c_str());
	int count = 1;
	string currentLine;
	while (getline(lyricStream, currentLine)){		
		if(count%2 == 1){
			chords.push_back(currentLine);
		}

		else{
			lyrics.push_back(currentLine);
		}
		lineCount = lyrics.size();
		count++;
	}
	lyricStream.close();
}

Song::~Song(void)
{
}

void Song::Initialize(){
	if (!isInitalized){
		notes[Song::NOTES::C1] = "C";
		notes[Song::NOTES::C2] = "C#";
		notes[Song::NOTES::D1] = "D";
		notes[Song::NOTES::D2] = "Eb";
		notes[Song::NOTES::E1] = "E";
		notes[Song::NOTES::F1] = "F";
		notes[Song::NOTES::F2] = "F#";
		notes[Song::NOTES::G1] = "G";
		notes[Song::NOTES::G2] = "G#";
		notes[Song::NOTES::A1] = "A";
		notes[Song::NOTES::A2] = "Bb";
		notes[Song::NOTES::B1] = "B";

		notes_alias[Song::NOTES::C1] = "B#";
		notes_alias[Song::NOTES::C2] = "Db";
		notes_alias[Song::NOTES::D1] = "D";
		notes_alias[Song::NOTES::D2] = "D#";
		notes_alias[Song::NOTES::E1] = "Fb";
		notes_alias[Song::NOTES::F1] = "E#";
		notes_alias[Song::NOTES::F2] = "Gb";
		notes_alias[Song::NOTES::G1] = "G";
		notes_alias[Song::NOTES::G2] = "Ab";
		notes_alias[Song::NOTES::A1] = "A";
		notes_alias[Song::NOTES::A2] = "A#";
		notes_alias[Song::NOTES::B1] = "Cb";
		
		isInitalized = true;
	}
}

void Song::transpose(KEY startKEY, KEY endKEY){
	title_visible = StringMethods::ReplaceStr(title_visible, "(", "( ");
	title_visible = StringMethods::ReplaceStr(title_visible, ")", " )");
	title_visible = TransposeStr(title_visible, startKEY, endKEY);
	title_visible = StringMethods::ReplaceStr(title_visible, "( ", "(");
	title_visible = StringMethods::ReplaceStr(title_visible, " )", ")");
	for(int i = 0; i<lineCount; i++){
		string lyricline = StringMethods::ReplaceStr(lyrics[i], "	", "         ");
		string chordline = StringMethods::ReplaceStr(chords[i], "	", "         ");
		lyrics[i] = TransposeStr(lyricline, startKEY, endKEY);
		chords[i] = TransposeStr(chordline, startKEY, endKEY);
	}
}

string Song::TransposeStr(string input, KEY startKEY, KEY endKEY){
	string currentLine;
	string output;
	istringstream in(input);
	while (getline(in, currentLine)){
		istringstream line(currentLine);
		vector<string> lineChords;
	/*	string chord;
		while (line >> chord){
			lineChords.push_back(chord);
		}*/
		lineChords = StringMethods::TokenizeWithSpaces(currentLine);

		vector<string> transposedLn = transposeLine(lineChords, startKEY, endKEY);
		vector<string>::iterator iter;
		string chordline;
		for (iter = transposedLn.begin(); iter != transposedLn.end(); ++iter){
			if (iter + 1 != transposedLn.end()){
				string dbg = "";
				dbg = *iter;
				/*chordline = chordline + *iter + spaces;*/
				chordline = chordline + *iter;
			}
			else{
				chordline = chordline + *iter;
			}
			
		}
		chordline += "\n";
		output += chordline;
	}
	return output;
}

vector<string> Song::transposeLine(vector<string> lineChords, KEY startKEY, KEY endKEY){
	vector<string> newChords;
	for (int i = 0; i < 50; i++){
		newChords.push_back("");
	}

	int debugsize = lineChords.size();

	for (int i = 0; i < lineChords.size(); i++){
		//replace all chords within this case
		//string transposedChord = findEquivalent(lineChords[i], startKEY, endKEY);
		int checkemptychord = lineChords[i].find_first_not_of(" ");
		if (checkemptychord != string::npos){
			int offset = endKEY - startKEY;
			string base = isolateChord(lineChords[i]);
			string details = isolateDetails(lineChords[i]);
			if (IsValidChord(base, details)){
				string transposedChord = offSet(base, offset);
				details = transposeSlashChord(details, offset);
				transposedChord += details;
				newChords[i] = transposedChord;
			}

			else{
				newChords[i] = lineChords[i];
			}

		}

		//added to attempt to include spaces
		else{
			newChords[i] = lineChords[i];
		}
	}

	vector<string> output;
	vector<string>::iterator iter;
	for (iter = newChords.begin(); iter != newChords.end(); ++iter){
		//if (*iter != spaces){
		//	output.push_back(*iter);
		//}
		output.push_back(*iter);
	}

	//handle bug when output is uninitialized
	if (output.empty()){
		output.push_back("");
		return output;
	}
	else{
		return output;
	}
}

string Song::isolateChord(string input){
	istringstream in(input);
	char tChord;
	char sharp;
	string output = "";
	in >> tChord;
	in >> sharp;
	output = tChord;
	if (sharp == '#'){
		output += sharp;
	}
	if (sharp == 'b'){
		output += sharp;
	}
	return output;
}
string Song::isolateDetails(string input){
	istringstream in(input);
	string remainder = "";
	char tChord;
	char sharp;
	string output = "";
	in >> tChord;
	if (in >> sharp){
		if (!in.eof()){
			if (sharp == '#' || sharp == 'b'){
				getline(in, remainder);
			}
			else{
				string buffer;
				getline(in, buffer);
				remainder = sharp + buffer;
			}
		}
		
	}
	
	return remainder;
}

string Song::offSet(string base, int offset){
	string transposed;
	for (int i = 0; i < 12; i++){
		if (base == notes[i] || base == notes_alias[i]){
			transposed = notes[(i + offset + 12) % 12]; //12 is to ensure result is positive in the event that offset is negative
		}
	}

	return transposed;
}

string Song::transposeSlashChord(string remainder, int offset){
	int slashIdx;
	string output;
	slashIdx = remainder.find_first_of("/");
	if (slashIdx != string::npos){
		string newSlashChord;
		string before_slash = remainder.substr(0, slashIdx);
		int length = remainder.length() - slashIdx;
		string after_slash = remainder.substr(slashIdx + 1, length);
		after_slash = transposeSlashChord(after_slash, offset);
		string currentChord = isolateChord(after_slash);
		string after_slash_details = isolateDetails(after_slash);
		string newChord = offSet(currentChord, offset);
		if (newChord == ""){
			//assumption: newChord == currentChord == ""
			newSlashChord = before_slash + "/" + after_slash;
			output = newSlashChord;
		}
		else{
			newSlashChord = before_slash + "/" + newChord + after_slash_details;
			output = newSlashChord;
		}
		
	}
	else{
		output = remainder;
	}
	
	return output;
}

void Song::save(string filename){
	ofstream out(filename.c_str());
	for (int i = 0; i< lineCount; i++){
		out << chords[i] << "\r\n";
		out << lyrics[i] << "\r\n";
	}
	return;
}

string Song::ToString(){
	ostringstream oss;

	int found = title_visible.find_first_of(".");
	if (found != string::npos){
		title_visible = title_visible.substr(0, found);
	}
	oss << title_visible << "\r\n" << "\r\n";
		for (int i = 0; i< lineCount; i++){
			oss << chords[i] << "\r\n";
			oss << lyrics[i] << "\r\n";
	}

		oss << "=========================================================" << "\r\n" << "\r\n";
		return oss.str();
}

string Song::Chords(){
	ostringstream oss;
	for (int i = 0; i< lineCount; i++){
		oss << chords[i] << "\r\n";
	}
	oss << "=========================================================" << "\r\n" << "\r\n";
	return oss.str();
}

bool Song::IsValidChord(string base, string details){
	const int maxAug = 20;
	string aug[maxAug];
	aug[0] = "dim";
	aug[1] = "aug";
	aug[2] = "sus";
	aug[3] = "maj";
	aug[4] = "min";
	aug[5] = "2";
	aug[6] = "3";
	aug[7] = "5";
	aug[8] = "7";
	aug[9] = "9";
	aug[10] = "11";
	aug[11] = "13";
	aug[12] = "m";
	aug[13] = "M";
	aug[14] = "1";
	aug[15] = "add";
	aug[16] = "6";
	aug[17] = "4";
	aug[18] = "b";
	aug[19] = "#";
	const int maxInvalid = 20;
	string invalidchars[maxInvalid];

	vector<string>::iterator iter;
	bool isValid = false;
	bool isInvalidAug = true;
	bool isInvalid = true;
	
	int findInvalidDetail = details.find_first_of("cefhklopqrstvwxyzHKLOPQRTVWXYZ");
	int findInvalidBase = base.find_first_of("cefhklopqrstvwxyzHKLOPQRTVWXYZ");
	if (findInvalidDetail == string::npos && findInvalidBase == string::npos){
		isInvalid = false;
	}

	for (int i = 0; i < maxAug; i++){
		int found = details.find(aug[i]);
		if (found != string::npos || details == ""){
			isInvalidAug = false;
		}
	}
	


	bool properChordFound = false;
	for (int i = 0; i < 12; i++){
		if (notes[i] == base || notes_alias[i] == base){
			properChordFound = true;
		}
		
		int found = details.find(notes[i]);
		int found_alias = details.find(notes_alias[i]);
		if (found != string::npos || found_alias != string::npos){
			isInvalidAug = false;
		}
	}



	if (properChordFound == true && !isInvalidAug && !isInvalid){
		isValid = true;
	}
	else{
		isValid = false;
	}
	return isValid;
}