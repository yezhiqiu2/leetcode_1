#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int reverse( long long x) 
{
	int result[10] = { 0 };
	int boundary[10] = { 2,1,4,7,4,8,3,6,4,8 };
	int i = 0;
	 long long mid;
	int j;
	int bz;
	if (x > 0)
	{
		bz = 1;
		mid = x;
	}
	else
	{
		bz = 0;
		mid = 0-x;
	}
	for (i = 0; i < 10; i++)
	{
		result[i] = mid % 10;
		mid = mid / 10;
	}
	for (i = 0; i < 10; i++)
	{
		if (result[9] == 0)
		{
			for (j = 0; j < 9; j++)
				result[9 - j] = result[8 - j];
			result[0] = 0;
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (i < 9)
		{
			if (result[i] > boundary[i])
				return 0;
			else if (result[i]<boundary[i])
				break;
		}
		else
		{
			if (x > 0)
			{
				if (result[i] > boundary[i]-1)
					return 0;
			}
			else
			{
				if (result[i] > boundary[i])
					return 0;
			}
		}
	}
	for (i = 0, mid = 0; i < 10; i++)
	{
		mid = result[i] + mid * 10;
	}

	if (bz>0)
		return (int) mid;
	else
		return (int)( mid);
}
void main()
{
	
	int t;
	long long a;
	a = 1563847412;
	t = reverse(a);

	
	system("pause");
}