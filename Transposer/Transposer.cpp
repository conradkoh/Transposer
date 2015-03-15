#include "Transposer.h"


Transposer::Transposer()
{
	FILENAME_ACTIVE = GetActiveFile();
	myList = new Songlist(songListDIR + FILENAME_ACTIVE);
	s = new Song();
	DISPLAY_SONGLYRICS = to_string(1) + ". " + myList->SongToString(1);;
	DISPLAY_SONGLIST = myList->ToString();
	INPUT_COMMAND_LINE = "";
	INPUT_QUICKTRANSPOSE = "";
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
	DISPLAY_SONGLYRICS = to_string(idx) + ". " + myList->SongToString(idx);
}

void Transposer::Previous(){
	int offset = myList->songCount;
	curIdx = (offset + curIdx - 1) % myList->songCount; // 0 based indexing
	int idx = curIdx + 1; //change to 1 based
	DISPLAY_SONGLYRICS = to_string(idx) + ". " + myList->SongToString(idx);
}

void Transposer::Update(){
	COMMAND command = Parse(INPUT_COMMAND_LINE);
	if (Execute(command, INPUT_COMMAND_LINE)){
	}
	else{
		DISPLAY_FEEDBACK = "Failed.";
	}
	return;
}
void Transposer::TransposeUp(){
	int idx = curIdx + 1;
	myList->transpose(idx, "e", "f");
	DISPLAY_SONGLYRICS = to_string(idx) + ". " + myList->SongToString(idx);
	INPUT_QUICKTRANSPOSE = s->TransposeStr(INPUT_QUICKTRANSPOSE, Song::E, Song::F);
	return;
}
void Transposer::TransposeDown(){
	int idx = curIdx + 1;
	myList->transpose(idx, "f", "e");
	DISPLAY_SONGLYRICS = to_string(idx) + ". " + myList->SongToString(idx);
	INPUT_QUICKTRANSPOSE = s->TransposeStr(INPUT_QUICKTRANSPOSE, Song::F, Song::E);
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

	if (command == "load"){
		return COMMAND::LOAD;
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
				int index = atoi(songRef.c_str());
				if (IndexIsValid(index)){
					myList->transpose(index, startkey, endkey);
					DISPLAY_SONGLYRICS = to_string(index) + ". " + myList->SongToString(atoi(songRef.c_str()));
					DISPLAY_FEEDBACK = "Transpose.";
					curIdx = index - 1;
				}
				else{
					DISPLAY_FEEDBACK = "Invalid index.";
				}
				
			}
			else{
				return false;
			}
			
			break;
		}
		case DISPLAY:{
			string dbg = myList->ToString();
			DISPLAY_SONGLIST = myList->ToString();
			DISPLAY_FEEDBACK = "Display.";
			break;
		}
		case CHORDS:{
			if (songRef != ""){
				int index = atoi(songRef.c_str());
				if (IndexIsValid(index)){
					if (myList->ChordsToString(atoi(songRef.c_str())) != ""){
						DISPLAY_SONGLYRICS = to_string(index) + ". " + myList->ChordsToString(index);
						DISPLAY_FEEDBACK = "Chords.";
						curIdx = index - 1;
					}
					else{
						return false;
					}
				}
				else{
					DISPLAY_FEEDBACK = "Invalid index.";
				}
			}
			else{
				return false;
			}
			break;
		}
		case SELECT:{
			int index = atoi(songRef.c_str());
			if (songRef != "" && index <= myList->songCount && index > 0){
				DISPLAY_SONGLYRICS = to_string(index) + ". " + myList->SongToString(index);
				DISPLAY_FEEDBACK = "Selected.";
				curIdx = index - 1;
			}
			else{
				DISPLAY_FEEDBACK = "Invalid song index.";
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
				DISPLAY_FEEDBACK = "Saved.";
			}
			else{
				return false;
			}
			
			break;
		}
		case RELOAD:{
			delete myList;
			myList = new Songlist(FILENAME_ACTIVE);
			DISPLAY_SONGLYRICS = to_string(1) + ". " + myList->SongToString(1);;
			DISPLAY_SONGLIST = myList->ToString();
			INPUT_COMMAND_LINE = "";
			curIdx = 0;
			DISPLAY_FEEDBACK = "Reloaded.";
			break;
		}
		case LOAD:{
			istringstream getfilename(input);
			string buffer;
			string filename;
			getfilename >> buffer; //remove command
			if (getline(getfilename, filename)){
				filename = filename.substr(1, filename.length() - 1);
				string filenamedir = songListDIR + filename;
				if (FileExists(filenamedir)){
					delete myList;
					myList = new Songlist(filenamedir);
					DISPLAY_SONGLYRICS = to_string(1) + ". " + myList->SongToString(1);;
					DISPLAY_SONGLIST = myList->ToString();
					INPUT_COMMAND_LINE = "";
					curIdx = 0;
					UpdateActiveFile(filename);
					DISPLAY_FEEDBACK = "Loaded: " + filename;
				}
				else{
					DISPLAY_FEEDBACK = "File does not exist";
				}
			}
			else{
				return false;
			}
			
			break;
		}
		case INVALID:{
			return false;
		}

	}
	DISPLAY_SONGLIST = myList->ToString();
	return true;
}
bool Transposer::IndexIsValid(int index){
	if (index > 0 && index <= myList->songCount){
		return true;
	}
	else{
		return false;
	}
}
string Transposer::GetActiveFile(){
	ifstream in;
	string filename;
	in.open(FILENAME_ACTIVE_CONTAINER);
	if (getline(in, filename)){
		return filename;
		in.close();
	}
	in.close();
	return "temp.slist";
}

string Transposer::UpdateActiveFile(string filename){
	ofstream out;
	out.open(FILENAME_ACTIVE_CONTAINER.c_str(), ios::trunc);
	out << filename;
	FILENAME_ACTIVE = filename;
	return "filename updated";
}

bool Transposer::FileExists(string filename){
	ifstream in;
	string test;
	in.open(filename.c_str());
		if (in >> test){
			in.close();
			return true;
		}
		else{
			in.close();
			return false;
	}
}
