//
//  Created by TaoSama on 2015-09-11
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

int n;

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();

    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

const int B = 1000;
vector<pair<int, int> > a[B + 5];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    n = read();
    for(int i = 0; i < n; ++i) {
        int x, y;
        x = read(); y = read();
        a[x / B].push_back({y, i + 1});
    }
    for(int i = 0; i <= B; ++i) {
        sort(a[i].begin(), a[i].end());
        if(i & 1) reverse(a[i].begin(), a[i].end());
        for(int j = 0; j < a[i].size(); ++j)
            printf("%d ", a[i][j].second);
    }
    puts("");
    return 0;
}
