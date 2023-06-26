#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
struct ID3v1 {
	char header[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	char genre[1];
};
struct ID3v2Header
{
	char header[3];
	char version[2];
	char flag[1];
	char size[4];
	unsigned int calcSize();
	
	//	std::map<const char*, const char*>id3v2Frames;
};
struct ID3v2Frame
{
	char FrameID[4];
	//frame size excluding header (-10)
	unsigned char Size[4];//39
	char Flags[2];			
	char Encoding[1];
	unsigned int FrameSize();

	//friend bool operator< (const ID3v2Frame& o1, const ID3v2Frame& o2);
	friend bool operator== (const ID3v2Frame& o1, const ID3v2Frame& o2);
	
};
class MP3
{
private:
	
		bool hasID3v1tag;
		bool hasID3v2tag;
		ID3v1 x;
		ID3v2Header id3v2;
		std::vector <ID3v2Frame>Tags;	
		std::vector<char> data;
		std::vector<std::pair<ID3v2Frame,unsigned char*>>TextFrame;

public:
	
	MP3() :hasID3v1tag(0), hasID3v2tag(0) {};
	~MP3() {};
	bool read(const char* path);
	bool write(const char* path);
	friend std::ostream& operator<<(std::ostream& os, const MP3& MP3);




	void ID3v2ReWrite();

	bool SetTitle(const char *arg);
	bool SetArtist(const char *arg);
	bool SetAlbum(const char *arg);
	bool SetYear(const char *arg);
	bool SetComment(const char *arg);
	bool SetGenre(const char *arg);


	void ID3v2ReSize();
	unsigned int GetSize();
	bool Insert(ID3v2Frame _Frame, const char* content);


friend void Wylew(MP3& _MP3);
friend void Printchar(const char* attribute,int len);
};
unsigned int My_Sizeof(const char* expression);
void LoadTags();

