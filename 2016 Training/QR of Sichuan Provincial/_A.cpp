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

int dp[5005][5005];
int dfs(int x,int y){
	//printf("%d %d\n",x,y);
	if(dp[x][y]!=-1) return dp[x][y];
	if(x==0) return dp[x][y]=0;
	int ok=0;
	for(int j=1;j<=2*y&&j<=x;j++){
		if(!dfs(x-j,j)) ok=1;
	}
	return dp[x][y]=ok;
}
int main() {
//#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
////  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
//#endif
    ios_base::sync_with_stdio(0);
    int n;
    memset(dp,-1,sizeof(dp));

    for(int j=2;j<=5000;j++){
		int ok=0;
		for(int k=1;k<j;k++){
            if(!dfs(j-k,k)) ok=1;
		}
		if(ok==0) printf("%d\n",j);
    }
    return 0;
}
