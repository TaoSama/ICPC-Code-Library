//
//  Created by TaoSama on 2016-03-24
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N];
int f[N];
const char* hehe = "hehe";

bool check(int i) {
    if(i + 3 > n) return false;
    for(int j = 0; j < 4; ++j)
        if(s[i + j] != hehe[j]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; ++i) {
            f[i] = (f[i] + f[i - 1]) % 10007;
            if(check(i)) f[i + 3] = (f[i + 3] + f[i] + 1) % 10007;
        }
        static int kase = 0;
        printf("Case %d: %d\n", ++kase, (f[n] + 1) % 10007);
    }
    return 0;
}
