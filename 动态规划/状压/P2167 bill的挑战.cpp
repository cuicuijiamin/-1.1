#include <iostream>
#include<cstring>
#include<string>
using namespace std;
const int MOD = 1000003;
int f[55][1 << 15]; //前i个字符  第i个字符的匹配状态为j   的匹配数
int ma[55][26];     //第i个字符为字母j 的状态
int g(int j){
	int num = 0;
	while (j){
		if (j & 1)num++;
		j >>= 1;
	}
	return num;
}
void sol()
{
	memset(f, 0, sizeof(f));
	memset(ma, 0, sizeof(ma));
	string s[17];
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		cin >> s[i];
		for (int j = 0; j < s[i].size(); ++j) //更新match数组
		{
			for (int k = 0; k < 26; ++k)
			{
				ma[j + 1][k] <<= 1;
				if (s[i][j] == '?' || s[i][j]-'a' == k)ma[j + 1][k] += 1;
			}
		}
	}
	if (k>n){
		cout << 0 << endl;
		return;
	}
	int len = s[1].size(); //长度
	int all = (1 << n) - 1;
	f[0][all] = 1;
	for (int i = 0; i < len; ++i){ //遍历字符
		for (int j = 0; j <= all; ++j) //遍历i位的所有状态
		{
			if (f[i][j])
			{
				for (int k = 0; k < 26; ++k) //遍历i+1位的字符
				{
					f[i + 1][ma[i + 1][k] & j] += f[i][j];
					f[i + 1][ma[i + 1][k] & j] %= MOD;
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= all; ++j)
	{
		if (g(j) == k)
			ans = (ans + f[len][j]) % MOD;
	}
	cout << ans << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--){
		sol();
	}
}
