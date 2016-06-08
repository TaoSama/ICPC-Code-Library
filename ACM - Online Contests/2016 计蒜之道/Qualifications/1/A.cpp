//
//  Created by TaoSama on 2016-06-05
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

int cnt[26];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        pair<int, int> minv = make_pair(INF, INF);
        for(int i = 0; i < 26; ++i) {
            scanf("%d", cnt + i);
            if(cnt[i]) minv = min(minv, make_pair(cnt[i], i));
        }
        int first = minv.second;
        if(first == INF) {
            puts("0");
            continue;
        }
        string s = string(1, char(first + 'a'));
        for(int i = 0; i < 26; ++i) {
            if(i == first) continue;
            s += string(cnt[i], char('a' + i));
        }
        s += string(cnt[first] - 1, char('a' + first));

        vector<int> nxt(s.size() + 1);
        nxt[0] = -1;
        for(int i = 0, j = -1; i < s.size();)
            if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
            else j = nxt[j];

        int ans = 0;
        for(int i = 2; i <= s.size(); ++i) {
            ans += nxt[i];
//          printf("nxt[%d] = %d\n", i, nxt[i]);
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
