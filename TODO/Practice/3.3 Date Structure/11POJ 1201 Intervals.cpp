//
//  Created by TaoSama on 2015-06-18
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e4 + 10;

int n, b[N];

struct P {
    int s, g, c;
    bool operator < (const P& rhs) const {
        return g < rhs.g;
    }
} a[N];

int add(int i, int x) {
    for(; i <= N; i += i & -i) b[i] += x;
}

int sum(int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &a[i].s, &a[i].g, &a[i].c);
            a[i].s++, a[i].g++;
        }
        sort(a + 1, a + 1 + n);

//        for(int i = 1; i <= n; ++i)
//            cout << a[i].s << ' ' << a[i].g << ' ' << a[i].c << endl;

        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; ++i) {
            int cur = sum(a[i].g) - sum(a[i].s - 1);
            if(cur < a[i].c) cur = a[i].c - cur;
            else cur = 0;
            for(int j = a[i].g, k = 1; k <= cur; ++k) {
                while(sum(j) - sum(j - 1)) j--;
                add(j, 1);
            }
        }
        printf("%d\n", sum(N));
    }
    return 0;
}
/*
8
4 9 5
8 9 1
5 6 1
3 9 5
7 9 1
2 5 2
3 4 1
2 5 3

ans: 6
*/
