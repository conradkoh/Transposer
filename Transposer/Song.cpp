#include "Song.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//enum KEY { C, D, E, F, G, A, B, INVALID };

Song::Song(void)
{
}

Song::Song(string filename)
{
	FILENAME = filename;
	ifstream lyricStream(filename.c_str());
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
}

Song::~Song(void)
{
}

void Song::transpose(KEY startKEY, KEY endKEY){
	for(int i = 0; i<lineCount; i++){
		istringstream line(chords[i]);
		string newChordsLine;
		vector<string> lineChords;
		string spaces = "    ";
		
		string chord;
		while(line >> chord){
			lineChords.push_back(chord);
		}

		vector<string> newChords = transposeLine(lineChords, startKEY, endKEY);

		//reconstructing new chord line
		newChordsLine = newChords.front();
		for(int j = 1; j< newChords.size(); j++){
			newChordsLine += spaces;
			newChordsLine += newChords[j];
		}

		chords[i] = newChordsLine;

	}
}

vector<string> Song::transposeLine(vector<string> lineChords, KEY startKEY, KEY endKEY){
	vector<string> newChords(20);

	int debugsize = lineChords.size();

	for (int i = 0; i < lineChords.size(); i++){
		//replace all chords within this case
		//string transposedChord = findEquivalent(lineChords[i], startKEY, endKEY);
		int offset = endKEY - startKEY;
		string base = isolateChord(lineChords[i]);
		string details = isolateDetails(lineChords[i]);
		string transposedChord = offSet(base, offset);
		details = transposeSlashChord(details, offset);
		transposedChord += details;
		newChords[i] = transposedChord;
	}
	
	return newChords;
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
	string notes[12];
	string notes_alias[12];
	string transposed;
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
	notes[Song::NOTES::A2] = "A#";
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
	notes_alias[Song::NOTES::A2] = "Bb";
	notes_alias[Song::NOTES::B1] = "Cb";
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
	int found = FILENAME.find_last_of(".");
	string title = FILENAME.substr(0, found);
	oss << title << "\r\n" << "\r\n";
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