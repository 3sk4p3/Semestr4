#include "MP3.h"
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
// #x to nazwa zmiennej 
#define name(x) std::cout << (#x)
std::map<std::string, const char*>id3v2Frames;

bool is_in_vec(std::vector<std::pair<std::string, int>> vec_in, int X)
{
	for (auto& e : vec_in)
		if (e.second == X)
			return true;
	return false;
}
void Printchar(const char* attribute, int len)
{
	std::cout << "  ";

	for (int i = 0; i < len; ++i)
	{
		std::cout << attribute[i];
	}
	std::cout << std::endl;
}
std::vector<std::pair<std::string, int>> FrameBuf;
bool operator==(const ID3v2Frame& o1, const ID3v2Frame& o2)
{
	
	char myint[4];
	char myint2[4];

	int* mycastint = (int*)myint;

	int* mycastint2 = (int*)myint2;
	
	for (int i = 0; i < 4; ++i)
	{
		myint[i] = o1.Size[3 - i];
		myint2[i] = o2.Size[3 - i];
		if (o1.FrameID[i] == o2.FrameID[i])continue;
		return false;
	}
	if (*mycastint==*mycastint2)	return true;
	return false;
	



}
//bool operator< (const ID3v2Frame& o1, const ID3v2Frame& o2)
//{
//	char myint[4];
//	char myint2[4];
//	myint[0] = o1.Size[3];
//	myint[1] = o1.Size[2];
//	myint[2] = o1.Size[1];
//	myint[3] = o1.Size[0];
//
//	int* mycastint = (int*)myint;
//	myint2[0] = o2.Size[3];
//	myint2[1] = o2.Size[2];
//	myint2[2] = o2.Size[1];
//	myint2[3] = o2.Size[0];
//	int* mycastint2 = (int*)myint2;
//	return  *mycastint < *mycastint2;
// }
bool MP3::read(const char* path)
{
	//ios in or ios binary or ios at the end 
	std::fstream File;
	File.open(path, std::ios::in | std::ios::binary | std::ios::ate);
		if (!File.is_open())
		{
			std::cerr << "error";
			return false;
		}
	

		
		//             =position of cuyrrent character
		std::ifstream::pos_type FileSize = File.tellg();
		if (FileSize < 0)
		{
			File.close();
			return false;
		}
		std::string tagId = "ID3";
		hasID3v2tag = hasID3v1tag = 1;
		//cursor position change
		File.seekg(0, std::ios::beg);

		//vector charow o rozmiarze FileSizeu
		data = std::vector<char>(FileSize);
		File.read(&data[0], FileSize);


		//sprawdzanie czy na poczatku jest tag ID3
		for (int i = 0; i < 3; ++i)
		{
			if (data[i] != tagId[i])hasID3v2tag = 0;
		}
		if (hasID3v2tag) 
		{
			LoadTags();
		//kopiuje naglowek
		memcpy(&id3v2, &data[0], sizeof(ID3v2Header));
		//wypierdalam naglowek
		data.erase(data.begin(), data.begin() + 10); 
		Wylew(*this);
	
		}

		//sprawdzanie czy na koniec-128 jest tag TAG
		tagId = "TAG";
		for (int i = 0; i < 3; ++i)
		{

			if (data[data.size() - 128 + i] != tagId[i])hasID3v1tag = 0;
		}



		if (hasID3v1tag)
		{
			//kopiowanie calego bloku pamieci do struktury(128)
			memcpy(&x, &data[data.size() - 128], sizeof(ID3v1));
			//kasowanie tego z daty
			// mozliwe ze niekonieczne jest usuwanie jak uzyje std::vector.assign
		//ata.erase((data.end() - 128), data.end());
	
		}


			File.close();
			return true;
}
	

//moj sizeof
 unsigned int My_Sizeof(const char* expression)
{
	int i = 0;
	while (expression[i] != '\0')++i;	
	return i-1;
}
//wypisywanie wartosci spod tablicy

std::ostream& operator<<(std::ostream& os, const MP3& MP3)
{

	name(ID3V1:header); Printchar(MP3.x.header,sizeof(MP3.x.header));
	name(ID3V1:artist); Printchar(MP3.x.artist, sizeof(MP3.x.artist));
	name(ID3V1:title); Printchar(MP3.x.title, sizeof(MP3.x.title));
	name(ID3V1:album); Printchar(MP3.x.album, sizeof(MP3.x.album));
	name(ID3V1:year); Printchar(MP3.x.year, sizeof(MP3.x.year));
	name(ID3V1:comment); Printchar(MP3.x.comment, sizeof(MP3.x.comment));
	name(ID3V1:genre); Printchar(MP3.x.genre, sizeof(MP3.x.genre));


	return os;
}

bool MP3::write(const char* path)
{
	
	std::fstream File(path, std::ios::out | std::ios::binary);
	//
	if (!File.is_open())
	{
		std::cerr << "error";
		return false;
	}

	if (hasID3v1tag||hasID3v2tag) {
		//File.seekg(128, std::ios::end);
		//data.insert(data.end(), reinterpret_cast<char*>(&x)[0], sizeof(ID3v1));
		char *bufID3v1= reinterpret_cast<char*>(&x);


		data.erase(data.begin(), data.begin() + GetSize());

		//unsigned char buf[sizeof(ID3v1)];
		//memcpy(&buf, &x, sizeof(ID3v1));
		data.erase((data.end() - 128), data.end());
		//data.insert(data.end(), buf, buf + sizeof(ID3v1));
		ID3v2ReWrite();
		std::copy(bufID3v1, bufID3v1 + sizeof(ID3v1), std::back_inserter(data));

		//std::memcpy(&data,&x , sizeof(ID3v1));
		File.write(&data[0], data.size());
		//File.write(reinterpret_cast<char*>(&x), sizeof(ID3v1));
	
	}
	return true;
	File.close();

}
void Wylew(MP3& _MP3)
{
	
	std::string PossibleFrame("T[A-Z][A-Z][A-Z1-9]");
	std::regex rx(PossibleFrame);
	std::string BufString(&_MP3.data[0], &_MP3.data[_MP3.id3v2.calcSize()]);
		//szukanie possbile tagow i umieszczanie je w buforze
	for (std::sregex_iterator it = std::sregex_iterator(BufString.begin(), BufString.end(), rx); it != std::sregex_iterator(); ++it)
	{
		std::smatch match;
		match = *it;
		ID3v2Frame key;
		memcpy(&key, &_MP3.data[match.position(0)], sizeof(ID3v2Frame));
		
		if (id3v2Frames.count(match.str(0)) > 0&& std::find(_MP3.Tags.begin(), _MP3.Tags.end(), key) == _MP3.Tags.end()) 
			
		{
			//no i sie okazalo ze freame buf w huj nie potrzebne...
			FrameBuf.push_back({ match.str(0), match.position(0) });//czemu to nie dziala SDXD./
			memcpy(&key, &_MP3.data[match.position(0)], sizeof(ID3v2Frame));
			_MP3.Tags.push_back(key);
			//FrameBuf.emplace_back(match.str(0), match.position(0) );
		}
			
		
 	}

	//teraz z tego samego bufora wypierdalam wartosc jezeli jej nie ma w mapie
	//std::vector<std::pair<std::string, int>>::iterator it;
	//int bufsize = FrameBuf.size();
	//for (int i = 0; i < bufsize; ++i)
	//{
	//	it = FrameBuf.begin()+i;
	//	if (id3v2Frames.count(FrameBuf[i].first) == 0)
	//	{
	//		FrameBuf.erase(it); 

	//		--bufsize;
	//		--i;
	//	}
	//}

	//teraz z tego co zostalo kopiuje zawartosc pliku do struktury w klasie
	//for (auto i : FrameBuf)
	//{
	//		
	//	
	//}
	/*std::sort(_MP3.Tags.begin(), _MP3.Tags.end());
	std::cout << "after sort: " << std::endl;
	for (auto i : _MP3.Tags)
	{
		char myint[4];
			myint[0] = i.Size[3];
	myint[1] = i.Size[2];
	myint[2] = i.Size[1];
	myint[3] = i.Size[0];
	int* mycastint = (int*)myint;
		std::cout << i.FrameID << "size: "<<*mycastint<<std::endl;
	}
	_MP3.Tags.erase(std::unique(_MP3.Tags.begin(), _MP3.Tags.end()), _MP3.Tags.end());
	std::cout << "after removing: " << std::endl;
	for (auto i : _MP3.Tags)
	{
		char myint[4];
		myint[0] = i.Size[3];
		myint[1] = i.Size[2];
		myint[2] = i.Size[1];
		myint[3] = i.Size[0];
		int* mycastint = (int*)myint;
		std::cout << i.FrameID << "size: " << *mycastint << std::endl;
	}*/
	

	int x = 0;
	for (auto i  : _MP3.Tags)

	{

		
		unsigned int FrameSize=i.FrameSize();
	
		int size=FrameBuf[x].second;
		size += 10;
		std::cout<< id3v2Frames.at(i.FrameID)<< std::endl;
		/*int size = (i.Size[3 ] << (8 * 0));
		for (int j= 1; j < 4; ++j)
		{
			std::cout << i.Size[j - 1] << " "  ;
			size += (i.Size[ 3-j] << (8 * j));
		}
		std::cout<<std::endl;;
		std::cout << std::endl << "leftshift size: " << size << std::endl;
		std::cout << std::endl << "endian size: " << *mycastint << std::endl;*/
		unsigned char* BufText;
	
		for (int j = size; j < (size+ FrameSize); ++j)
		{
			
			//BufText += _MP3.data[j+1];
			std::cout << _MP3.data[j];
		}
		memcpy(&BufText, &_MP3.data[size], FrameSize);
		_MP3.TextFrame.push_back({ i, BufText });
		std::cout << std::endl<<"size(po konwersji): " << FrameSize << std::endl;

	/*	std::cout << "flags: " << i.Flags << std::endl;
		std::cout << "encoding: " << i.Encoding<< std::endl;*/

		++x;
	}



	




					/*WORKING VERSSION :*/
	
	//while (std::regex_search(BufString,sm,rx))
	//{
	//	for (auto x:sm )
	//	{
	//		//std::cout << x <<" "<< std::endl;
	//		if (id3v2Frames.count(x) > 0)
	//		{
	//			FrameBuf.push_back(x);
	//		}c
	//		BufString = sm.suffix().str();
	//		
	//		sm.position();
	//		
	//	}
	//}
	//
	//for (auto i : FrameBuf)
	//{
	//	std::cout << i << std::endl;
	//}
	//

	/*char Second[] = { 'A','B','C','D','E','F','I','K','L','M','O','P','R','S','Y','X' };
	char Third[] = { 'A','L','P','O','N','X','M','T','E','F','R','W','U','C','D','S','I' };
	char Fourth[] = { 'B','M','N','P','T','Y','C','E','1','2','3','D','L','4','S','K','A','O','Z','R','X' };*/
	//size_t size = _MP3.GetSize();
	//std::string BufKey;
	//sprawdzanie po kolei czy nastepna pozycja w rejestrze nalezy do tablicy mozliwych znako
	//for (int i = 0; i < size; ++i)
	//{
	//			if (_MP3.data[i]=='T')
	//			{
	//				BufKey += "T";
	//				for (int j = 0; j < sizeof(Second); ++j)
	//				{
	//					if (_MP3.data[i + 1] == Second[j])
	//					{
	//						BufKey += _MP3.data[i + 1];
	//						for (int k = 0; k < sizeof(Third); ++k)
	//						{
	//							if (_MP3.data[i+2]==Third[k])
	//							{
	//								BufKey += _MP3.data[i + 2];
	//								for (int l = 0; l < sizeof(Fourth); ++l)
	//								{
	//									if (_MP3.data[i+3]==Fourth[l])
	//									{
	//										BufKey += _MP3.data[i + 3];
	//										//const char* result = BufKey.c_str();
	//										//char* c = const_cast<char*>(BufKey.c_str());
	//										//sprawdzanie czy 4literowy ciag nalezy do mapy
	//											if (id3v2Frames.find(BufKey)==id3v2Frames.end()){}
	//											else
	//										{
	//												ID3v2Frame BufFrame;
	//												memcpy(&BufFrame, &_MP3.data[i], sizeof(ID3v2Frame));
	//												//push back skoipiowanego bufora 
	//												_MP3.Tags.push_back(BufFrame);
	//											
	//										}
	//											
	//									}

	//								}
	//									

	//									
	//							}

	//						}
	//					}
	//				}

	//			}
	//			BufKey = "";
	//}
	
}


void MP3::ID3v2ReWrite()
{
//new size in header
ID3v2ReSize();
for (auto i : TextFrame)
{
	char* bufID3v2Frame=(char*)&i.first;
	//= reinterpret_cast<char*>(&i.first);
	//memcpy(bufID3v2Frame, &i.first, sizeof(ID3v2Frame));
	/*const char* beginning = i.second;
	const char* end = i.second + strlen(i.second);
	data.insert(data.begin() + sizeof(ID3v2Header),beginning,end);
	data.insert(data.begin() + sizeof(ID3v2Header), bufID3v2Frame[0], bufID3v2Frame[My_Sizeof(bufID3v2Frame)]);*/


}

}

bool MP3::SetTitle(  const char* arg)
{

	if (My_Sizeof(arg) > sizeof(x.title))return false;
	for (int i = 0; i < sizeof(x.title); ++i)
	{
		this->x.title[i] = '\0';
	}
	memcpy(&x.title, arg, My_Sizeof(arg));
	return true;
}

bool MP3::SetArtist(const char* arg)
{

	if (My_Sizeof(arg) > sizeof(x.artist))return false;
	for (int i = 0; i < sizeof(x.artist); ++i)
	{
		this->x.artist[i] = '\0';
	}
	memcpy(&x.artist, arg, My_Sizeof(arg));
	return true;
}

bool MP3::SetAlbum(const char* arg)
{

	if (My_Sizeof(arg) > sizeof(x.album))return false;
	for (int i = 0; i < sizeof(x.album); ++i)
	{
		this->x.album[i] = '\0';
	}
	memcpy(&x.album, arg, My_Sizeof(arg));
	return true;
}

bool MP3::SetYear(const char* arg)
{

	if (My_Sizeof(arg) > sizeof(x.year))return false;
	for (int i = 0; i < sizeof(x.year); ++i)
	{
		this->x.year[i] = '\0';
	}
	memcpy(&x.year, arg, My_Sizeof(arg));
	return true;
}

bool MP3::SetComment(const char* arg)
{


	if (My_Sizeof(arg) > sizeof(x.comment))return false;
	for (int i = 0; i < sizeof(x.comment); ++i)
	{
		this->x.comment[i] = '\0';
	} 
	memcpy(&x.comment, arg, My_Sizeof(arg));
	//for (int i = 0; i < sizeof(arg); ++i)
	//{
	//	this->x.comment[i] =arg[i];
	//}
	/*int i = 0;
	while (arg[i] != '\0')
	{
		this->x.comment[i] = arg[i];
		++i;
	}
	return true;*/
	return true;
}

bool MP3::SetGenre(const char* arg)
{

	if (My_Sizeof(arg) > sizeof(x.genre))return false;
	for (int i = 0; i < sizeof(x.genre); ++i)
	{
		this->x.genre[i] = '\0';
	}
	memcpy(&x.genre, arg, My_Sizeof(arg));
	return true;
}

unsigned int ID3v2Header::calcSize()
{
	unsigned int buf_size = 0;
	for (int i = 0; i < 4; ++i) {
		buf_size += size[3 - i] << (7 * i);
	}
	return buf_size;
}
void MP3::ID3v2ReSize()
{
	unsigned int size = 0;
	for (auto i : this->Tags)
	{
		size += sizeof(ID3v2Frame);
		size += i.FrameSize();
	}
	unsigned int extractor = 0b01111111;
	for (int j = 0; j < 4; ++j)
	{
		id3v2.size[3-j] = 0;
		id3v2.size[3 - j] = (size & extractor) >> (7 * j);
		extractor <<= 7;

	}
	return;
}
unsigned int MP3::GetSize()
{
	std::cout << sizeof(id3v2);
	return id3v2.calcSize();
}
void LoadTags()
{
	id3v2Frames.insert({ "TALB","Album:" });
	id3v2Frames.insert({ "TBPM","Bits_Per_Minute:" });
	id3v2Frames.insert({ "TCOM","Composer:" });
	id3v2Frames.insert({ "TCON","Content_type:" });
	id3v2Frames.insert({ "TCOP","Copyright_message:" });
	id3v2Frames.insert({ "TDAT","Date:" });
	id3v2Frames.insert({ "TDLY","Playlist_Delay:" });
	id3v2Frames.insert({ "TENC","Encoded_by:" });
	id3v2Frames.insert({ "TEXT","Lyricist:" });
	id3v2Frames.insert({ "TFLT","File_type:" });
	id3v2Frames.insert({ "TIME","Time:" });
	id3v2Frames.insert({ "TIT1","Content_group_description(?):" });
	id3v2Frames.insert({ "TIT2","Title/songname:" });
	id3v2Frames.insert({ "TIT3","Subtitle:" });
	id3v2Frames.insert({ "TKEY","Initial_key:" });
	id3v2Frames.insert({ "TLAN","Language(s):" });
	id3v2Frames.insert({ "TLEN","Length:" });
	id3v2Frames.insert({ "TMED","Media_type:" });
	id3v2Frames.insert({ "TOAL","Original_album_title:" });
	id3v2Frames.insert({ "TOFN","Original_File_Name:" });
	id3v2Frames.insert({ "TOLY","Original_Lyricist:" });
	id3v2Frames.insert({ "TOPE","Original_Artist:" });
	id3v2Frames.insert({ "TORY","Original_Release_Year:" });
	id3v2Frames.insert({ "TOWN","File_owner/license:" });
	id3v2Frames.insert({ "TPE1","Lead_Performer:" });
	id3v2Frames.insert({ "TPE2","Band/orchestra:" });
	id3v2Frames.insert({ "TPE3","Conductor/performer_refinement:" });
	id3v2Frames.insert({ "TPE4","Modified_by:" });
	id3v2Frames.insert({ "TPOS","Part_of_a_set:" });
	id3v2Frames.insert({ "TPUB","Publiser:" });
	id3v2Frames.insert({ "TRCK","Track_number/position_in_set:" });
	id3v2Frames.insert({ "TRDA","Recording_dates:" });
	id3v2Frames.insert({ "TRSN","Internet_radio_station_name:" });
	id3v2Frames.insert({ "TRSO","Internet_radio_station_owner:" });
	id3v2Frames.insert({ "TSIZ","Size:" });
	id3v2Frames.insert({ "TSRC","ISRC(international_standard_recording_code):" });
	id3v2Frames.insert({ "TSSE","Software/Hardware_and_settings_used_for_encoding:" });
	id3v2Frames.insert({ "TYER","Year:" });
	id3v2Frames.insert({ "TXXX","User_defined_text_info_frame:" });
	


}
bool MP3::Insert(ID3v2Frame _Frame, const char* content)
{
	
	//jak to nie jest frame TXXX
	if (_Frame.FrameID != "TXXX")
	{
		//jak nie ma w mapie lub juz jest w tagach oddaj 0;
		if (id3v2Frames.count(_Frame.FrameID) == 0 || std::find(Tags.begin(), Tags.end(), _Frame) != Tags.end())return false;
	}
	//Dla TXXX:
	char* bufID3v2Frame = reinterpret_cast<char*>(&_Frame);
	bufID3v2Frame += *content;
	Tags.push_back(_Frame);
	data.insert(data.begin() + sizeof(ID3v2Header), bufID3v2Frame[0], bufID3v2Frame[My_Sizeof(bufID3v2Frame)]); return true;


}

unsigned int ID3v2Frame::FrameSize()
{
	char myint[4];
	myint[0] = Size[3];
	myint[1] = Size[2];
	myint[2] = Size[1];
	myint[3] = Size[0];

	int* mycastint = (int*)myint;
	return *mycastint;
}
