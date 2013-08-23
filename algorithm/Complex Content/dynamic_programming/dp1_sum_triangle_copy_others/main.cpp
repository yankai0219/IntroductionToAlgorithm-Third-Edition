/*
// Study at home 2013/08/05

Original Author: Tanky Woo
Blog:   www.WuTianQi.com
Description: 动态规划之三角形求值问题
*/
#include <iostream>
#include <string.h>
using namespace std;
 
int map[6][6] = 
{
	{0, 0, 0, 0, 0, 0},
	{0, 7, 0, 0, 0, 0},
	{0, 3, 8, 0, 0, 0},
	{0, 8, 1, 0, 0, 0},
	{0, 2, 7, 4, 4, 0},
	{0, 4, 5, 2, 6, 5}
};
 
int f[6][6];
 
int _max(int a, int b)
{
	if(a >= b)
		return a;
	return b;
}
 
int main()
{
	memset(f, 0, sizeof(f));
	for(int i=0; i<6; ++i)
		f[5][i] = map[5][i];
	for(int i=4; i>=1; --i)
		for(int j=1; j<=i; ++j)
			f[i][j] = _max(f[i+1][j], f[i+1][j+1]) + map[i][j];
	for(int i=1; i<=5; ++i)
	{
		for(int j=1; j<=5; ++j)
		{
			cout.width(2);
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	cout << f[1][1] << endl;
}
