int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int maxAreaa(int* height, int heightSize)
{
	int i;
	int header, tiller,max,mid;
	mid = 0;
	max = 0;
	for (i = 1,header=0,tiller=heightSize-1; i < heightSize; i++)
	{
		mid = (tiller - header)*min(*(height + header), *(height + tiller));
		if (mid > max)
			max = mid;
		if (*(height + header) < *(height + tiller))
			header++;
		else
			tiller--;
	}
	return max;
}
int maxArea(int* height, int heightSize) 
{
	int i,j;
	int mid_area,mid_max_area,mid_height,mid_max_height;
	mid_area = 0;
	mid_max_area = 0;

	for (i = 1; i < heightSize; i++)
	{
		mid_height = 0;
		mid_max_height = 0;
		for (j = 0; j + i < heightSize; j++)
		{
			mid_height = min(*(height + j), *(height + j + i));
			if (mid_height > mid_max_height)
			{
				mid_max_height = mid_height;
			}
		}
		mid_area = mid_max_height*i;
		if (mid_max_area < mid_area)
			mid_max_area = mid_area;
	}
	return mid_max_area;
}
void main11()
{

	int t;
	char* a;
	a = intToRoman(3350);


	system("pause");
}