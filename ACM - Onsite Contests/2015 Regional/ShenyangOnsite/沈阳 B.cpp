//
//  Created by TaoSama on 2015-10-31
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

int n;
char s[505][2005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%s", s + i);
        bool no = true;
        for(int i = 1; i < n; ++i) {
            if(!strstr(s[i + 1], s[i])) {
                no = false;
                break;
            }
        }
        if(no) {printf("Case #%d: -1\n", ++kase); continue;}

        int ans = -1;
        for(int i = n; i; --i) {
            for(int j = i - 1; j; --j) {
                if(!strstr(s[i], s[j])) {
                    ans = i;
                    break;
                }
            }
            if(~ans) break;
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
