#ifndef SONGLIST_H
#define SONGLIST_H
#include "Song.h"
#include <sstream>
#include <vector>

using namespace std;

class Songlist
{
public:

	string FILENAME;
	int songCount;
	vector<string> filenames;
	vector<Song*> songs;

	Songlist();
	Songlist(string FILENAME_ALL_SONG_FILENAMES);
	~Songlist();

	void addSong(string filename);

	void transpose(int index, string startkey, string endkey);
	Song::KEY stringToKEY(string input);
	string SongListTitles();

	//======================================================
	//SAVE
	//======================================================

	void saveSong(int index, string filename);
	string saveSong(int index);

	//======================================================
	//LOAD
	//======================================================

	void loadAll();

	//======================================================
	//MISC
	//======================================================
	bool FileExists(string filename);



	//======================================================
	//GET METHODS
	//======================================================

	string ToString();
	string ChordsToString(int index);
	string SongToString(int index);
	string GetFileNames();

	//======================================================
	//PRIVATE
	//======================================================
	vector<string> UpdateFileNamesVectorFromSong();

};

#endif