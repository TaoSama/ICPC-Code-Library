//
//  Created by TaoSama on 2016-09-30
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, x;
typedef long long LL;
LL a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &k, &x) == 3) {
        pair<LL, int> minv = {INF, INF};
        int sgn = 0;

        vector<int> zeros;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            minv = min(minv, {abs(a[i]), i});
            if(a[i] < 0) sgn ^= 1;
            if(a[i] == 0) zeros.push_back(i);
        }

        //sign and zeros
        if(!sgn) {
            if(zeros.size()) {
                for(int i = 0; i < zeros.size() && k; ++i, --k) {
                    int p = zeros[i];
                    if(!i) a[p] -= x;
                    else a[p] += x;
                }
            } else {
                int p = minv.second;
                if(a[p] < 0) {
                    while(k && a[p] <= 0) {
                        a[p] += x;
                        --k;
                    }
                } else {
                    while(k && a[p] >= 0) {
                        a[p] -= x;
                        --k;
                    }
                }
            }
        }

//        puts("...1");

        typedef pair<LL, int> P;
        priority_queue<P, vector<P>, greater<P> > q;
        for(int i = 1; i <= n; ++i) q.push({abs(a[i]), i});

        while(k--) {
            auto u = q.top(); q.pop();
            u.first += x;
            q.push(u);
        }
        while(q.size()) {
            LL v; int p; tie(v, p) = q.top(); q.pop();
            if(a[p] < 0) a[p] = -v;
            else a[p] = v;
        }

        for(int i = 1; i <= n; ++i)
            printf("%I64d%c", a[i], " \n"[i == n]);
    }

    return 0;
}
