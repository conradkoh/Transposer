#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "StringMethods.h"
using namespace std;



class Song
{
public:
	enum KEY { C, CSHARP, D, DSHARP, E, F, FSHARP, G, GSHARP, A, ASHARP, B, INVALID };
	enum NOTES {C1, C2, D1, D2, E1, F1, F2, G1, G2, A1, A2, B1};
	string FILENAME;
	vector<string> songLines;
	string spaces = "    ";
	string title_visible;
	static const string songDIR;
	static const string masterSongDIR;
	static const string saveDIR;

	static string notes[12];
	static string notes_alias[12];

	bool isInitalized = false;

	Song(void);
	~Song(void);
	Song(string filename);
	void Initialize();
	void transpose(KEY startKEY, KEY endKEY);
	void save(string filename);
	string save();
	string TransposeStr(string input, KEY startKEY, KEY endKEY);
	vector<string> transposeLine(vector<string> lineChords, KEY startKEY, KEY endKEY);
	string isolateChord(string input);
	string isolateDetails(string input);
	string offSet(string base, int offset);
	string transposeSlashChord(string remainder, int offset);
	string ToString();
	string Chords();

	bool IsValidChord(string base, string details);
	int CountValidChords(vector<string> chordline);

	//=========================================
	//GET METHODS
	//=========================================
	string GetFileName();
};

#endif