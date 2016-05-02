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

int A[N];
int mark[N*10];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n;
    scanf("%d",&n);
    int maxx=0;
    for(int j=1;j<=n;j++){
		scanf("%d",&A[j]);
		mark[A[j]]++;
		maxx=max(maxx,mark[A[j]]);
    }
    memset(mark,0,sizeof(mark));
    int r=1;
    int ans=INF,cnt=0;
    int ansx,ansy;
    for(int j=1;j<=n;j++){
		while(r<=n&&cnt<maxx){
			mark[A[r]]++;
			cnt=max(cnt,mark[A[r]]);
			r++;
		}
		if(cnt==maxx){
			if(r-j<ans){
				ans=r-j;
				ansx=j;
				ansy=r-1;
			}
		}
		if(mark[A[j]]==maxx) cnt--;
		mark[A[j]]--;
    }
    printf("%d %d\n",ansx,ansy);
    return 0;
}
