//
//  Created by TaoSama on 2016-01-08
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, nxt[N];
char s[N], t[N], rt[N];

void getNxt(char *s) {
    int n = strlen(s);
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < n) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int kmp(char *s, char *t) {
    getNxt(t);
    int i = 0, j = 0, ret = 0;
    while(i < n) {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
        ret = max(ret, j);
    }
    return ret;
}

int l[N], r[N], f[N];
pair<int, int> last[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", s, t) == 2) {
        n = strlen(s), m = strlen(t);
        memset(rt, 0, sizeof rt);
        strcpy(rt, t);
        reverse(rt, rt + m);
//        puts(t); puts(rt);
        for(int i = 0; i < m; ++i) {
            l[i] = kmp(s, t + i);
            r[i] = kmp(s, rt + m - i - 1);
//            printf("%d: %s: %d\n", i, t + i, l[i]);
//            printf("%d: %s: %d\n", m - i - 1, rt + m - i - 1, r[i]);
        }
        memset(f, 0x3f, sizeof f);
        for(int i = 0; i < l[0]; ++i) {
            f[i] = 1;
            last[i] = make_pair(i, 1);
        }
        for(int i = 0; i < m; ++i) {
            if(r[i] != i + 1) break;
            f[i] = 1;
            last[i] = make_pair(i, -1);
        }
//        for(int i = 0; i < m; ++i) printf("f[%d]=%d\n", i, f[i]);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < i; ++j) {
                if(l[j + 1] >= i - j) {
                    if(f[i] > f[j] + 1) {
                        f[i] = f[j] + 1;
                        last[i] = make_pair(i - j - 1, 1);
                    }
                }
                if(r[i] >= i - j) {
                    if(f[i] > f[j] + 1) {
                        f[i] = f[j] + 1;
                        last[i] = make_pair(i - j - 1, -1);
                    }
                }
            }
        }
        if(f[m - 1] == INF) puts("-1");
        else {
            printf("%d\n", f[m - 1]);
            vector<pair<int, int> > path;
            int e = m - 1;
            while(e >= 0) {
                char buf[N];
                memset(buf, 0, sizeof buf);
//                pr(e), prln(last[e].first);
                if(last[e].second == 1) {
                    for(int i = e - last[e].first, j = 0; i <= e; ++i, ++j)
                        buf[j] = t[i];
                    int st = strstr(s, buf) - s;
                    path.push_back(make_pair(st, st + last[e].first));
                } else {
                    for(int i = e, j = 0; i >= e - last[e].first; --i, ++j)
                        buf[j] = t[i];
                    int st = strstr(s, buf) - s;
                    path.push_back(make_pair(st + last[e].first, st));
                }
                e = e - last[e].first - 1;
            }
            for(int i = f[m - 1] - 1; ~i; --i)
                printf("%d %d\n", path[i].first + 1, path[i].second + 1);
        }
    }
    return 0;
}
