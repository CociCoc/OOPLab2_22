#include <iostream>
#include <fstream>
using namespace std;
#include <clocale>
#include <Windows.h>
#include "Examples.h"
enum  ConsoleColor //: unsigned int
{							//0000 IRGB  
	Black = 0x00,			//0000 0000
	Blue = 0x01,			//0000 0001
	Green = 0x02,			//0000 0010
	Cyan = 0x03,			//0000 0011
	Red = 0x04,				//0000 0100
	Magenta = 0x05,			//0000 0101
	Brown = 0x06,			//0000 0110
	LightGray = 0x07,		//0000 0111 
	DarkGray = 0x08,		//0000 1000
	LightBlue = 0x09,		//0000 1001
	LightGreen = 0x0a,		//0000 1010
	LightCyan = 0x0b,		//0000 1011
	LightRed = 0x0c,		//0000 1100
	LightMagenta = 0x0d,	//0000 1101
	Yellow = 0x0e,			//0000 1110
	White = 0x0f			//0000 1111
};
void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, (WORD)((background << 4) | text));
}

void MenuExamples() {
	SetColor(Blue, Black);
	cout << "     Examples   \n";
	SetColor(Green, Black);
	cout << "    1.  ������� �������� ������ ����� � ��������� ������� � ������� \n";
	cout << "    2.  ������� ���������� ������ �������������� �i���� ���i���i ������i�. \n";
	cout << "    3.   \n";
	cout << "    4.   \n";
	cout << "    5.   \n";
	cout << "    6.  Exit \n";
}
void Examples()
{   // Examples of tasks using bitwise operations
    // �������� ����� � ������������� �������� ��������
	setlocale(LC_CTYPE, "ukr");  // 
	
    cout << " Examples of tasks using bitwise operations \n";
	cout << " �������� ����� � ������������� ���i����� ������i� \n";
	char ch = '5';
	do {
		system("cls");
		MenuExamples();
		ch = cin.get();

		cin.get();

		switch (ch) {
		case '1': Example1();   break;
		case '2': Example2();   break;
		case '3': Example3();   break;
		case '4': Example4();   break;
		case '5':  Example5(); break;
		case '6': SetColor(White, Black); return ;
		}
		cout << " Press any key and enter\n";
		ch = cin.get();
	} while (ch != '6');
	SetColor(White, Black);
	return ;
}

#include <clocale>
//  ������� �������� ������ ����� � ��������� ������� � �������
void Example1()
{
	char out[17];
	int i, in, ix, n = 0;
	double x;
	
	cout << " ����i�� �i�� ������� �����:";
	cin >> in;
	if (in != 0) {
		x = in;
		do {
			x = x / 2.;
			ix = (int)x;
			if ((x - ix) != 0) out[n] = '1';
			else out[n] = '0';
			n++;
			x = ix;
		} while (x >= 1);
	}
	cout << " ���������: \n";
	for (i = n - 1; i >= 0; i--)
		cout << out[i];
	cout << endl;
	cin.get();

	return;
}
/*
* ������� ���������� ������ �������������� ����� ������ ��������.
* ����� : x = 33 * a + (a * 16 � b * 17) / 8 + (15 * b + 300) / 128.
*
*/
void Example2()
{
	int a, b, x, y;
	cout << "������� ���������� ������ �������������� �i���� ���i���i ������i�.\n";
	cout << "����� : x = 33 * a + (a * 16 � b * 17) / 8 + (15 * b + 300) / 128. \n";
	cout << " ����i�� a  b ";
	cin >> a >> b;
	x = a + (a << 5) + (((a << 4) - b - (b << 4)) >> 3) + (((b << 4) - b + 300) >> 7);
	y = a * 33 + (a * 16 - b * 17) / 8 + (15 * b + 300) / 128;
	cout << "  x=" << x << "  y=" << y << " a=" << a << "  b=" << b << endl;
	cin.get();
	cin.get();
	return;
}
/*
������ ����� ASCII (��������� �����), ���� ���������� � 64 ����. 
�������� ������� ���������� �� ������������� �������� ������. 
����� ��� ��������� ����� ������ ���� �������� � �������, 
���� ���������� � ���� ����� �� �� ���������:
  -  � ���� 0-3 ������ �������, ����� ��� 4-7 ASCII - ���� ����� (4 ���) - ����,
  -  � ���� 4-10 ������� ����� � ����� (7 ���) - ���,
  -  � ���� 12-15 ������� �������, ����� ��� 0-3 ASCII - ���� ����� (4 ���) - ����,
  -  11 �� � �� ������� ���������� ������ (1 ��)  -��.
  -    15 14 13 12  11  10 09 08 07 06 05 04 03 02 01 00
       | ����    | |��| |     ���          | |   ����  |    
*/
void MyEncryption(char InS[64], unsigned short OutCoding[64])
{
	unsigned char c;
	unsigned short r, t, i, b;
	short j;
    for (i = 0; i < 64; i++)            //
	{
		r = 0;                        // 0000 0000 0000 0000
		c = InS[i];                     // s - 0x73 = 0111 0011
		t = c;
		r |= t >> 4;                  // 0000 0000 0000 0111
		r |= i << 4;                  // 0000 0000 0101 0111  if i=5 -> 0000 0000 0000 0101
		t = c;
		r |= t << 12;                 // 0011 0000 0101 0111  if i=5 0000 0000 0000 0101
		t = 1;
		b = 0;
		for (j = 0; j < 16; j++)         // ���������� ��� �������
		{
			if (r & t) {
				if (b == 0) b = 1; else b = 0;
			}
			t <<= 1;
		}
		r |= b << 11;                    // 0011 0000 0101 0111 if i=5 0000 0000 0000 0101
		OutCoding[i] = r;
	}
}
int MyDecryption(char OutS[64], unsigned short InCoding[64]) {
	
	unsigned char c;
	unsigned short r, t, i, b, p, w;
	short j;
	for (i = 0; i < 64; i++)            //
	{
		// �������� �������
		r = InCoding[i];
		t = r & 0b1111011111111111;      //  0xf7ff			1111 0111 1111 1111
		p = r & 0b0000100000000000;      //  0x0800			0000 1000 0000 0000
		w = 1;
		b = 0;
		for (j = 0; j < 16; j++)         // ���������� ��� �������
		{
			if (r & w) {
				if (b == 0) b = 1; else b = 0;
			}
			w <<= 1;
		}
		p >>= 11;
		if (p != b)  return -i;
		t = r & 0b1111000000000000;  // 0xf000
		t >>= 12;
		w = r & 0b0000000000001111;  // 0x000f
		w <<= 4;
		t |= w;
		p = r & 0b0000011111110000;  // 0x07f
		p >>= 4;
		OutS[p] = (unsigned char)t;
	}

	return 1;
}

void Example3() {
	char S[65];
	unsigned short Rez[64];
	unsigned short i, f;
	cout << " Input string from file press 1\n ";
	cin >> f;
	if (f == 1) {
		ifstream ifs("in.txt");
		if (!ifs) {
			cout << "File in.txt not open" << endl; f = 2;
		}
		else {
			ifs.get(S, 64);
			ifs.close();
		}
		}
	if(f!=1) {
		cout << " Input string (size <=64) \n";
		cin.get(S, 64);
	}
	int n = strlen(S);
	for (int i = n; i < 64; i++) S[i] = '\0';


	MyEncryption(S, Rez);

	for (i = 0; i < 64; i++)
		cout << hex << Rez[i] << endl;
	ofstream ofsb("outb.bin", ios::out | ios::binary);
	if (!ofsb) {
		cout << "File outb.bin not open" << endl;
	}
	else {
		ofsb.write((char*)Rez, 64 * sizeof(unsigned short));
		ofsb.close();
		cout << "Data write to outb.bin " << endl;
	}
	cin.get();
}
void Example4() {
	char S[65];
	unsigned short InBin[64];
	ofstream ofs("out.txt");
	if (!ofs) {
		cout << "File out.txt not open" << endl;
		return;
	}
	ifstream ifsb("outb.bin", ios::in | ios::binary);
	if (!ifsb) {
		cout << "File outb.bin not open" << endl;
		return;
	}
	else {
		ifsb.read((char*)InBin, 64 * sizeof(unsigned short));
		ifsb.close();
		cout << "Data read from outb.bin " << endl;

	}
	int r;
	r = MyDecryption(S, InBin);
	if (r < 1) {
		cout << "Error  read  " << r << " row " << endl;
	}
	cout << "String  " << S << endl;
	ofs << S << endl;
}


void Example5() {

}