//**********************************************双向队列解法
#include<bits/stdc++.h>
using namespace std;

string goal="123804765";
string s;
typedef struct node
{
	string now;
	int step;
} node;
int a[4][4];
queue<node>qa;
queue<node>qb;
map<string,int>mpa;
map<string,int>mpb;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs()
{
	qa.push((node)
	{
		s,0
	});
	qb.push((node)
	{
		goal,0
	});//起点，终点入队
	mpa[s]=1;
	mpb[goal]=1;
	int step=0;
	while(1)
	{
		++step;
		while(qa.front().step==step-1)
		{
			node t=qa.front();//获取队头
			string cur=t.now;
			qa.pop();//队头出队
			int sx,sy,tmp1;
			for(int i=0; i<9; ++i)
			{
				if(cur[i]=='0')
				{
					sx=i/3+1;
					sy=i%3+1;
					tmp1=i;
				}
			}
			//入队四个相关节点
			for(int i=0; i<4; ++i)
			{
				int nx=sx+dx[i];
				int ny=sy+dy[i];
				if(nx<1||nx>3||ny<1||ny>3)continue;
				int tmp2=(nx-1)*3+ny-1;
				swap(cur[tmp1],cur[tmp2]);
				node nt;
				nt.now=cur;
				swap(cur[tmp1],cur[tmp2]);
				if(mpa.find(nt.now)!=mpa.end())continue;
				if(mpa.find(nt.now)==mpa.end())
				{
					nt.step=t.step+1;
					qa.push(nt);
					mpa[nt.now]=1;
				}
				if(mpb.find(nt.now)!=mpb.end())
				{
					cout<<2*step-1<<endl;
					return ;
				}
			}
		}
		
		while(qb.front().step==step-1)
		{
			node t=qb.front();//获取队头
			string cur=t.now;
			qb.pop();//队头出队
			int sx,sy,tmp1;
			for(int i=0; i<9; ++i)
			{
				if(cur[i]=='0')
				{
					sx=i/3+1;
					sy=i%3+1;
					tmp1=i;
				}
			}
			//入队四个相关节点
			for(int i=0; i<4; ++i)
			{
				int nx=sx+dx[i];
				int ny=sy+dy[i];
				if(nx<1||nx>3||ny<1||ny>3)continue;
				int tmp2=(nx-1)*3+ny-1;
				swap(cur[tmp1],cur[tmp2]);
				node nt;
				nt.now=cur;
				swap(cur[tmp1],cur[tmp2]);
				if(mpb.find(nt.now)!=mpb.end())continue;
				if(mpb.find(nt.now)==mpb.end())
				{
					nt.step=t.step+1;
					qb.push(nt);
					mpb[nt.now]=1;
				}
				if(mpa.find(nt.now)!=mpa.end())
				{
					cout<<2*step<<endl;
					return ;
				}
			}
		}
	}
}
int main()
{
	cin>>s;

	if(s==goal)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=0; i<9; ++i)
	{
		a[i/3+1][i%3+1]=s[i];
	}
	bfs();
}
//******************************************************A*解法
#include<bits/stdc++.h>
using namespace std;
string goal="123804765";//目标

int a[4][4];
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
typedef struct node
{
	int f;//估价
	int step;
	string now;
	bool operator<(const struct node &oth)const //f越小，node越大，越在前，
	{
		return f>oth.f;
	}
} node;
priority_queue<node>q;
string s;
map<string,int>mp;
map<string,int>dis;//到达某个位置的距离 
int h(string cur)
{
	int res=0;
	for(int i=0; i<9; ++i)
	{
		if(cur[i]!=goal[i])//&&goal[i]!='0'
			res++;
	}
	return res;
}
void A_star()
{
	q.push((node)
	{
		h(s),0,s
	});
	mp[s]=1;
	while(!q.empty())
	{
		node t=q.top(); 
		string cur=t.now;
		cout<<"现在的字串："<< cur<<"所处的步数"<<t.step<<endl; 
		if(cur==goal)
		{
			cout<<t.step<<endl;
			break;
		}
		q.pop();
		int sx,sy,tmp1;
		for(int i=0; i<9; ++i)
		{
			if(cur[i]=='0')
			{
				sx=i/3+1;
				sy=i%3+1;//更新sx,sy
				tmp1=i;
			}
		}
		for(int i=0; i<4; ++i) //遍历4个方向
		{
			int xx=sx+dx[i];
			int yy=sy+dy[i];
			if(xx<1||xx>3||yy<1||yy>3)continue;//越界
			int tmp2=(xx-1)*3+yy-1;
			swap(cur[tmp1],cur[tmp2]);
			if(mp[cur]==0||(mp[cur]==1&&dis[cur]>t.step+1))
			{
				dis[cur]=t.step+1;//到达这个状态的距离
				mp[cur]=1;//标记该状态
				q.push((node){h(cur)+dis[cur],dis[cur],cur}); 
			}
			swap(cur[tmp1],cur[tmp2]);//有别的方向还没遍历，得先变回来 
		}
	}
}
int main()
{
	cin>>s;
	if(s==goal)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=0; i<9; ++i)
	{
		a[i/3+1][i%3+1]=s[i]-'0';
	}
	A_star(); 
	return 0;
}
//*************************************************IDA*解法
#include<bits/stdc++.h>
using namespace std;
string goal="123804765";
string s;
int a[4][4];
int dx[4]= {0,1,-1,0};//方向数组
int dy[4]= {1,0,0,-1};
int maxDeep;
int h(string cur)
{
	int res=0;
	for(int i=0;i<9;++i)
	{
		if(cur[i]!=goal[i])
		{
			res++;
		}
	}
	return res;
}
bool IDA_star(string cur,int pre,int step)
{
	cout<<"现在的cur"<<cur<<"第"<<step<<"步"<<endl;
	if(cur==goal)return true;
	if(step+h(cur)-1>maxDeep)//猜的距离
		return false; 
	int sx,sy,tmp1;
	for(int i=0;i<9;++i)
	{
		if(cur[i]=='0')
		{
			sx=i/3+1;
			sy=i%3+1;
			tmp1=i;
		}
	}
	 for(int i=0;i<4;++i)
	 {
	 	int xx=sx+dx[i];
	 	int yy=sy+dy[i];//预判的位置
		if(xx<1||xx>3||yy<1||yy>3)continue;
		if(pre+i==3) continue;
	 	int tmp2=(xx-1)*3+yy-1;
		swap(cur[tmp1],cur[tmp2]);
		if(IDA_star(cur,i,step+1))return true;
		swap(cur[tmp1],cur[tmp2]);
	 }
	 return false;
}
int main()
{
	cin>>s;
	if(s==goal)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=0; i<9; ++i)
	{
		a[i/3+1][i%3+1]=s[i];
	}
	for(maxDeep=0;; maxDeep++)
	{
		if(IDA_star(s,-1,0))
		{
			cout<<maxDeep<<endl;
			return 0;
		}
	}
	return 0;
}
