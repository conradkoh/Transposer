#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include "Song.h"
#include "Songlist.h"
#include <Windows.h>
class Transposer
{
	enum COMMAND { TRANSPOSE, DISPLAY, CHORDS, SELECT, SAVE, RELOAD, LOAD, EXIT, INVALID };
public:
	string DISPLAY_SONGLYRICS;
	string DISPLAY_SONGLIST;
	string DISPLAY_FEEDBACK;
	string INPUT_COMMAND_LINE;
	string INPUT_QUICKTRANSPOSE;
	string INPUT_ACTIVE;
	Songlist* myList;
	Song* s; // used to access methods from Song
	string FILENAME_ACTIVE_CONTAINER = "SYSTEM\\active.tsys";
	string FILENAME_ACTIVE;
	int curIdx; // 0 based
	
	Transposer();
	~Transposer();
	void Update();
	void Next();
	void Previous();
	void TransposeUp();
	void TransposeDown();
	COMMAND Parse(string input);
	bool Execute(COMMAND command, string input);
	bool IndexIsValid(int index); //1 based index
	string GetActiveFile();
	string UpdateActiveFile(string filename);
	bool FileExists(string filename);
	
};

