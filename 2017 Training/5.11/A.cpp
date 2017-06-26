//
//  Created by TaoSama on 2017-05-11
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char A[N], B[N << 1];
int n, nxt[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%s%s", &n, A, B);
    copy(B, B + n, B + n);

    nxt[0] = -1;
    for(int i = 0, j = -1; i < n; ++i) {
        while(~j && A[i] != A[j]) j = nxt[j];
        nxt[++i] = ++j;
    }

    pair<int, int> ans = {0, 0};
    for(int i = 0, j = 0; i < 2 * n;) {
        while(~j && B[i] != A[j]) j = nxt[j];
        ++i, ++j;
        ans = max(ans, {j, j - i});
    }
    printf("%d\n", -ans.second);

    return 0;
}
