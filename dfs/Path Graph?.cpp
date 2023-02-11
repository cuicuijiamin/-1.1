## https://atcoder.jp/contests/abc287/tasks/abc287_c
//条件1：v(i)到v(i+1)之间有边	度数为1的点：2个  得是连通的
//条件2：v(i)到v(i+k) k>=2之间没边 每个点的度数不能>=3
#include <bits/stdc++.h>
using namespace std;
int vst[200010],cnt[200010];
vector<int> adj[200010];
void dfs(int x){
	if(vst[x]==1) return;
	vst[x]=1;
	for(int i=0;i<adj[x].size();i++) dfs(adj[x][i]);
}
int main(){
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cnt[u]++;//记录度
		cnt[v]++;
		if(cnt[u]==2) sum--;//sum记录度为1的点的数目
		if(cnt[v]==2) sum--;
		if(cnt[u]==1) sum++;
		if(cnt[v]==1) sum++;
		if(cnt[u]==3 || cnt[v]==3){//有3个度是一定不成立的
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(sum!=2) cout<<"No"<<endl;
	else{
		dfs(1);
		for(int i=1;i<=n;i++){
			if(vst[i]==0){//还有没有标记的
				cout<<"No"<<endl;
				return 0;
			}
		}
		cout<<"Yes"<<endl;
		return 0;
	}
	return 0;
}
