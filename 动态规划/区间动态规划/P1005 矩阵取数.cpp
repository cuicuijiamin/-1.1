//高精+区间dp
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
struct HP
{
	int s[MAXN];
	int len;//存放数的长度
	HP()
	{
		memset(s, 0, sizeof(s));//初始0
		len = 1;
	}
	HP operator=(const char* str)
	{
		len = strlen(str);
		for (int i = 0; i<len; ++i)
			s[i] = str[len - i - 1] - '0';
		return *this;
	}
	HP operator=(int num)
	{
		char s[MAXN];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	void clean()
	{
		while (len>1 && s[len - 1] == 0)len--;
	}
	HP operator+(const HP& b)
	{
		HP c;
		c.len = 0;
		int g = 0;
		for (int i = 0; g || i<max(len, b.len); ++i)
		{
			int x = g;
			if (i<len)x += s[i];
			if (i<b.len)x += b.s[i];
			g = x / 10;
			c.s[c.len++] = x % 10;
		}
		c.clean();
		return c;
	}
	HP operator*(const HP& b)
	{
		HP c;
		c.len = len + b.len;//最最大的一个长度，肯定是够的
		for (int i = 0; i<len; ++i) //先乘
		{
			for (int j = 0; j<b.len; ++j)
			{
				c.s[i + j] += s[i] * b.s[j];//竟然忘写加号，调了1天。。。 
			}
		}
		for (int i = 0; i<c.len - 1; ++i)
		{
			c.s[i + 1] += c.s[i] / 10;//加上进位
			c.s[i] %= 10;
		}
		c.clean();//除掉多的那些位子
		return c;
	}
	string str()const//转字符串的函数
	{
		string res = "";
		for (int i = len - 1; i >= 0; --i)res += (char)(s[i] + '0');
		if (res == "")return "0";
		else return res;
	}
};
istream& operator>>(istream& in, HP& x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}
ostream& operator<<(ostream& out, HP& x)
{
	out << x.str();
	return out;
}
HP max(const HP &a, const HP &b)
{
	if (a.len > b.len)
		return a;
	else if (a.len < b.len)
		return b;
	for (int i = a.len-1; i >= 0; i--)
	{
		if (a.s[i] > b.s[i])
			return a;
		else if (a.s[i] < b.s[i])
			return b;
	}
	return a;
} //比较取最大值

HP HH[85];
HP a[85][85];
HP dp[85][85];//表示区间变为[i,j]的最大得分
void getPowerHP()
{
	HH[1] = 2;
	HP t;
	t = 2;
	for (int i = 2; i<85; ++i)
	{
		HH[i] = HH[i - 1] * t;
	}
}

int main()
{
//	freopen("P1005_5.in","r",stdin);
//	freopen("out1.txt","w",stdout);
	getPowerHP();
	int n, m;
	cin >> n >> m;//n行m列
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}
	HP ans;
	for (int h = 1; h <= n; ++h) //h表示遍历到的行
	{
		memset(dp, 0, sizeof(dp));
		int tmp = 1;
		for (int len = m - 1; len >= 1; --len) //遍历区间的长度
		{
			for (int i = 1; i <= m+1-len; ++i) //区间的起点
			{
				int j = i + len - 1;//区间的终点
				dp[i][j] = max(dp[i][j], max(dp[i][j + 1] + a[h][j + 1] * HH[tmp], dp[i - 1][j] + a[h][i - 1] * HH[tmp]));
			}
			tmp++;
		}

		//打印dp
//		for (int i = 1; i <= m; ++i)
//		{
//			for (int j = i; j <= m; ++j)
//				cout << "dp " << i << " " << j << " " << dp[i][j] << endl;
//		}
		HP mm;
		mm = 0;
		for (int i = 1; i <= m; ++i)
		{
			mm = max(mm, dp[i][i] + a[h][i] * HH[m]);
		}
//		cout<<mm<<endl;
		ans = ans + mm;
	}
	cout << ans << endl;
}
