//
//  Created by TaoSama on 2016-02-25
//  Copyright (c) 2016 TaoSama. All rights reserved.
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

int n;
char s[N];

bool add() {
    ++s[1];
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        int carry = s[i] >= 10;
        if(carry) s[i] -= 10, ++s[i + 1];
        sum += s[i];
    }
    if(s[n + 1]) ++n, ++sum;
    return sum % 10 == 0;
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
        reverse(s + 1, s + 1 + n);
        for(int i = 1; i <= n; ++i) s[i] -= '0';
        while(!add());
        for(int i = n; i; --i) printf("%d", s[i]); puts("");
    }
    return 0;
}
