//
//  Created by TaoSama on 2016-01-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
LL n;

bool vis[N * 10];
vector<int> lovely;
void gao() {
    lovely.push_back(1);
    for(LL i = 2; i <= 1e6; ++i) {
        if(vis[i]) continue;
        lovely.push_back(i);
        for(LL j = i * i; j <= 1e6; j += i * i) vis[j] = true;
    }
//  cout << lovely.size() << endl;
//  for(int i = 0; i < 100; ++i) cout << lovely[i] << ' '; cout << endl;
}

bool isLovely(LL x) {
    for(LL i = 2; i * i <= x; ++i)
        if(x % (i * i) == 0) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%I64d", &n) == 1) {
        vector<LL> factor;
        for(LL i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                factor.push_back(i);
                if(i != n / i) factor.push_back(n / i);
            }
        }
        sort(factor.begin(), factor.end());
        for(int i = factor.size() - 1; ~i; --i) {
            LL &x = factor[i];
            if(x > 1e6 && isLovely(x)) {
                printf("%I64d\n", x);
                break;
            }
            if(x <= 1e6 && binary_search(lovely.begin(), lovely.end(), x)) {
                printf("%I64d\n", x);
                break;
            }
        }
    }
    return 0;
}
