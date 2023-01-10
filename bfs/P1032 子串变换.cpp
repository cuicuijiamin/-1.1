#include<bits/stdc++.h>
using namespace std;
string s,t;
string a[7],b[7];
int n=0;
queue<string>qa,qb;
map <string,int> ma,mb;
//要求是10步以内的操作，包含10
int bfs()
{
	int step=0;
	qa.push(s);
	ma[s]=0;
	qb.push(t);//入队
	mb[t]=0;
	while(++step<=5)
	{
		while(ma[qa.front()]==step-1)//每次只入队一层  上面入一层，下面入一层 
		{
			string s1=qa.front();
			qa.pop();
			for(int i=0; i<n; ++i) //遍历所有可能
			{
				unsigned int pos=0;//从pos位置开始寻找a[i]
				while(pos<s1.size())
				{
					if(s1.find(a[i],pos)==string::npos)
						break;
						
					string s2=s1;
					s2.replace(s2.find(a[i],pos),a[i].size(),b[i]);//替换
					if(ma.find(s2)!=ma.end())
					{
						pos++;
						continue;
					 } 
					 if(mb.find(s2)!=mb.end())
					 {
					 	return 2*step-1;
					 }
					 qa.push(s2);
					 ma[s2]=step;
					 pos++; 
				}
			}
		}
		
		while(mb[qb.front()]==step-1)//干什么 
		{
			string s1=qb.front();
			qb.pop();
			for(int i=0; i<n; ++i) //遍历所有可能
			{
				unsigned int pos=0;//从pos位置开始寻找a[i]
				while(pos<s1.size())
				{
					if(s1.find(b[i],pos)==string::npos)
						break;
						
					string s2=s1;
					s2.replace(s2.find(b[i],pos),b[i].size(),a[i]);//替换
					if(mb.find(s2)!=mb.end())
					{
						pos++;
						continue;
					 } 
					 if(ma.find(s2)!=ma.end())
					 {
					 	return 2*step;
					 }
					 qb.push(s2);
					 mb[s2]=step;
					 pos++; 
				}
			}
		}
	}
	return -1;
}
int main()
{
	cin>>s>>t;
	while(cin>>a[n]>>b[n])
	{
		n++;
	}
	int ans=bfs();
	if(ans!=-1)cout<<ans<<endl;
	else cout<<"NO ANSWER!"<<endl;
	return 0;
}
