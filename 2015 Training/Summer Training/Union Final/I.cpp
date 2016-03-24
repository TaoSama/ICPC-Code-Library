//
//  Created by TaoSama on 2015-09-01
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

int a[5005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

    map<char, int> p;
    for(int i = 'a', j = 2; i <= 'z'; ++i) {
        p[i] = j;
        if(i == 'c' || i == 'f' || i == 'i' || i == 'l'
                || i == 'o' || i == 's' || i == 'v') ++j;
    }

    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        multimap<int, string> mp;
        for(int i = 1; i <= m; ++i) {
            string x; cin >> x;
            int num = 0;
            for(int j = 0; j < x.size(); ++j)
                num = num * 10 + p[x[j]];
            mp.insert(make_pair(num, x));
        }
        for(int i = 1; i <= n; ++i)
            printf("%d\n", mp.count(a[i]));
    }
    return 0;
}
