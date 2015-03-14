#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Song
{
public:
	enum KEY { C, CSHARP, D, DSHARP, E, F, FSHARP, G, GSHARP, A, ASHARP, B, INVALID };
	enum NOTES {C1, C2, D1, D2, E1, F1, F2, G1, G2, A1, A2, B1};
	string FILENAME;
	vector<string> chords;
	vector<string> lyrics;
	int lineCount;
	string spaces = "    ";
	static const string songDIR;
	static const string saveDIR;

	Song(void);
	~Song(void);
	Song(string filename);
	void transpose(KEY startKEY, KEY endKEY);
	void save(string filename);
	string TransposeStr(string input, KEY startKEY, KEY endKEY);
	vector<string> transposeLine(vector<string> lineChords, KEY startKEY, KEY endKEY);
	string isolateChord(string input);
	string isolateDetails(string input);
	string offSet(string base, int offset);
	string transposeSlashChord(string remainder, int offset);
	string ToString();
	string Chords();
};

#endif