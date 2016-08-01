//
//  Created by TaoSama on 2016-07-21
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

int n, m;
char s[N], t[N];

bool match(char* s, char* t) {
    for(int i = 0; i < m; ++i) {
//      printf("%c %c %c %c\n", s[i], s[i + 1], t[i], t[i + 1]);
        if(s[i] == t[i]) continue;
        if(i + 1 < m && s[i] == t[i + 1] && s[i + 1] == t[i]) {
            ++i;
            continue;
        }
        return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        scanf("%s%s", s + 1, t + 1);

        for(int i = 1; i <= n; ++i) {
            if(i + m - 1 > n) putchar('0');
            else putchar("01"[match(s + i, t + 1)]);
        }
        puts("");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
