#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int a[7][7];//地图
int goal[7][7] =
{
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 1 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 0, 2, 1, 1 },
	{ 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 0 }
};
int dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
int maxDep;
int h()//估价函数
{
	int res = 0;
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			if (a[i][j] != goal[i][j]&&a[i][j]!=2)//
			{
				res++;
			}
		}
	}
	return res;
}
int judge = 0;
void IDA_star(int x, int y, int step)
{
	//cout << "现在的x,y" << x << "\t" << y << "\t"<<step<<endl;
	if (step == maxDep)//step表示第step步时的状态
	{	
		if (h() == 0)
			judge = 1;
		return;
	}
	if (h() + step > maxDep) return;
	for (int i = 0; i < 8; i++)//遍历8个方向 
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx<1 || xx>5 || yy<1 || yy>5)continue;//结束
		swap(a[x][y], a[xx][yy]);
		IDA_star( xx, yy, step + 1);
		swap(a[x][y], a[xx][yy]);
	}
}

int main()
{
	//	freopen("in.txt","r",stdin);
	//	freopen("out.txt","w",stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		for (int i = 1; i <= 5; ++i)
		{
			string s;
			cin >> s;
			for (int j = 1; j <= 5; ++j)
			{
				if (s[j-1] == '*')a[i][j] = 2, x = i, y = j;//记录起点即为空白格子
				else a[i][j] = s[j-1] - '0';
			}
		}
		judge = 0;
		for (maxDep = 0; maxDep <= 15; maxDep++)
		{
			IDA_star(x, y, 0);
			if (judge)
			{
				cout << maxDep << endl;
				goto my;
			}
		}
		cout << -1 << endl;
	my:;
	}
	return 0;
}
