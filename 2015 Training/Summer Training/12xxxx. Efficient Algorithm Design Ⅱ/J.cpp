//
//  Created by TaoSama on 2015-08-01
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

int n, d;
char a[N];
bool vis[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> d && (n || d)) {
        cin >> (a + 1);

        memset(vis, false, sizeof vis);
        int pre = 1, cnt = 0;
        for(int i = 2; i <= n; ++i) {
            if(!vis[i]) {
                if(a[i] > a[pre]) {
                    for(int j = i - 1; j; --j) {
                        if(!vis[j]) {
                            if(a[j] < a[i] && cnt < d) {
                                vis[j] = true;
                                cnt++;
                            } else if(a[j] >= a[i]) break;
                        }
                    }
                }
                pre = i;
            }
        }
        for(int i = n; i >= 0 && cnt < d; --i) {
            if(!vis[i]) {
                vis[i] = true;
                cnt++;
            }
        }
        for(int i = 1; i <= n; ++i)
            if(!vis[i]) cout << a[i];
        cout << '\n';
    }
    return 0;
}
