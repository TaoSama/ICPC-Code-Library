//
//  Created by TaoSama on 2015-06-13
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

string a, b, c;
int aa[26], bb[26], cc[26];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a >> b >> c) {
        memset(aa, 0, sizeof aa);
        memset(bb, 0, sizeof bb);
        memset(cc, 0, sizeof cc);
        for(int i = 0; i < a.size(); ++i)
            aa[a[i] - 'a'] ++;
        for(int i = 0; i < b.size(); ++i)
            bb[b[i] - 'a'] ++;
        for(int i = 0; i < c.size(); ++i)
            cc[c[i] - 'a'] ++;

        int cntb = INF, cntc = INF;
        while(true) {
            for(int i = 0; i < 26; ++i) if(bb[i]) cntb = min(cntb, aa[i] / bb[i]);
            for(int i = 0; i < 26; ++i) if(cc[i]) cntc = min(cntc, aa[i] / cc[i]);

            if(cntb == 0 && cntc == 0) break;

            if(cntb > cntc) {
                cout << b;
                for(int i = 0; i < 26; ++i) aa[i] -= bb[i];
            } else if(cntc) {
                cout << c;
                for(int i = 0; i < 26; ++i) aa[i] -= cc[i];
            }
        }
        for(int i = 0; i < 26; ++i) while(aa[i]--) cout << char(i + 'a');
        cout << '\n';
    }
    return 0;
}
