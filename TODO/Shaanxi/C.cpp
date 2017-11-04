//
//  Created by TaoSama on 2017-05-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


int A[N],B[N];
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
	int n,a,b;
	while(scanf("%d%d%d",&n,&a,&b)!=EOF){
		for(int j=1;j<=n;j++) scanf("%d",&A[j]),B[j]=A[j];
		sort(B+1,B+1+n);
		int ans=0;
		int cnt[3][3];
		memset(cnt, 0, sizeof(cnt));
		for(int i=1; i<=n; i++) cnt[B[i]][A[i]]++;
		for(int i=0; i<=1; i++) for(int j=i+1; j<=2; j++)
		{
			int t = min(cnt[i][j], cnt[j][i]);
			cnt[i][j] -= t;
			cnt[j][i] -= t;
			ans += t;
		}
		ans += (cnt[0][1]+cnt[0][2])*2;
		printf("%d\n", ans*b);
//		vector<int>pos[3];
//		for(int j=1;j<=n;j++){
//			if(A[j]==0&&A[j]!=B[j]) pos[B[j]].push_back(j);
//		}
//		//printf("size = %d\n",pos[1].size());
//		for(int j=1;j<=n;j++){
//			if(B[j]==0&&A[j]!=B[j]){
//				//printf("j = %d\n",j);
//				ans+=b;
//				if(pos[A[j]].size()){
//					//printf("pos = %d\n",pos[A[j]].back());
//					int p=pos[A[j]].back();
//					pos[A[j]].pop_back();
//					swap(A[p],A[j]);
//					//printf("A[j] = %d size = %d\n",A[j]);
//
//				}
//				else{
//					int t=((A[j]-1)^1)+1;
//					//printf("t = %d\n",t);
//					int p=pos[t].back();
//					pos[t].pop_back();
//					swap(A[p],A[j]);
//
//				}
//			}
//		}
//		for(int j=1;j<=n;j++){
//			if(B[j]==1&&A[j]!=B[j]) ans+=b;
//		}
//        printf("%d\n",ans);
	}


    return 0;
}
