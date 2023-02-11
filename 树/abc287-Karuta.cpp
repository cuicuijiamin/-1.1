//补题:树
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int son[N][26],cnt[N],idx;
string s[N];
void insert(string str)
{
	int cur = 0;
	for (int i = 0; i<str.size(); i ++ )
	{
		int u = str[i] - 'a';
		if (!son[cur][u]) son[cur][u] = ++ idx;//idx是节点的唯一性标识
		cur = son[cur][u];//获取现在位置坐标
		cnt[cur]++;//这个id位的节点+1
	}
}

int query(string str)
{
	int cur = 0;
	for (int i = 0; i<str.size(); i ++ )
	{
		int u = str[i] - 'a';
		cur = son[cur][u];
		if (cnt[cur]<2) return i;
	}
    //此时就是str整个的长度
	return str.size();
}
int main(){
    int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		insert(s[i]);
	} 
	for(int i=0;i<n;i++)
	{
		int t=query(s[i]);
		cout<<t<<endl;
	}
	return 0;
}
