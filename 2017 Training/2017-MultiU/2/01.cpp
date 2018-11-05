
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, x, y;
char A[N], B[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &x, &y);
        scanf("%s%s", A + 1, B + 1);
        int same = 0, diff = 0;
        for(int i = 1; i <= n; ++i) {
            if(A[i] == B[i]) ++same;
            else ++diff;
        }
        int g = min({same, x, y});
        x -= g; y -= g;
        puts(x + y <= diff ? "Not lying" : "Lying");
    }
    return 0;
}
