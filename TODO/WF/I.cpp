//
//  Created by TaoSama on 2017-05-24
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
int f[30][30];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        memset(f, 0, sizeof f);
        for(int i = 0; i < 26; ++i) f[i][i] = 1;
        for(int i = 1; i <= n; ++i) {
            char a[2], b[2]; scanf("%s%s", a, b);
            f[*a - 'a'][*b - 'a'] = 1;
        }
        for(int k = 0; k < 26; ++k)
            for(int i = 0; i < 26; ++i)
                for(int j = 0; j < 26; ++j)
                    f[i][j] |= f[i][k] & f[k][j];
        while(q--) {
            char a[100], b[100]; scanf("%s%s", a, b);
            int al = strlen(a), bl = strlen(b);
            if(al != bl) puts("no");
            else {
                bool ok = true;
                for(int i = 0; a[i] && ok; ++i)
                    ok &= f[a[i] - 'a'][b[i] - 'a'];
                puts(ok ? "yes" : "no");
            }
        }
    }

    return 0;
}
