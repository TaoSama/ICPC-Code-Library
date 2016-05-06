//
//  Created by TaoSama on 2016-05-06
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N], t[N];
int c[10];
int LOG10[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i < N; ++i) LOG10[i] = LOG10[i / 10] + 1;

    while(scanf("%s%s", s + 1, t + 1) == 2) {
        n = strlen(s + 1); m = strlen(t + 1);
        memset(c, 0, sizeof c);
        for(int i = 1; i <= n; ++i) c[s[i] - '0']++;

        int l = 1, r = n;
        while(l <= r) {
            int m = l + r >> 1;
            if(m + LOG10[m] <= n) l = m + 1;
            else r = m - 1;
        }
        --l;
//        prln(l);

        char digit[10]; sprintf(digit, "%d", l);
        for(int i = 0; digit[i]; ++i) {
            int idx = digit[i] - '0';
            assert(c[idx] != 0);
            --c[idx];
        }
        for(int i = 1; i <= m; ++i) {
            int idx = t[i] - '0';
            assert(c[idx] != 0);
            --c[idx];
        }

//        for(int i = 0; i < 10; ++i) printf("%d ", i); puts("");
//        for(int i = 0; i < 10; ++i) printf("%d ", c[i]); puts("");

        string ans;
        if(t[1] != '0') {
            //t插入在最前面
            ans = string(t + 1, t + 1 + m);
            for(int i = 0; i < 10; ++i) ans += string(c[i], char('0' + i));
        }

//        prln(ans);

        int first = -1;
        for(int i = 1; i < 10; ++i) if(c[i]) {first = i; break;}

        if(first == -1) {
            if(!ans.size()) ans = "0";
        } else {
            //不管t
            --c[first];
            string tmp;
            vector<string> v; v.push_back(string(t + 1, t + 1 + m));
            for(int i = 0; i < 10; ++i) {
                if(!c[i]) continue;
                v.push_back(string(c[i], char('0' + i)));
            }
            sort(v.begin(), v.end());

            tmp += char(first + '0');
            for(auto& s : v) tmp += s;

            if(!ans.size() || tmp < ans) ans = tmp;
        }
        puts(ans.c_str());
    }
    return 0;
}
