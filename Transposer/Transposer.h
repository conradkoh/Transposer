#pragma once
#include <string>
#include <sstream>
#include "Song.h"
#include "Songlist.h"
#include <Windows.h>
class Transposer
{
	enum COMMAND { TRANSPOSE, DISPLAY, CHORDS, SELECT, SAVE, RELOAD, EXIT, INVALID };
public:
	string DISPLAY_SONGLYRICS;
	string DISPLAY_SONGLIST;
	string INPUT_COMMAND_LINE;
	Songlist* myList;
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
	
};

