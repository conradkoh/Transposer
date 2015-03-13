#include "Songlist.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Songlist::Songlist()
{
	FILENAME = "songlist.txt";
	loadAll();
	songCount = songs.size();
}

Songlist::Songlist(string FILENAME_ALL_SONG_FILENAMES){
	
}

Songlist::~Songlist()
{
}

void Songlist::loadAll(){
	cout << "filename: " << FILENAME.c_str() << "\r\n";
	ifstream songFileNames(FILENAME.c_str());
	string filename_current_song;
	while (getline(songFileNames, filename_current_song)){
		cout << "loading: " << filename_current_song << "\r\n";
		Song* currentSong = new Song(filename_current_song);
		songs.push_back(currentSong);
		cout << "debug" << "\r\n";
	}
	cout << "loaded" << "\r\n";
	return;

}

void Songlist::addSong(){

}

void Songlist::displayList(){
	int index = 1;
	ifstream songFileNames(FILENAME);
	string filename_current_song;
	while (getline(songFileNames, filename_current_song)){
		cout << index <<". " << filename_current_song << "\r\n";
		index++;
	}
}

string Songlist::ToString(){
	ostringstream oss;
	int index = 1;
	ifstream songFileNames(FILENAME);
	string filename_current_song;
	while (getline(songFileNames, filename_current_song)){
		
		oss << index << ". " << filename_current_song << "\r\n";
		index++;
	}
	return oss.str();
}

void Songlist::displaySong(int index){
	if(index <= songCount){
		songs[index-1]->display();
	}
	
}

void Songlist::displaySongChords(int index){
	if (index <= songCount){
		songs[index - 1]->displayChords();
	}
}

string Songlist::ChordsToString(int index){
	ostringstream oss;
	if (index <= songCount){
		oss << songs[index - 1]->Chords();
	}
	return oss.str();
}

string Songlist::SongToString(int index){
	string output;
	if (index <= songCount){
		output = songs[index - 1]->ToString();
	}
	else{
		output = "invalid index\n";
	}
	return output;
}

void Songlist::transpose(int index, string startkey, string endkey){
	if(index <= songCount){
		Song::KEY startKEY = stringToKEY(startkey);
		Song::KEY endKEY = stringToKEY(endkey);

		songs[index-1]->transpose(startKEY, endKEY);
	}
}

void Songlist::saveSong(int index, string filename){
	if (index <= songCount){
		songs[index - 1]->save(filename);
	}
	return;
}

Song::KEY Songlist::stringToKEY(string input){
	if (input == "c" || input == "C"){
		return Song::KEY::C;
	}
	if (input == "c#" || input == "C#"){
		return Song::KEY::CSHARP;
	}
	if (input == "d" || input == "D"){
		return Song::KEY::D;
	}
	if (input == "d#" || input == "D#"){
		return Song::KEY::DSHARP;
	}
	if (input == "e" || input == "E"){
		return Song::KEY::E;
	}
	if (input == "f" || input == "F"){
		return Song::KEY::F;
	}
	if (input == "f#" || input == "F#"){
		return Song::KEY::FSHARP;
	}
	if (input == "g" || input == "G"){
		return Song::KEY::G;
	}
	if (input == "g#" || input == "G#"){
		return Song::KEY::GSHARP;
	}
	if (input == "a" || input == "A"){
		return Song::KEY::A;
	}
	if (input == "a#" || input == "A#"){
		return Song::KEY::ASHARP;
	}
	if (input == "b" || input == "B"){
		return Song::KEY::B;
	}
	
	return Song::KEY::INVALID;
}