//
//  Created by TaoSama on 2015-11-04
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

int n, a[755], b[755];

typedef pair<int, int> P;
void merge() {
    priority_queue<P, vector<P>, greater<P> > q;
    for(int i = 1; i <= n; ++i) q.push(P(a[i] + b[1], 1));
    for(int i = 1; i <= n; ++i) {
        P u = q.top(); q.pop();
        a[i] = u.first;
        int idx = u.second;
        if(idx < n)
            q.push(P(u.first - b[idx] + b[idx + 1], idx + 1));
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) scanf("%d", b + j);
            sort(b + 1, b + 1 + n);
            merge();
        }
        for(int i = 1; i <= n; ++i)
            printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}
