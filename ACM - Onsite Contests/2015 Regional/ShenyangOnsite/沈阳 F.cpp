//
//  Created by TaoSama on 2015-10-25
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

typedef long long LL;

LL n, m, a[N];
bool vis[N];

vector<int> prime;
void gao() {
    int x = sqrt(1e9) + 5;
    for(int i = 2; i <= x; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i + i; j <= x; j += i) vis[j] = false;
    }
}

set<LL> step;
void update(int gcd) {
    for(auto x : step) if(gcd % x == 0) return;
    int tmp = -1;
    while(true) {
        auto iter = step.upper_bound(tmp);
        if(iter == step.end()) break;
        tmp = *iter;
        if(tmp % gcd == 0) step.erase(iter);
    }
    step.insert(gcd);
}

//sum
LL get(LL x) {
    LL cnt = m / x;
    return cnt * x + cnt * (cnt - 1) * x / 2;
}

LL calc() {
    LL ret = 0;
    vector<LL> gcd;
    for(auto x : step) gcd.push_back(x);
    int sz = gcd.size();
    for(int s = 1; s < 1 << sz; ++s) {
        LL cnt = 0, mul = 1;
        bool ok = true;
        for(int i = 0; i < sz; ++i) {
            if(s >> i & 1) {
                ++cnt;
                if(1.0 * mul / __gcd(gcd[i], mul) * gcd[i] > 1e10) {
                    ok = false;
                    break;
                }
                mul = mul / __gcd(gcd[i], mul) * gcd[i];
            }
        }
        if(!ok) continue;
        LL tmp = get(mul);
        if(cnt & 1) ret += tmp;
        else ret -= tmp;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%I64d%I64d", &n, &m);
        step.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            update(__gcd(a[i], m));
        }
        --m;
        printf("Case #%d: %I64d\n", ++kase, calc());
    }
    return 0;
}
