#define true 1
#define false 0
#define bool int

bool isPalindrome(int x) 
{
	int a[20] = { 0 };
	int i,j,mid;
	if (x < 0)
		return false;
	else if (x == 0)
		return true;
	else
	{
		for (i = 0,mid=x; i < 20; i++)
		{
			a[i] = mid % 10;
			mid = (mid - a[i]) / 10;
		}
		for (i = 19; i >=0; i--)
		{
			if (a[i] != 0)
				break;
		}
		for (j = 0; j < i / 2+1; j++)
		{
			if (a[j] != a[i - j])
				return false;
		}
		return true;
	}

}
void main9()
{

	int t;
	char* a;
	a = isPalindrome(3333);
	a = 0;

	system("pause");
}