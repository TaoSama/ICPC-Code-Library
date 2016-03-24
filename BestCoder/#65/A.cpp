//
//  Created by TaoSama on 2015-12-05
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

int n;
char s[105], t[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s%s", s + 1, t + 1);
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == 'A' && t[i] == 'U') continue;
            if(s[i] == 'T' && t[i] == 'A') continue;
            if(s[i] == 'C' && t[i] == 'G') continue;
            if(s[i] == 'G' && t[i] == 'C') continue;
            ok = false; break;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
