//
//  Created by TaoSama on 2016-07-24
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

int n, a[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%s", &n, s + 2) == 2) {
        a[1] = 1;
        for(int i = 2; i <= n; ++i) {
            if(s[i] == 'L') {
                a[i] = 1;
                for(int j = i - 1; j; --j)
                    if(a[j] == a[j + 1] || a[j] + 1 == a[j + 1]) ++a[j];
                    else break;
            } else if(s[i] == 'R') a[i] = a[i - 1] + 1;
            else a[i] = a[i - 1];
        }
        for(int i = 1; i <= n; ++i)
            printf("%d%c", a[i], " \n"[i == n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
