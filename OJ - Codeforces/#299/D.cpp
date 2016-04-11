//
//  Created by TaoSama on 2015-05-10
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, m, nxt[N];
bool can[N];
string s;

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < s.size()) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

long long ksm(long long x, int n) {
    if(n < 0) return 0;
    long long ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        cin >> s;
        int len = s.size(), i = len;
        getNxt();
        memset(can, false, sizeof can);
        while(nxt[i]) {
            can[len - nxt[i] + 1] = true;
            i = nxt[i];
        }
        /*for(int i = 0; i <= len; ++i)
            cout << i << ' ';
        cout << endl;
        for(int i = 0; i <= len; ++i)
            cout << can[i] << ' ';
        cout << endl;*/
        int cnt = 0, x, y;
        bool ok = true;
        if(!m) {
            cnt = n;
            cout << ksm(26LL, cnt) << '\n';
            continue;
        }
        for(int i = 1; i <= m; ++i) {
            cin >> y; --y;
            if(ok) {
                if(i == 1) cnt += y;  //前面多余的
                else {
                    if(y - x < len) {  //重叠否？
                        if(!can[y - x + 1]) ok = false;
                    } else cnt += y - x - len; //中间多余的
                }
                x = y;
            }
        }
        if(ok) {
            int t = n - y - len;
            if(t) cnt += t;   //后面多余的
            //cout << cnt << endl;
            cout << ksm(26LL, cnt) << '\n';
        } else cout << "0\n";
    }
    return 0;
}
