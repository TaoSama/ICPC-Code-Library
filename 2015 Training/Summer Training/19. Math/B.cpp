//
//  Created by TaoSama on 2015-08-14
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, M = 10001;

int n, A[205];

void gao() {
    for(int a = 0; a < M; ++a) {
        for(int b = 0; b < M; ++b) {
            bool ok = true;
            for(int i = 2; i <= n; i += 2) {
                A[i] = (a * A[i - 1] + b) % M;
                if(i + 1 <= n && A[i + 1] != (a * A[i] + b) % M) {
                    ok = false;
                    break;
                }
            }
            if(ok) return;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        n <<= 1;
        for(int i = 1; i <= n; i += 2) scanf("%d", A + i);
        gao();
        for(int i = 2; i <= n; i += 2) printf("%d\n", A[i]);
    }
    return 0;
}
