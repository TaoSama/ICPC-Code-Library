//
//  Created by TaoSama on 2016-05-07
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s);

        int ans = 0;
        vector<int> a, c, m;
        for(int i = 0; s[i]; ++i) {
            s[i] = tolower(s[i]);
            if(s[i] == 'a') a.push_back(i);
            if(s[i] == 'c') c.push_back(i);
            if(s[i] == 'm') m.push_back(i);
        }
        for(int i = 0, j = 0, k = 0; i < a.size(); ++i, ++j, ++k) {
            j = lower_bound(c.begin() + j, c.end(), a[i]) - c.begin();
            if(j == c.size()) break;
            k = lower_bound(m.begin() + k, m.end(), c[j]) - m.begin();
            if(k == m.size()) break;
            ++ans;
        }
        printf("%d\n", ans);
    }


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
