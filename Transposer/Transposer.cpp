#include "Transposer.h"


Transposer::Transposer()
{
	myList = new Songlist();
	DISPLAY_SONGLYRICS = "";
	DISPLAY_SONGLIST = "";
	INPUT_COMMAND_LINE = "";
	curIdx = 0;
	DISPLAY_FEEDBACK = "INITIALIZED";
}


Transposer::~Transposer()
{
}

void Transposer::Next(){
	int offset = myList->songCount;
	curIdx = (offset + curIdx + 1) % myList->songCount; // 0 based indexing
	int idx = curIdx + 1; //change to 1 based
	DISPLAY_SONGLYRICS = myList->SongToString(idx);
}

void Transposer::Previous(){
	int offset = myList->songCount;
	curIdx = (offset + curIdx - 1) % myList->songCount; // 0 based indexing
	int idx = curIdx + 1; //change to 1 based
	DISPLAY_SONGLYRICS = myList->SongToString(idx);
}

void Transposer::Update(){
	string dbg1 = INPUT_COMMAND_LINE;
	COMMAND command = Parse(INPUT_COMMAND_LINE);
	if (Execute(command, INPUT_COMMAND_LINE)){
		DISPLAY_FEEDBACK = "Success!";
	}
	else{
		DISPLAY_FEEDBACK = "Failed.";
	}
	string dbg2 = DISPLAY_SONGLIST;
	string dbg3 = DISPLAY_SONGLYRICS;
	return;
}
void Transposer::TransposeUp(){
	int idx = curIdx + 1;
	myList->transpose(idx, "e", "f");
	DISPLAY_SONGLYRICS = myList->SongToString(idx);
	return;
}
void Transposer::TransposeDown(){
	int idx = curIdx + 1;
	myList->transpose(idx, "f", "e");
	DISPLAY_SONGLYRICS = myList->SongToString(idx);
	return;
}

Transposer::COMMAND Transposer::Parse(string input){
	istringstream in(input);
	string command;
	string buffer;
	in >> command;
	if (command == "transpose"){
		if (!in.eof()){
			in >> buffer;
			if (!in.eof()){
				return COMMAND::TRANSPOSE;
			}
		}
		return COMMAND::INVALID;
	}
	if (command == "display"){
		return COMMAND::DISPLAY;
	}
	if (command == "select"){
		return COMMAND::SELECT;
	}
	if (command == "exit"){
		return COMMAND::EXIT;
	}

	if (command == "chords"){
		return COMMAND::CHORDS;
	}

	if (command == "save"){
		return COMMAND::SAVE;
	}

	if (command == "reload"){
		return COMMAND::RELOAD;
	}
	return COMMAND::INVALID;
}

bool Transposer::Execute(Transposer::COMMAND command, string input){
	istringstream in(input);
	string buffer;
	string songRef;
	string remainder;
	string startkey;
	string endkey;

	in >> buffer;
	in >> songRef;
	in >> startkey;
	in >> endkey;
	buffer = "";
	getline(in, buffer);
	remainder += buffer;
	switch (command){
		case TRANSPOSE:{
			if (songRef != "" && startkey != "" && endkey != ""){
				myList->transpose(atoi(songRef.c_str()), startkey, endkey);
				DISPLAY_SONGLYRICS = myList->SongToString(atoi(songRef.c_str()));
			}
			else{
				return false;
			}
			
			break;
		}
		case DISPLAY:{
			string dbg = myList->ToString();
			DISPLAY_SONGLIST = myList->ToString();
			break;
		}
		case CHORDS:{
			if (songRef != ""){
				DISPLAY_SONGLYRICS = myList->ChordsToString(atoi(songRef.c_str()));
			}
			break;
		}
		case SELECT:{
			if (songRef != ""){
				DISPLAY_SONGLYRICS = myList->SongToString(atoi(songRef.c_str()));
			}
			break;
		}
		case EXIT:{
			return false;
		}
		case SAVE:{
			istringstream getfilename(input);
			string buffer;
			string filename;
			getfilename >> buffer; //remove command
			int index = curIdx + 1;
			if (getline(getfilename, filename)){
				filename = filename.substr(1, (filename.length() - 1));
				//myList->saveSong(atoi(songRef.c_str()), filename);
				myList->saveSong(index, filename);
			}
			else{
				return false;
			}
			
			break;
		}
		case RELOAD:{
			delete myList;
			myList = new Songlist();
			break;
		}
		case INVALID:{
			return false;
		}

	}
	DISPLAY_SONGLIST = myList->ToString();
	return true;
}