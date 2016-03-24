//
//  Created by TaoSama on 2015-08-15
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int Hnum[N], Hsemi[N];

void gao() {
    //0->H-prime 1->H-semi 2->H-composite
    for(int i = 5; i < N; i += 4) {
        for(int j = 5; j < N; j += 4) {
            long long t = 1LL * i * j;
            if(t >= N) break;
            if(!Hnum[i] && !Hnum[j]) Hnum[t] = 1;
            else Hnum[t] = 2;
        }
    }
    for(int i = 1; i < N; ++i)
        Hsemi[i] = Hsemi[i - 1] + (Hnum[i] == 1);
}

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1 && n) {
        printf("%d %d\n", n, Hsemi[n]);
    }
    return 0;
}
