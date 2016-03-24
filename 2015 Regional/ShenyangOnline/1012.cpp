//
//  Created by TaoSama on 2015-09-19
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
const int N = 5e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct P {
    int v, id;
    bool operator==(const P& rhs) const {
        return v == rhs.v && id == rhs.id;
    }
    bool operator<(const P& rhs) const {
        return v < rhs.v;
    }
};

P A[N];
int n, a, b;

bool cmp(P x, P y) {
    return abs(x.v) < abs(y.v);
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
        scanf("%d%d%d", &n, &a, &b);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i].v);
            A[i].id = i;
        }

        vector<P> v;
        sort(A + 1, A + 1 + n);
        for(int i = 1; i <= 2; ++i) {
            v.push_back(A[i]);
            v.push_back(A[n - i + 1]);
        }
        sort(A + 1, A + 1 + n, cmp);
        for(int i = 1; i <= 2; ++i) {
            v.push_back(A[i]);
            v.push_back(A[n - i + 1]);
        }

        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        long long ans = -2e18;
        for(int i = 0; i < v.size(); ++i) {
            for(int j = 0; j < v.size(); ++j) {
                if(i == j) continue;
                int x = v[i].v, y = v[j].v;
                ans = max(ans, 1LL * a * x * x + 1LL * b * y);
            }
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
