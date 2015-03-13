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
	void loadAll();
	void addSong();
	void displayList();
	string ToString();
	void displaySong(int index);
	void displaySongChords(int index);
	string ChordsToString(int index);
	string SongToString(int index);
	void transpose(int index, string startkey, string endkey);
	void saveSong(int index, string filename);
	Song::KEY stringToKEY(string input);
};

#endif