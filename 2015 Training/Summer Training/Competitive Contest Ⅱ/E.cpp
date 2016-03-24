//
//  Created by TaoSama on 2015-08-23
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int phi[N], ans[N];
void gao() {
    phi[1] = 1;
    for(int i = 2; i <= 5e4; ++i) {
        if(!phi[i]) {
            for(int j = i; j <= 5e4; j += i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    ans[1] = 1; ans[2] = phi[2];
    for(int i = 3; i <= 5e4; ++i) ans[i] = ans[i - 1] + phi[i];
    for(int i = 2; i <= 5e4; ++i) ans[i] = 2 * ans[i] + 1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1 && n) {
        printf("%d\n", ans[n]);
    }
    return 0;
}
