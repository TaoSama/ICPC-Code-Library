//
//  Created by TaoSama on 2015-08-03
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
struct P {
    int v, id, sgn;
    bool operator< (const P& rhs) const {
        return v > rhs.v;
    }
} a[N];

bool cmp(P x, P y) {
    return x.id < y.id;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        long long sum = 0, half;
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].v);
            a[i].id = i;
            sum += a[i].v;
        }
        if(sum & 1) {puts("No"); continue;}
        sort(a + 1, a + 1 + n);

        bool ok = false;
        half = sum >> 1; sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += a[i].v;
            if(sum == half) {a[i].sgn = 1; ok = true; break;}
            else if(sum > half) sum -= a[i].v;
            else a[i].sgn = 1;
        }

        if(!ok) puts("No");
        else {
            puts("Yes");
            sort(a + 1, a + 1 + n, cmp);
            for(int i = 1; i <= n; ++i) {
                if(a[i].sgn) putchar('-');
                printf("1%c", i == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}
