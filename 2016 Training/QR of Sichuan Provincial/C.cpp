//
//  Created by TaoSama on 2016-05-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int dp[N],dp1[N];
vector<pair<int,int> >edge[N];
void dfs(int x,int fa){
	for(int j=0;j<edge[x].size();j++){
		int to=edge[x][j].first,v=edge[x][j].second;
		if(to==fa) continue;
		dfs(to,x);
		dp[x]=max(dp[to]+v,dp[x]);
	}
}
void check(int &maxx,int &maxx1,int t){
	if(t>=maxx){
		maxx1=maxx;
		maxx=t;
	}
	else{
		if(t>maxx1){
			maxx1=t;
		}
	}
}
void dfs1(int x,int fa){
	int maxx=dp1[x],maxx1=0;
	for(int j=0;j<edge[x].size();j++){
		int to=edge[x][j].first,v=edge[x][j].second;
		if(to==fa){
			check(maxx,maxx1,dp1[to]+v);
			continue;
		}
		check(maxx,maxx1,dp[to]+v);
	}
	//if(x==1) printf("maxx = %d maxx1 = %d\n",maxx,maxx1);
	for(int j=0;j<edge[x].size();j++){
		int to=edge[x][j].first,v=edge[x][j].second;
		if(to==fa) continue;
		//if(x==1) printf("!!!%d\n",dp[to]+v);
		if(dp[to]+v==maxx) dp1[to]=max(dp1[to],maxx1+v);
		else dp1[to]=max(dp1[to],maxx+v);
	}
	//printf("%d %d\n",)
	for(int j=0;j<edge[x].size();j++){
		int to=edge[x][j].first,v=edge[x][j].second;
		if(to==fa) continue;
		dfs1(to,x);
	}
}
struct RMQ{
	int minn[N][16],n;
	int maxx[N][16];
	void init(int *B,int n){
		memset(minn,63,sizeof(minn));
		memset(maxx,0,sizeof(maxx));
		this->n=n;
		for(int j=n;j>=1;j--){
			maxx[j][0]=B[j];
			for(int k=1;j+(1<<k)-1<=n;k++){
				//printf("%d %d\n",j,k);
				maxx[j][k]=max(maxx[j][k-1],maxx[j+(1<<k-1)][k-1]);
			}
		}
		//printf("111\n");
		for(int j=n;j>=1;j--){
			minn[j][0]=B[j];
			for(int k=1;j+(1<<k)-1<=n;k++){
				minn[j][k]=min(minn[j][k-1],minn[j+(1<<k-1)][k-1]);
			}
		}
	}
	int query_max(int x,int y){
		int j=31-__builtin_clz(y-x+1);
		return max(maxx[x][j],maxx[y-(1<<j)+1][j]);
	}
	int query_min(int x,int y){
		int j=31-__builtin_clz(y-x+1);
		return min(minn[x][j],minn[y-(1<<j)+1][j]);
	}
}rmq;
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		for(int j=1;j<=n;j++) edge[j].clear();
		for(int j=1;j<n;j++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			edge[a].push_back({b,c});
			edge[b].push_back({a,c});
		}
		dfs(1,0);
		dfs1(1,0);

		for(int j=1;j<=n;j++) dp1[j]=max(dp1[j],dp[j]);//printf("%d %d\n",j,dp1[j]);
		rmq.init(dp1,n);
		//printf("max = %d\n",rmq.query_max(2,4));
		//printf("...\n");
		vector<pair<int,int> >Q;
		int R[505]={};
		int ans[505]={};
		for(int j=0;j<m;j++){
			int a;
			scanf("%d",&a);
			Q.push_back({a,j});
		}
		sort(Q.begin(),Q.end());
		//printf("%d %d\n",rmq.minn[1][2],rmq.minn[2][2]);
		//printf("%d %d\n",rmq.query_max(1,5),rmq.query_min(1,5));
		for(int j=0;j<Q.size();j++) R[j]=1;
		for(int j=1;j<=n;j++){
			for(int k=0;k<Q.size();k++){
				int now=Q[k].first;
				while(R[k]<=n&&rmq.query_max(j,R[k])-rmq.query_min(j,R[k])<=now) R[k]++;
				//printf("%d %d %d %d %d\n",j,R[k],now,rmq.query_max(j,R[k]-1),rmq.query_min(j,R[k]-1));
				ans[Q[k].second]=max(ans[Q[k].second],R[k]-j);
			}
		}
		for(int j=0;j<Q.size();j++) printf("%d\n",ans[j]);
    }
    return 0;
}
