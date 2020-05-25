#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "locale.h"

#pragma warning(disable : 4996)

using namespace std;
const int string_len = 8;

void showTask() {
	cout << "Обьявить сущности (самолёт и авионика), реализовать запись и чтение данных в текстовом и бинарном файле" << "\t"
		<< "Посмотреть примеры и проверить работу функции для чтения PDF и BMP файлов." << endl;
}
struct Avionics {
	string serial;
	int type;
	int price;
};

struct Plane {
	string number;
	int age;
	float avg_price;
	Avionics avionics;
};

void showPlane(const Plane s) {
   cout << s.number << "\t"
		<< s.age << "\t"
		<< s.avg_price << "\t\t["
		<< s.avionics.serial << ","
		<< s.avionics.type << ","
		<< s.avionics.price << "]" << endl;
}

void showPlanes(const Plane sts[], const int len) {
	cout << "number \t"
		<< "age \t"
		<< "avg_price \t["
		<< "serial,"
		<< "type,"
		<< "and price]" << endl;

	for (int i = 0; i < len; i++) {
		showPlane(sts[i]);
	}

	cout << endl;
}

void randString(string& str, const int len) {
	static const char alphabet[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	    "0123456789";

	// очищаем и заносим данные
	str.clear();
	str.append(len, ' ');

	for (int i = 0; i < str.length(); i++) {
		int r = rand() % (sizeof(alphabet) - 1);
		str[i] = alphabet[r];
	}
	str[str.length()] = 0;  // последний символ сообщает о том, что строка закончилась
}

void initPlanes(Plane sts[], const int len) {
	for (int i = 0; i < len; i++) {
		
		sts[i].age = rand() % 25;
		sts[i].avg_price = 5.0 * (float)rand() / RAND_MAX;
		randString(sts[i].number, string_len);

		randString(sts[i].avionics.serial, string_len);
		sts[i].avionics.type = rand() % 25;
		sts[i].avionics.price = rand() % 50;
	}
}

void writeTextFile(const Plane sts[], const int l) {
	ofstream f;

	f.open("data.txt");
	for (int i = 0; i < l; i++)  // Все атрибуты struct  в одной строке
		f << sts[i].number << " "
		<< sts[i].age << " "
		<< sts[i].avg_price << " "
		<< sts[i].avionics.serial << " "
		<< sts[i].avionics.type << " "
		<< sts[i].avionics.price << endl;
	f.close();
}

void openTextFile(Plane sts[], const int l) {
	ifstream f;

	f.open("data.txt");
	for (int i = 0; i < l; i++)
		f >> sts[i].number
		>> sts[i].age
		>> sts[i].avg_price
		>> sts[i].avionics.serial
		>> sts[i].avionics.type
		>> sts[i].avionics.price;
	f.close();
}


void writeBinFile(Plane sts[], const int l) {
	// in-function WRITE code
	fstream f;
	f.open("data.bin.txt", ios::out | ios::binary);
	f.write((char*)sts, sizeof(Plane) * l);
	f.close();
}

void openBinFile(Plane sts[], const int l) {
	fstream f;
	f.open("data.bin.txt", ios::in | ios::binary);
	f.read((char*)sts, sizeof(Plane) * l);
	f.close();
}

void readPdfHeader(const string fname) {
	ifstream f;
	char head[8];

	f.open(fname.c_str());
	if (!f.is_open()) {
		cout << "Error open: " << fname;
		f.close();
		return;
	}
	f >> head;
	f.close();

	cout << "Size of char type is " << sizeof(char) << " byte." << endl;
	cout << "PDF header is 8 bytes." << endl;
	cout << "PDF header of \"" << fname << "\" file is: " << head << endl;
}

typedef short int WORD;
typedef unsigned int DWORD;
typedef int LONG;

#pragma pack(push, 1)  // упаковка памяти, иначе структура будет занимать 16 байт, а не 14, как положено
struct BITMAPFILEHEADER {
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
};
#pragma pack(pop)

struct BITMAPINFOHEADER {
	DWORD  biSize;
	LONG   biWidth;
	LONG   biHeight;
	WORD   biPlanes;
	WORD   biBitCount;
	DWORD  biCompression;
	DWORD  biSizeImage;
	LONG   biXPelsPerMeter;
	LONG   biYPelsPerMeter;
	DWORD  biClrUsed;
	DWORD  biClrImportant;
};

void readBmpHeader(string fname) {
	ifstream f;
	BITMAPFILEHEADER fHead;
	BITMAPINFOHEADER imHead;

	f.open(fname);
	if (!f.is_open()) {
		cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
		f.close();
		return;
	}
	f.read((char*)&fHead, sizeof(fHead));
	f.read((char*)&imHead, sizeof(imHead));
	f.close();

	cout << "----------------- BMP file header reader ----------------- \n";
	cout << fname << endl;
	cout << "Size of types are (in bytes, / must be):" << endl;
	cout << "WORD  " << sizeof(WORD) << " /2" << endl;
	cout << "DWORD " << sizeof(DWORD) << " /4" << endl;
	cout << "LONG  " << sizeof(LONG) << " /4" << endl;
	cout << "BITMAPFILEHEADER " << sizeof(BITMAPFILEHEADER) << " /14" << endl;
	cout << "BITMAPINFOHEADER " << sizeof(BITMAPINFOHEADER) << endl;

	cout << endl;

	cout << "File info: ["
		<< fHead.bfType << " == 19778, "
		<< fHead.bfSize << " bytes, "
		<< fHead.bfReserved1 << ", "
		<< fHead.bfReserved2 << ", "
		<< fHead.bfOffBits << "] " << endl;

	cout << "Image info: ["
		<< imHead.biSize << " bytes, ("
		<< imHead.biWidth << "x"
		<< imHead.biHeight << ") px, "
		<< imHead.biBitCount << " bits] " << endl;

	cout << endl;
}


void readBmpImageHeader(string fname) {
	ifstream f;
	BITMAPINFOHEADER imHead;

	f.open(fname);
	if (!f.is_open()) {
		cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
		f.close();
		return;
	}

	cout << "----------------- BMP file Image header reader via seek----------------- \n";
	cout << fname << endl;
	cout << "BITMAPFILEHEADER size is 14 bytes" << endl;
	cout << "BITMAPINFOHEADER " << sizeof(BITMAPINFOHEADER) << endl;

	cout << "Current position in file " << f.tellg() << endl;
	cout << "Seek 14 bytes" << endl;
	f.seekg(14);  // смещаемся на 14 байт вперёд
	cout << "Current position in file " << f.tellg() << endl;

	f.read((char*)&imHead, sizeof(imHead));
	f.close();

	cout << endl;

	cout << "Image info: ["
		<< imHead.biSize << " bytes, ("
		<< imHead.biWidth << "x"
		<< imHead.biHeight << ") px, "
		<< imHead.biBitCount << " bits] " << endl;

	cout << endl;
}

int main()
{
	// init
	cout.precision(5);
	srand(5);
	setlocale(LC_ALL, "Russian");

	const int len = 20;
	Plane planes[len];

	showTask();

	cout << endl;

	cout << "Начальный массив:\n";
	initPlanes(planes, len);
	writeTextFile(planes, len);
	showPlanes(planes, 5);

	cout << "Новый массив:\n";
	initPlanes(planes, len);
	showPlanes(planes, 5);

	cout << "Считанный массив:\n";
	openTextFile(planes, len);
	showPlanes(planes, 5);

	cout << "Бинарный файл.\n";
	writeBinFile(planes, len);

	cout << "Новый массив:\n";
	initPlanes(planes, len);
	showPlanes(planes, 5);

	cout << "Считанный массив:\n";
	openBinFile(planes, len);
	showPlanes(planes, 5);

	readPdfHeader("file.pdf");

	readBmpHeader("microsoft.bmp");

	return 0;
}
