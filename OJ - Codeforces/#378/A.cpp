//
//  Created by TaoSama on 2016-10-31
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1), last = 0;
        s[++n] = 'A';
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            const char* buf = "AEIOUY";
            if(!strchr(buf, s[i])) continue;
            ans = max(ans, i - last);
            last = i;
        }
        printf("%d\n", ans);
    }

    return 0;
}
