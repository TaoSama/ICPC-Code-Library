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



int main(int argc, char* argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n = atoi(argv[1]);
    printf("%d\n", n);
    for(int i = 1; i <= n; ++i) printf("%d%c", i > 1, " \n"[i == n]);
    for(int i = 1; i < n; ++i) {
        printf("%d %d\n", i, i + 1);
    }

    return 0;
}
