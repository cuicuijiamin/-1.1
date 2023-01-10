#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MAXN = 2010;
int n,k;
struct Tree {
    int head[MAXN], nxt[MAXN<<1], to[MAXN<<1], w[MAXN<<1], idx;
    Tree() { idx = 0; memset( head, -1, sizeof(head) ); }
    void addedge( int u, int v, int val ) {
        to[idx] = v; nxt[idx] = head[u]; w[idx] = val; head[u] = idx; ++idx;
        to[idx] = u; nxt[idx] = head[v]; w[idx] = val; head[v] = idx; ++idx;
    }
}tree;
ll dp[MAXN][MAXN]; int sz[MAXN];
void dfs( int u, int fa ) {
    sz[u] = 1; 
    memset( dp[u], -1, sizeof(dp[u]) ); 
    dp[u][0] = dp[u][1] = 0;
    for( int e = tree.head[u]; ~e; e = tree.nxt[e] ) 
    {
        int v = tree.to[e]; if( v == fa ) continue; 
        dfs(v,u); 
        sz[u] += sz[v];
    }
    for( int e = tree.head[u]; ~e; e = tree.nxt[e] ) 
    {
        int v = tree.to[e]; if( v == fa ) continue; 
        int w = tree.w[e];
        for( int i = min(k,sz[u]); i >= 0; --i ) 
        {
            for( int j = 0; j <= min(i,sz[v]); ++j ) if( ~dp[u][i-j] ) 
            {
                ll val = (ll)j*(k-j)*w + (ll)(sz[v]-j)*(n-k+j-sz[v])*w;
                dp[u][i] = max( dp[u][i], dp[u][i-j] + dp[v][j] + val );
            }
        }
    }
}
int main() {
    scanf( "%d%d", &n, &k );
    for( int i = 0; i < n-1; ++i ) {
        int u,v,w; 
        scanf( "%d%d%d", &u, &v, &w ); 
        tree.addedge(u,v,w);
    } 
    dfs(1,0); 
    printf( "%lld\n", dp[1][k] );
    return 0;
}
