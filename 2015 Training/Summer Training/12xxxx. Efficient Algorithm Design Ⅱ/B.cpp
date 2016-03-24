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

int n, s, x[3 * N], cnt[N], ok[2 * N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s >> n;
        memset(x, -1, sizeof x);
        memset(cnt, 0, sizeof cnt); //mark each number's existence
        memset(ok, 0, sizeof ok); //check i-th window's validation
        for(int i = 0; i < n; ++i) cin >> x[i + s];
        //expand it, so we don't worry about the bound

        int tot = 0;  //the slide window's size is fixed -> s
        for(int i = 0; i < n + s; ++i) {
            if(tot == s) ok[i] = 1; //complete window
            if(i < s && tot == i) ok[i] = 1; //left incomplete window
            if(i > n && tot == n + s - i) ok[i] = 1; //right incomplete window;

            if(x[i] != -1 && --cnt[x[i]] == 0) --tot;
            if(x[i + s] != -1 && cnt[x[i + s]]++ == 0) ++tot;
        }

        int ans = 0;
        for(int i = 0; i < s; ++i) {
            bool valid = true;
            for(int j = i; j < n + s; j += s) {
                if(!ok[j]) {
                    valid = false;
                    break;
                }
            }
            ans += valid;
        }
        if(ans == n + 1) ans = s;
        cout << ans << '\n';
    }
    return 0;
}
