// https://ac.nowcoder.com/acm/contest/46812/F
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mpow(int k){
	ll ans = 1;
	ll a = 2;
	while (k){
		if (k & 1) ans *= a;
		k >>= 1;
		a = a*a;
	}
	return ans;
}
void dfs(ll &q, ll &z, ll &h, int dep, ll qu){
	if (qu == z)//查找到
	{
		return;
	}
	ll lowbit = mpow(dep);
	if (qu<z){//往左走 
		z = z - lowbit / 2;
		q = q + 1;
		h = h - lowbit;
		dfs(q, z, h, --dep, qu);
		return;
	}
	else {//往右走
		z = z + lowbit / 2;
		q = q + lowbit;
		h = h - 1;
		dfs(q, z, h, --dep, qu);
		return;
	}
}
int query[100005];
int main()
{
	int k, q;
	cin >> k >> q;
	ll N = mpow(k);
	for (int i = 1; i <= q; ++i){
		ll t;
		cin >> t;
		if (t == N){ cout << 1 << " " << N << " " << N << endl; continue;}
		ll q = 2, z = N / 2, h = N - 1;
		dfs(q, z, h, k - 1, t);//传参为前，中，后序结果 要查找的值
		cout << q << " " << z << " " << h << endl;
	}
}
