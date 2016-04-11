//
//  Created by TaoSama on 2016-03-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

typedef long long LL;

int n, a[N];
LL Q;

bool check(int x) {
    priority_queue<int> q;
    LL ret = 0;
    int j = 1;
    for(int i = 1; i <= n; ++i) {
        if(q.size() == x) {
            int cur = q.top(); q.pop();
            ret += cur * j++;
        }
        q.push(a[i]);
    }
    while(q.size()) {
        int cur = q.top(); q.pop();
        ret += cur * j++;
    }
    return ret <= Q;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%lld%", &n, &Q);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    int l = 1, r = 100000;
    while(l <= r) {
        int m = l + r >> 1;
        if(check(m)) r = m - 1;
        else l = m + 1;
    }
    if(l > 100000) l = -1;
    printf("%d\n", l);
    return 0;
}
