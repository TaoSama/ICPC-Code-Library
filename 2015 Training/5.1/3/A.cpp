//
//  Created by TaoSama on 2015-06-04
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
const int N = 1e6 + 10;

int nxt[10], hh[N], mm[N], cnth, cntm;
string h = "heavy", m = "metal";
string s;

void getNxt(string &s) {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < s.size()) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

void kmp(int *p, int& cnt, string &s, string &t) {
    int i = 0, j = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
        if(j == t.size()) p[cnt++] = i;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        cnth = cntm = 0;
        getNxt(h); kmp(hh, cnth, s, h);

        /*cout<<cnth<<endl;
        for(int i = 0; i < cnth; ++i)
            cout<<hh[i] <<' '; cout << endl;*/
        getNxt(m); kmp(mm, cntm, s, m);

        /*cout<<cntm<<endl;
        for(int i = 0; i < cnth; ++i)
            cout<<mm[i] <<' '; cout << endl;*/

        long long ans = 0;
        for(int i = 0; i < cnth; ++i) {
            ans += cntm - (lower_bound(mm, mm + cntm, hh[i]) - mm);
        }
        cout << ans << '\n';
    }
    return 0;
}
