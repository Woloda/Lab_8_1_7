#include <iostream>
#include <Windows.h>

using namespace std;

char* InsertBefore(char* string, const char* para, const char* vstawka, bool g);
char* Delete(char* string, const char* para);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char lit_r[30] = "SQsdgdgQShhQQQSdhd";
	cout << "Сфомований літерний рядок: " << endl << endl << lit_r << endl << endl;
	char para[] = "SQ";
	char para1[] = "QS";
	char zamina[] = "*";

	InsertBefore(lit_r, para, zamina, true);
	InsertBefore(lit_r, para1, zamina, false);
	Delete(lit_r, para);
	Delete(lit_r, para1);

	cout << "Модифікований літерний рядок: " << endl << endl << lit_r << endl << endl;
	return 0;
}

char* InsertBefore(char* string, const char* para, const char* vstawka, bool g)
{
	char* d = new char[2 * strlen(string) + 1];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*d = 0;
	int L;
	while (p = strstr(string + pos1, para))
	{
		pos2 = p - string + 1 + 1;
		strncat_s(d, 2 * strlen(string) + 1, string + pos1, pos2 - pos1 - 1 - 1);
		L = strlen(d);
		d[L] = *vstawka;
		d[L + 1] = *vstawka;
		d[L + 2] = *vstawka;
		d[L + 3] = *para;
		if (g == true)
			d[L + 4] = 'Q';
		else
			d[L + 4] = 'S';
		d[L + 5] = '\0';
		pos1 = pos2;
	}

	strcat_s(d, 2 * strlen(string) + 1, string + pos1);
	strcpy_s(string, strlen(d) + 1, d);
	return d;
}

char* Delete(char* string, const char* para)
{
	char* t = new char[2 * strlen(string) + 1];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strstr(string + pos1, para))
	{
		pos2 = p - string + 2;
		strncat_s(t, 2 * strlen(string) + 1, string + pos1, pos2 - pos1 - 2);
		pos1 = pos2;
	}
	strcat_s(t, 2 * strlen(string) + 1, string + pos1);
	strcpy_s(string, strlen(t) + 1, t);
	return t;
}