//
//  Created by TaoSama on 2017-04-30
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int f[N][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        f[i][0] = f[i][1] = 1;
        for(int j = 1; j < i; ++j) {
            if(a[i] > a[j]) f[i][1] = max(f[i][1], f[j][0] + 1);
            if(a[i] < a[j]) f[i][0] = max(f[i][0], f[j][1] + 1);
        }
    }
    printf("%d\n", n - max(f[n][0], f[n][1]));

    return 0;
}
