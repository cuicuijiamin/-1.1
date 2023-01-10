#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int f1[500005][3];//记录最大值
int f2[500005][3];
int root[500005][2];//root[i][0]表示i节点的左节点的下标  root[i][1]表示i节点的右节点的下标

string s;
int tot;
//f[i][j]表示以i为根节点 根节点涂色为0绿，1红，2蓝的树的绿色节点的数目
void createT(int r){//root表示几号节点
	tot++;//表示总共访问了几个节点
	if (s[r] == '0'){
		return;//叶子节点退出
	}
	if (s[r] == '1') {
		root[r][0] = r + 1;//r的左节点一定是下一个
		createT(r + 1);//创建左子树
	}
	if (s[r] == '2') {
		root[r][0] = r + 1;//r的左节点一定是下一个
		createT(r + 1);//创建左子树
		root[r][1] = tot + 1;//右节点一定是总共访问的编号+1  太细了
		createT(tot + 1);//创建右子树
	}
}
int main()
{
	cin >> s;
	s = " " + s;//前面补了一个空格
	createT(1);//递归创建二叉树
	//for (int i = s.size() - 1; i>0; --i)
	//{
	//	printf("%d---%d---%d\n", i, root[i][0], root[i][1]);
	//}
	memset(f1, 0, sizeof(f1));
	memset(f2, 0x3f, sizeof(f2));
	memset(f2, 0, sizeof(f2[0]));
	for (int i = s.size() - 1; i>0; --i)
	{
		f1[i][0] = 1+max(f1[root[i][0]][1] + f1[root[i][1]][2], f1[root[i][0]][2] + f1[root[i][1]][1]);//根绿
		f1[i][1] = max(f1[root[i][0]][0] + f1[root[i][1]][2], f1[root[i][0]][2] + f1[root[i][1]][0]);//根红
		f1[i][2] = max(f1[root[i][0]][0] + f1[root[i][1]][1], f1[root[i][0]][1] + f1[root[i][1]][0]);//根蓝

		f2[i][0] = 1+min(f2[root[i][0]][1] + f2[root[i][1]][2], f2[root[i][0]][2] + f2[root[i][1]][1]);//根绿
		f2[i][1] = min(f2[root[i][0]][0] + f2[root[i][1]][2], f2[root[i][0]][2] + f2[root[i][1]][0]);//根红
		f2[i][2] = min(f2[root[i][0]][0] + f2[root[i][1]][1], f2[root[i][0]][1] + f2[root[i][1]][0]);//根蓝
	}
	int ans1 = max(f1[1][0], max(f1[1][1], f1[1][2]));
	int ans2 = min(f2[1][0], min(f2[1][1], f2[1][2]));
	cout << ans1 << " " << ans2 << endl;
}
