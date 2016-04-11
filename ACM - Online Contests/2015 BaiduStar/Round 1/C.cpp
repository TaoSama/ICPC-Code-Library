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
const int N = 1e5 + 10;

int n, a[N], b[N];
bool check(int x) {
    b[1] = a[1] - x;
    for(int i = 2; i <= n; i++) {
        b[i] = a[i] - x;
        if(b[i] < b[i - 1] + 1)
            b[i] = b[i - 1] + 1;
        if(b[i] - a[i] > x) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        int l = 0, r = 1e9;
        while(l <= r) {
            int mid = l + r >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        printf("Case #%d:\n%d\n", ++kase, r + 1);
    }
    return 0;
}
