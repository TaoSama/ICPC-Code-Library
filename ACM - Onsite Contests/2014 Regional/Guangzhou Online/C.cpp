//
//  Created by TaoSama on 2015-10-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int dx[]={1,-1,0,0,1,-1,1,-1};       //you zuo xia shang youxia zuoxia youshang zuoshang
const int dy[]={0,0,1,-1,1,1,-1,-1};       //0   1   2   3     4      5      6
//7
const int turn1[]={2,2,0,1,6,7,4,6};
const int turn2[]={3,3,0,1,5,4,7,5};

char s[105][105];
int n,dp[105][105][8];

bool check(int x,int y){
	if(x<1 || y<1 || x>n || y>n) return 0;
	if(s[x][y]!='.') return 0;
	return 1;
}

void solve(int x,int y,int dir){
	int ans=0,i=x,j=y;
	while(check(i,j)){
		ans++;
		i+=dx[dir]; j+=dy[dir];
	}
	dp[x][y][dir]=ans;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
	int i,j,k;
	while(~scanf("%d",&n) && n){
		for(i=1;i<=n;i++)
				scanf("%s",s[i]+1);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(s[i][j]=='.'){
					for(k=0;k<8;k++){
                        solve(i,j,k);
					}
				}
			}
		}
		int ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				for(k=0;k<8;k++){
					if(s[i][j]=='.'){
						int temp=dp[i][j][k];
                        int x=i,y=j;
                        x+=dx[k]*(temp-1); y+=dy[k]*(temp-1);
                        int temp2=max(dp[x][y][turn1[k]],dp[x][y][turn2[k]]);
						ans=max(ans,temp+temp2-1);
					}
				}
			}
		}
		printf("%d\n",ans);
	}



    return 0;
}
