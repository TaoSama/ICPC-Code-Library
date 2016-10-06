//
//  Created by TaoSama on 2016-10-01
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

int n;
typedef long long LL;
LL a[N], s[N];
int op[N];
int p[N], done[N];
LL sz[N];
multiset<LL> maxv;

int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    p[x] = y;
    maxv.erase(maxv.find(a[y]));
    maxv.erase(maxv.find(a[x]));
    a[y] += a[x];
    maxv.insert(a[y]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            s[i] = s[i - 1] + a[i];
        }
        for(int i = 1; i <= n; ++i) scanf("%d", op + i);


        for(int i = 1; i <= n; ++i) p[i] = i;
        memset(done, 0, sizeof done);

        maxv.clear();
        vector<LL> ans(1, 0);
        for(int i = n; i > 1; --i) {
            int x = op[i];
            done[x] = true;
            maxv.insert(a[x]);
//            prln(i);
            if(x - 1 >= 1 && done[x - 1]) unite(x - 1, x);
            if(x + 1 <= n && done[x + 1]) unite(x, x + 1);

            ans.push_back(*maxv.rbegin());
        }
        reverse(ans.begin(), ans.end());
        for(auto& x : ans) printf("%I64d\n", x);

//        puts("");
//        return 0;
    }

    return 0;
}
