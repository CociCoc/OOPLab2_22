#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
void task1() {
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 
    cout << " Calculation of expressions using bitwise operations  \n"
        int a, b, c, d, x, y;
    cout << "input int number a, b, c, d " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;
    x = (((a << 4) + (a << 1) + (d << 8) + (d << 5) + (d << 4) + (d << 3)) >> 9) - ((b << 7) - (b << 2) - (b << 1)) + ((c << 7) - (c << 2) - c);
    y = ((18 * a + 312 * d) / 512) - (b * 122) + (c * 123);
    cout << "x" << x << endl;
    cout << "y" << y;;
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";
        char s[8][9], ch;
	char so[8][9];
	unsigned short sh_dat[64], sd2[64], r, w;
	char st[9];
	ifstream ifs("in.dat");
	if (!ifs) {
		cout << "File in.dat not open" << endl; return -1;
	}
	ofstream ofs("out.dat");
	ofstream ofsb("outb.dat", ios::out | ios::binary);
	unsigned short i, j, l, b, k, t;
	for (i = 0; i < 16; i++)
	{
		ifs.get(s[i], 9, '\0'); ifs.get(ch);
	}
	j = 0;
	for (i = 0; i < 16; i++)
		for (l = 0; l < 4; l++)
		{
			r = i; 
				// 0000 0000 0000 0___ <- i
					w = l << 3;
						r |= w; 
			// 0000 0000 00__ _000 <- l
				b = 0; t = 1;
			for (k = 0; k < 6; k++) // обчислення біта парності
			{
				if (r & t) {
					if (b == 0) b = 1; else b = 0;
				}
				t <<= 1;
			}
				w = 1 << 6;
			if (b) r |= w; // 0000 0000 0_000 0000 <- b
				w = s[i][l];
					w <<= 7;
						r |= w;
			if (r & 0x4000) r |= 0x8000;
				sh_dat[j] = r;
					j++;
						ofs << hex << r << ' ';
							cout << hex << r << endl;
		}
	ofsb.write((char*)sh_dat, 64 * sizeof(unsigned short));
		ofsb.close();
			ifs.close();
	//for (i = 0;i < 64;i++) sh_dat[i] = 0;
		ifs.open("outb.dat", ios::in | ios::binary);
			ifs.read((char*)sd2, 64 * sizeof(unsigned short));
		short indi, indj;
	for (i = 0; i < 64; i++)
	{
		r = sd2[i];
			indj = r & 0x0038;
				indj >>= 3; // 0000 0000 0011 1000 = 0x0038
					indi = r & 0x0007; // 0000 0000 0000 0111 = 0x0007
				w = r & 0x7f80; // 0111 1111 1000 0000 = 0x7f80 
			w >>= 7;
		ch = w;
			so[indi][indj] = ch;
	}
	for (i = 0; i < 16; i++) {
		for (l = 0; l < 4; l++)
			cout << so[i][l];
		cout << endl;
	}
	return 0;

}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
    char s[8][9], ch;
	char so[8][9];
	unsigned short sh_dat[64], sd2[64], r, w;
	char st[9];
	ifstream ifs("in.dat");
	if (!ifs) {
		cout << "File in.dat not open" << endl; return -1;
	}
	ofstream ofs("out.dat");
	ofstream ofsb("outb.dat", ios::out | ios::binary);
	unsigned short i, j, l, b, k, t;
	for (i = 0; i < 16; i++)
	{
		ifs.get(s[i], 9, '\0'); ifs.get(ch);
	}
	j = 0;
	for (i = 0; i < 16; i++)
		for (l = 0; l < 4; l++)
		{
			r = i; 
				// 0000 0000 0000 0___ <- i
					w = l << 3;
						r |= w; 
			// 0000 0000 00__ _000 <- l
				b = 0; t = 1;
			for (k = 0; k < 6; k++) // обчислення біта парності
			{
				if (r & t) {
					if (b == 0) b = 1; else b = 0;
				}
				t <<= 1;
			}
				w = 1 << 6;
			if (b) r |= w; // 0000 0000 0_000 0000 <- b
				w = s[i][l];
					w <<= 7;
						r |= w;
			if (r & 0x4000) r |= 0x8000;
				sh_dat[j] = r;
					j++;
						ofs << hex << r << ' ';
							cout << hex << r << endl;
		}
	ofsb.write((char*)sh_dat, 64 * sizeof(unsigned short));
		ofsb.close();
			ifs.close();
	//for (i = 0;i < 64;i++) sh_dat[i] = 0;
		ifs.open("outb.dat", ios::in | ios::binary);
			ifs.read((char*)sd2, 64 * sizeof(unsigned short));
		short indi, indj;
	for (i = 0; i < 64; i++)
	{
		r = sd2[i];
			indj = r & 0x0038;
				indj >>= 3; // 0000 0000 0011 1000 = 0x0038
					indi = r & 0x0007; // 0000 0000 0000 0111 = 0x0007
				w = r & 0x7f80; // 0111 1111 1000 0000 = 0x7f80 
			w >>= 7;
		ch = w;
			so[indi][indj] = ch;
	}
	for (i = 0; i < 16; i++) {
		for (l = 0; l < 4; l++)
			cout << so[i][l];
		cout << endl;
	}
	return 0;
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";
    int multiply(int a, int b)
{
    // прапор для збереження
    bool isNegative = false;

    // якщо обидва числа негативні, робимо обидва числа
    // позитивно, оскільки результат все одно буде позитивним
    if (a < 0 && b < 0) {
        a = -a, b = -b;
    }

    // якщо тільки `a` негативне, робимо його позитивним
    // і помічаємо результат як негативний
    if (a < 0) {
        a = -a, isNegative = true;
    }

    // якщо тільки `b` негативне, робимо його позитивним
    // і помічаємо результат як негативний
    if (b < 0) {
        b = -b, isNegative = true;
    }

    // ініціалізуємо результат
    int result = 0;

    // працювати до тих пір, поки `b` не стане 0
    while (b)
    {
        // якщо `b` непарне, додати `b` до результату
        if (b & 1) {
            result += a;
        }

        // помножити `a` на 2
        a = a << 1;

        // ділимо `b` на 2
        b = b >> 1;
    }

    return (isNegative) ? -result : result;
}

int main()
{
    cout << multiply(3, 4) << " " << multiply(-3, -4) << " "
        << multiply(-3, 4) << " " << multiply(3, -4);

    return 0;
}

}


