#include "Songlist.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
Songlist::Songlist()
{
	FILENAME = "songlist.slist";
	loadAll();
	songCount = songs.size();
}

Songlist::Songlist(string FILENAME_ALL_SONG_FILENAMES){
	FILENAME = FILENAME_ALL_SONG_FILENAMES;
	loadAll();
	songCount = songs.size();
}

Songlist::~Songlist()
{
}

void Songlist::loadAll(){
	ifstream songFileNames(FILENAME.c_str());
	string filename_current_song;
	while (getline(songFileNames, filename_current_song)){
		//if (FileExists(Song::songDIR + filename_current_song)){
			filenames.push_back(filename_current_song);
			Song* currentSong = new Song(filename_current_song);
			songs.push_back(currentSong);
		//}
	}
	songFileNames.close();
	return;

}

bool Songlist::FileExists(string filename){
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

void Songlist::addSong(string filename){
	Song* currentSong = new Song(filename);
	songs.push_back(currentSong);
	songCount++;
	UpdateFileNamesVectorFromSong();
	return;
}

string Songlist::ToString(){
	ostringstream oss;
	/*int index = 1;
	ifstream songFileNames(FILENAME);
	string filename_current_song;
	while (getline(songFileNames, filename_current_song)){
		
		oss << index << ". " << filename_current_song << "\r\n";
		index++;
	}*/
	vector<Song*>::iterator iter;
	int index = 1;
	for (iter = songs.begin(); iter != songs.end(); ++iter){
		oss << index << ". " << (*iter)->FILENAME << "\r\n";
			index++;
	}
	return oss.str();
}

string Songlist::SongListTitles(){
	ostringstream oss;
	vector<Song*>::iterator iter;
	int index = 1;
	for (iter = songs.begin(); iter != songs.end(); ++iter){
		if (iter + 1 != songs.end()){
			oss << (*iter)->FILENAME << "\n";
			index++;
		}
		else{
			oss << (*iter)->FILENAME;
			index++;
		}
		
	}
	return oss.str();
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
	if (index <= songs.size() && index > 0){
		output = songs[index - 1]->ToString();
	}
	else{
		if (index > songs.size() && songs.size()!= 0){
			index = index % songs.size();
			output = songs[index - 1]->ToString();
		}
		else{
			output = "";
		}

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
	if (index <= songCount && index > 0){
		songs[index - 1]->save(Song::saveDIR + filename);
	}
	return;
}

string Songlist::saveSong(int index){
	string feedback;
	if (index <= songCount && index > 0){
		feedback = songs[index - 1]->save();
	}
	else{
		feedback = "Invalid Index, Save Song Failed";
	}
	return feedback;
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

string Songlist::GetFileNames(){
	ostringstream out;
	vector<string>::iterator iter;
	for (iter = filenames.begin(); iter != filenames.end(); ++iter){
		out << (*iter) << endl;
	}

	return out.str();
}

vector<string> Songlist::UpdateFileNamesVectorFromSong(){
	ostringstream out;
	filenames.clear();
	for (int i = 0; i < songs.size(); i++){
		string currentfilename = songs[i]->GetFileName();
		filenames.push_back(currentfilename);
	}
	return filenames;
}