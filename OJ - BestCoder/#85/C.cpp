//
//  Created by TaoSama on 2016-07-31
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

vector<int> prime;
bool vis[N];
void gao() {
    for(int i = 2; i < N; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i + i; j < N; j += i) vis[j] = true;
    }
}

bool factorize(int x) {
    for(int i = 0; i < prime.size(); ++i) {
        if(prime[i] > x || 1LL * prime[i] * prime[i] > x) break;
        if(x % prime[i] == 0) {
            int cnt = 0;
            while(x % prime[i] == 0) {
                x /= prime[i];
                if(++cnt > 1) return false;
            }
        }
    }
    return true;
}

typedef long long LL;
LL go(LL x, int delta) {
    LL st = sqrt(x) + 0.5 + delta;
    while(st * st >= 2) {
        if(factorize(st)) return abs(st * st - x);
        st += delta ? 1 : -1;
    }
    return 1LL * INF * INF;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();

    int t; scanf("%d", &t);
    while(t--) {
        LL x; scanf("%I64d", &x);
        LL ans = go(x, 1);
        ans = min(ans, go(x, 0));
        printf("%I64d\n", ans);
    }

    return 0;
}
