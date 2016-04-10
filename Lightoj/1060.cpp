//
//  Created by TaoSama on 2015-11-20
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

typedef long long LL;
int n, cnt[26];
LL k, fact[25] = {1};
char s[25];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    for(int i = 1; i <= 20; ++i) fact[i] = fact[i - 1] * i;
    while(t--) {
        scanf("%s%lld", s + 1, &k);
        n = strlen(s + 1);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) cnt[s[i] - 'a']++;

        printf("Case %d: ", ++kase);
        LL maxk = fact[n];
        for(int i = 0; i < 26; ++i) maxk /= fact[cnt[i]];
        if(k > maxk) {puts("Impossible"); continue;}

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 26; ++j) {
                if(!cnt[j]) continue;
                --cnt[j];
                LL tmp = fact[n - i];
                for(int k = 0; k < 26; ++k)
                    tmp /= fact[cnt[k]];
                if(k <= tmp) {
                    putchar('a' + j);
                    break;
                }
                ++cnt[j];
                k -= tmp;
            }
        }
        puts("");
    }
    return 0;
}
