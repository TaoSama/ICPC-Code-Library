//
//  Created by TaoSama on 2017-05-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char mp[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		for(int j=0;j<19;j++){
			scanf("%s",mp[j]);
		}
		int cnt1=0,cnt2=0;
		for(int j=0;j<19;j++){
			for(int k=0;k<19;k++){
				if(mp[j][k]=='0') cnt1++;
				else if(mp[j][k]=='1') cnt2++;
			}
		}
		printf("Case #%d:\n",cas++);
		if(cnt1>cnt2) printf("White\n");
		else if(cnt1<cnt2) printf("Black\n");
		else printf("Equal\n");
	}


    return 0;
}
