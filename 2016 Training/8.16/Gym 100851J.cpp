//
//  Created by TaoSama on 2016-08-15
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
int a[N];
bool rev[N];

int check() {
    int ret; scanf("%d", &ret);
    if(ret == n) exit(0);
    else if(ret == n / 2) return 1;
    return 0;
}

void output() {
    for(int i = 1; i <= n; ++i) printf("%d", a[i]); puts("");
    fflush(stdout);
}

int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    while(true) {
        for(int i = 1; i <= n; ++i) a[i] = rand() % 2;
        output();
        if(check()) break;
    }

    for(int i = 2; i <= n; ++i) {
        a[1] ^= 1; a[i] ^= 1;
        output();
        int r = a[1] == a[i];
        if(!check()) rev[i] = r ^ 1;
        else rev[i] = r;
        a[1] ^= 1; a[i] ^= 1;
    }

    for(int j = 0; j < 2; ++j) {
        a[1] = j;
        for(int i = 2; i <= n; ++i) a[i] = rev[i] ^ a[1];
        output();
        check();
    }

    return 0;
}
