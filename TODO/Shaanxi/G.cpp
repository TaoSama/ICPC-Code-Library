//
//  Created by TaoSama on 2017-05-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M=N;
int A[M][M];
int sum[M][M];
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int j=n;j>=1;j--){
			for(int k=1;k<=n;k++){
				scanf("%d",&A[k][j]);
			}
		}
        for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				sum[j][k]=sum[j][k-1]+A[j][k];
			}
        }
        int m;
        scanf("%d",&m);
        printf("Case #%d:\n",cas++);
        while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			long long ans=0;
			for(int j=1;j<=x;j++){
				int t=y*j/x;
				//printf("j = %d t = %d\n",j,t);
				ans+=sum[j][t];
			}
			printf("%lld\n",ans);
        }
	}


    return 0;
}
