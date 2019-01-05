/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入 : "babad"
	输出 : "bab"
	注意 : "aba" 也是一个有效答案。


	示例 2：
	输入 : "cbbd"
	输出 : "bb"
	*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int max_odd(char* s,int n,int len)
{
	int i=0;
	for (i=0; n - i >= 0 && n + i < len; i++)
	{
		if (*(s + n - i) != *(s + n + i)) 
			return i;
	}
	return i;
}
int max_even(char* s, int n, int len)
{
	int i=0;
	for (i = 0; n - i >= 0 && n + 1 + i < len; i++)
	{
		if (*(s + n - i) != *(s + n + 1 + i))
			return i ;
	}
	return i;
}
char* longestPalindrome(char* s)
{
	int len;
	int pos, l,r,i,isodd,result_len;
	static char* result;
	pos = 0;
	l = 1;
	isodd = 0;
	result_len = 0;
	len = strlen(s);
	if (len < 2)
		return s;
	else
	{
		for (i = 0; i < len; i++)
		{
			r = max_odd(s, i, len);
			if ( r>= l)
			{
				l = r;
				pos = i;
				isodd = 1;
			}
		}
		for (i = 0; i < len - 1; i++)
		{
			r = max_even(s, i, len);
			if (r >= l)
			{
				l = r;
				pos = i;
				isodd = 0;
			}
		}
		if (isodd > 0)
			result_len = 2 * l ;			
		else
			result_len = 2 * l + 1;
		result = malloc(sizeof(char)*(result_len));
		for(i=0;i<result_len-1;i++)
			*(result+i) = *(s + pos+1 - l+i);
		*(result + i) = '\0';
		return result;
	}
}
void main()
{
	char* a;
	char* b;
	a = "ac";
	b = longestPalindrome(a);
	printf(b);
	system("pause");
}