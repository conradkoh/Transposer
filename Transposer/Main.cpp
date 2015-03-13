#include <iostream>
#include <string>
#include <sstream>
#include "Song.h"
#include "Songlist.h"
#include "Transposer.h"
#include <Windows.h>
using namespace std;
enum COMMAND {TRANSPOSE, DISPLAY, CHORDS, SELECT, SAVE, RELOAD, EXIT, INVALID};
bool execute(COMMAND command, string input);
COMMAND parse(string input);
Songlist* myList;
int main(){
	myList = new Songlist();
	//debug
	Transposer* transposer = new Transposer();
	transposer->INPUT_COMMAND_LINE = "display";
	transposer->Update();
	string dbg1 = transposer->DISPLAY_SONGLIST;
	string dbg2 = transposer->DISPLAY_SONGLYRICS;
	system("CLS");
	cout <<"TEST!" << transposer->DISPLAY_SONGLIST << endl;
	cout <<"TEST!" <<  transposer->DISPLAY_SONGLYRICS << endl;
	//end debug
	system("pause");

	
	system("CLS");
	myList->displayList();
	bool exitStatus = false;
	string input;
	while (exitStatus == false && getline(cin, input)){
		system("CLS");
		myList->displayList();
		COMMAND command = parse(input);
		exitStatus = execute(command, input);

	}
}

COMMAND parse(string input){
	istringstream in(input);
	string command;
	string buffer;
	in >> command;
	if (command == "transpose"){
		if(!in.eof()){
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

bool execute(COMMAND command, string input){
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
			myList->transpose(atoi(songRef.c_str()), startkey, endkey);
			break;
		}
		case DISPLAY:{
			myList->displayList();
			break;
		}
		case CHORDS:{
			myList->displaySongChords(atoi(songRef.c_str()));
			break;
		}
		case SELECT:{
			myList->displaySong(atoi(songRef.c_str()));
			break;
		}
		case EXIT:{
			return true;
		}
		case SAVE:{
			istringstream getfilename(input);
			string buffer;
			string filename;
			getfilename >> buffer; //remove command
			getfilename >> buffer; //remove songRef
			getline(getfilename, filename);
			filename = filename.substr(1, (filename.length() - 1));
			myList->saveSong(atoi(songRef.c_str()), filename);
			break;
		}
		case RELOAD:{
			delete myList;
			myList = new Songlist();
			break;
		}
		case INVALID:{
			cout << "invalid command" << endl;
		}

	}

	return false;
}
