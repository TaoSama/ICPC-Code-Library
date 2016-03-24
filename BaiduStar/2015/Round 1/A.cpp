//
//  Created by TaoSama on 2015-05-30
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
const int N = 1e4 + 10;

long long n, m, k, a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        for(int i = 1; i <= n; ++i) scanf("%I64d", a + i);
        sort(a + 1, a + 1 + n);
        bool win = false;
        for(int i = 1; i < n; ++i) {
            if(a[i] <= m && a[i + 1] > m) {
                m = a[i] + k;
                //cout<<"M: "<<m<<" k: "<<k<<endl;
                k--;
            }
        }
        if(m >= a[n]) win = true;
        printf("Case #%d:\n", ++kase);
        puts(win ? "why am I so diao?" : "madan!");
    }
    return 0;
}
