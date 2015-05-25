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
	string ALL_SONGS = "ALL.slist";
	string songListDIR = "Playlists\\";
	string songDIR = Song::songDIR;
	string FILENAME_ACTIVE;
	int curIdx; // 0 based
	bool spawn = false;

	//==============================================
	//MAIN TAB
	//==============================================
	Transposer();
	~Transposer();
	void Update();
	void Next();
	void Previous();
	void TransposeUp();
	void TransposeDown();
	void QuickTransposeUp();
	void QuickTransposeDown();
	void NewWindow();
	void AddSong(string directory);
	void CreateSong(string filename, vector<string> songContent);

	//==============================================
	//OPTIONS TAB
	//==============================================
	//SAVE
	string DISPLAY_SAVE_TAB_STATUSBAR;
	void SavePlaylist();
	void SaveSong();
	void SaveAllSongs();




	//==============================================
	//MISC
	//==============================================
	COMMAND Parse(string input);
	bool Execute(COMMAND command, string input);
	bool IndexIsValid(int index); //1 based index
	string GetActiveFile();
	string GetCurrentSongPath();
	string UpdateActiveFile(string filename);
	string UpdateSongListFile();
	bool FileExists(string directory);
	void UpdateActivePlaylist();
	vector<string> GetFileNames();
	string GetDirectory(string fileExtension);
	


};

