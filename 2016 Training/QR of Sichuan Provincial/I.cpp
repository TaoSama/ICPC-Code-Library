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
const int M = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int A[M];
vector<int>edge[M];
int n,m;
int ans;
void dfs(int x,int fa,int y){
	if(y>m) return;
	int ok=0;
	for(int j=0;j<edge[x].size();j++){
		int to=edge[x][j];
		if(to==fa) continue;
		ok=1;
		if(A[x]) dfs(to,x,y+1);
		else dfs(to,x,0);
	}
	//printf("%d %d\n",x,y);
	int t;
	if(A[x]) t=y+A[x];
	else t=0;
	if(!ok&&t<=m) ans++;
}
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int j=1;j<=n;j++){
			scanf("%d",&A[j]);
			edge[j].clear();
        }
        for(int j=1;j<n;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
        }
        ans=0;
        dfs(1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
