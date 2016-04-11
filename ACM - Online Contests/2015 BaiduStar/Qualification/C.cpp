//
//  Created by TaoSama on 2015-05-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int N = 1e5 + 10;

int n, m;
int A[1005], B[1005], C[1005], D[1005];
int a, b, c, d;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        printf("Case #%d:\n", ++kase);
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            scanf("%d.%d.%d.%d", A + i, B + i, C + i, D + i);
        for(int i = 1; i <= m; ++i) {
            set<string> s;
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            for(int j = 1; j <= n; ++j) {
                string ss; char tt[10];
                sprintf(tt, "%d", (A[j] & a));
                ss = ss + tt;
                sprintf(tt, "%d", (B[j] & b));
                ss = ss + '.' + tt;
                sprintf(tt, "%d", (C[j] & c));
                ss = ss + '.' + tt;
                sprintf(tt, "%d", (D[j] & d));
                ss = ss + '.' + tt;
                //cout<<ss<<endl;
                s.insert(ss);
            }
            printf("%d\n", s.size());
        }
    }
    return 0;
}
