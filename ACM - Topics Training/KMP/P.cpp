//
//  Created by TaoSama on 2015-10-30
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

int k, n;
char s[205];

int getMin() {
    int i = 0, j = 1;
    while(i < n && j < n) {
        int k = 0;
        while(k < n && s[i + k] == s[j + k]) ++k;
        if(k == n) break;
        if(s[i + k] < s[j + k]) j += k + 1;
        else i += k + 1;
        j += i == j;
    }
    return min(i, j);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &k) == 1) {
        n = 0;
        set<string> cnt;
        for(int i = 1; i <= k; ++i) {
            scanf("%s", s);
            if(!n) n = strlen(s);
            strncpy(s + n, s, n);
            int p = getMin();
            for(int j = 0; j < n; ++j)
                s[j] = s[j + p];
            s[n] = 0;
            cnt.insert(s);
        }
        printf("%d\n", cnt.size());
    }
    return 0;
}
