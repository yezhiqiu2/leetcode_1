#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* get_roman(int num, char a, char b,char c)
{
	static char* rst;
	rst = malloc(sizeof(char) * 5);
	switch (num)
	{
	case 0:
		*rst = '\0';
		break;
	case 1:
		*rst = a;
		*(rst+1) = '\0';
		break;
	case 2:
		*rst = a;
		*(rst + 1) = a;
		*(rst + 2) = '\0';
		break;
	case 3:
		*rst = a;
		*(rst + 1) = a;
		*(rst + 2) = a;
		*(rst + 3) = '\0';
		break;
	case 4:
		*rst = a;
		*(rst + 1) = b;
		*(rst + 2) = '\0';
		break;
	case 5:
		*rst = b;
		*(rst + 1) = '\0';
		break;
	case 6:
		*rst = b;
		*(rst + 1) = a;
		*(rst + 2) = '\0';
		break;
	case 7:
		*rst = b;
		*(rst + 1) = a;
		*(rst + 2) = a;
		*(rst + 3) = '\0';
		break;
	case 8:
		*rst = b;
		*(rst + 1) = a;
		*(rst + 2) = a;
		*(rst + 3) = a;
		*(rst + 4) = '\0';
		break;
	case 9:
		*rst = a;
		*(rst + 1) = c;
		*(rst + 2) = '\0';
		break;
	default:
		break;
	}
	return rst;
}
char* intToRoman(int num) 
{
	int q, b, s, y;
	static char* rst;
	char* qstr;
	char* bstr;
	char* sstr;
	char* ystr;
	qstr = malloc(sizeof(char) * 5);
	bstr = malloc(sizeof(char) * 5);
	sstr = malloc(sizeof(char) * 5);
	ystr = malloc(sizeof(char) * 5);
	rst = malloc(sizeof(char) * 20);
	*rst = '\0';
	q = num / 1000;
	b = (num - 1000 * q) / 100;
	s = (num - 1000 * q - 100 * b) / 10;
	y = num - 1000 * q - 100 * b - 10 * s;
	ystr = get_roman(y, 'I', 'V', 'X');
	sstr = get_roman(s, 'X', 'L', 'C');
	bstr = get_roman(b, 'C', 'D', 'M');
	qstr = get_roman(q, 'M', 'M', 'M');

	strcat(rst, qstr);
	strcat(rst, bstr);
	strcat(rst, sstr);
	strcat(rst, ystr);
	return rst;

}
void main()
{

	int t;
	char* a;
	a = intToRoman(3350);


	system("pause");
}