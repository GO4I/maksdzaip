#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "locale.h"

#pragma warning(disable : 4996)

using namespace std;
const int string_len = 8;

void showTask() {
	cout << "—читать ID3v1 из MP3 файлов." << "\t"
		<< "–еализовать чтение форматов: ZIP: Local File Header" << endl;
}

void readMp3Header(const string fname) {
	ifstream f;

	f.open(fname);
	if (!f.is_open()) {
		cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
		f.close();
		return;
	}

	unsigned char b2[2];
	unsigned char b3;
	unsigned char b4;

	cout << "----------------- Read First MP3 Header in file without ID3v2----------------- \n";
	f.read((char*)b2, sizeof(b2));
	f.read((char*)&b3, sizeof(char));
	f.read((char*)&b4, sizeof(char));
	f.close();

	cout << fname << endl << "Signature: " << hex << showbase << endl
		<< (int)b2[0] << endl
		<< (int)b2[1] << endl
		<< (int)b3 << endl
		<< (int)b4 << endl;

	cout << endl;
}

void readZipHeader(string fname) {
	ifstream f;

	f.open(fname);
	if (!f.is_open()) {
		cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
		f.close();
		return;
	}

	  #pragma pack(push, 1)  // упаковка пам€ти, иначе структура будет занимать 16 байт, а не 14, как положено
	struct ZIPLOCALFILEHEADER {
		unsigned int sign;
		short int version;
		short int flag;
		short int comp;
		short int lastTime;
		short int lastDate;
		unsigned int crc;
		unsigned int sizec;
		unsigned int sized;
		short int lenName;
		short int lenEf;
		     char * fName;
		     char * ef;
	};
	   #pragma pack(pop)

	ZIPLOCALFILEHEADER lfh;

	cout << "----------------- Read ZIP ----------------- \n";
	f.read((char*)&lfh, sizeof(ZIPLOCALFILEHEADER));
	f.close();

	unsigned short int ud = lfh.lastDate;
	unsigned short int ut = lfh.lastTime;

	cout << fname << endl;
	cout << "Local File Header: " << endl << dec
		<< "sign     " << (unsigned int)lfh.sign << endl //<< dec
		<< "version  " << (short int)lfh.version << endl
		<< "flag     " << (short int)lfh.flag << endl
		<< "comp     " << (unsigned short int) lfh.comp << endl
		<< "lastTime " << (unsigned short int) lfh.lastTime
		<< " (" << ((ut & 0xF800) >> 11) << ":"
		<< ((((ut) & 0x7E0) >> 6)) << ":"
		<< 2 * (ut & 0x1f) << ")" << endl
		<< "lastDate " << (unsigned short int) lfh.lastDate
		<< " (" << (ud & 0b11111) << "/"
		<< ((((ud) & 0x1E0) / 0x20)) << "/"
		<< (((ud & 0x0FE00) / 0x0200) + 1980) << ")" << endl
		<< "crc      " << (unsigned int)lfh.crc << endl
		<< "sizec    " << (unsigned int)lfh.sizec << endl
		<< "sized    " << (unsigned int)lfh.sized << endl
		<< "lenName  " << (short int)lfh.lenName << endl
		<< "lenEf    " << (short int)lfh.lenEf << endl;

	cout << endl;
}

void readMp3Id3v1(const string fname) {
	ifstream f;

	f.open(fname);
	if (!f.is_open()) {
		cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
		f.close();
		return;
	}
	// будет дописанн
	cout << "----------------- Read First MP3 Header in file without ID3v2----------------- \n";

	f.close();

	cout << endl;
}

int main()
{
	// init
	cout.precision(5);
	srand(5);
	setlocale(LC_ALL, "Russian");
	
	showTask();
	cout << endl;

	readMp3Header("1.mp3");
	readMp3Header("2.mp3");
	readMp3Header("3.mp3");
	readMp3Id3v1("1.mp3");
	readMp3Id3v1("2.mp3");
	readMp3Id3v1("3.mp3");

	readZipHeader("files.zip");
	readZipHeader("ezyzip.zip");
	readZipHeader("tennis.zip");

	return 0;
}
