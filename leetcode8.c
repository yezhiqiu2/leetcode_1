int chartoint(char s)
{
	if (s == ' ')
		return -2;
	else if (s == '-')
		return -1;
	else if (s == '+')
		return -3;
	else if (s >= '0' && s <= '9')
		return s - '0';
	else
		return 10;
}
int abs(int a)
{
	if (a > 0)
		return a;
	else
		return -a;
}
int myAtoi(char* str) 
{
	int i = 0;
	int valid = 0;
	int mid;
	int rst=0;
	int sz = 1;
	mid = chartoint(*(str));
	while (mid!=10)
	{
		if (valid == 0)
			if (mid == -2)
			{
				i++;
				mid = chartoint(*(str + i));
				continue;
			}
			else if (mid == -3)
			{
				i++;
				mid = chartoint(*(str + i));
				valid = 1;
				continue;
			}
			else if(mid==-1)
			{
				sz =  -1;
				valid = 1;
			}
			else
			{
				rst = mid;
				valid = 1;
			}
		else
		{
			if (mid < 0)
				break;
			else
			{
				if (rst > 214748364 || (rst == 214748364 && mid > 7))
					return 214748364;
				else if (rst < -214748364 || (rst == -214748364 && mid > 8))
					return -214748364;
				else
					rst = sz*(abs(rst) * 10 + mid);
			}
		}



		i++;
		mid = chartoint(*(str + i));
	}
	return rst;
}
void main()
{
	char a[] = "  -42";
	int t;
	t = myAtoi(a);
}