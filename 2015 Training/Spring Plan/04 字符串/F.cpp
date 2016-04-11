//
//  Created by TaoSama on 2015-05-04
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
const int N = 1e5 + 10;

int n, p[2005];
char a[1005], t[1005], tt[1005], s[2005];

void dif(char *a, char * t) {
    if(a[0] == 0 || a[1] == 0) {
        t[0] = 0;
        return;
    }
    int len = 1;
    for(int i = 1; a[i]; ++i, ++len)
        t[i - 1] = abs(a[i] - a[i - 1]) + 'a';
    t[len - 1] = 0;
}

void PreProcess() {
    s[0] = '@'; s[1] = '#'; n = 2;
    for(int i = 0; a[i]; ++i) {
        s[n++] = a[i];
        s[n++] = '#';
    }
    s[n] = 0;
}

int Manacher() {
    PreProcess();
    int mx = 0, id;
    for(int i = 1; i < n; ++i) {
        if(mx > i) p[i] = min(mx - i, p[2 * id - i]);
        else p[i] = 1;
        while(s[i - p[i]] == s[i + p[i]]) ++p[i];
        if(mx < p[i] + i) mx = p[i] + i, id = i;
    }
    int ret = 0;
    for(int i = 1; i < n; ++i) ret = max(ret, p[i] - 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", a) != EOF) {
        int ans = 0, sz = strlen(a);
        for(int i = 0; i < sz; ++i) {
            if(i != 0) {
                dif(a, t);
                strcpy(a, t);
            }
            //cout<<a<<' '<<Manacher()<<endl;
            ans = max(ans, Manacher());
        }
        printf("%d\n", ans);
    }
    return 0;
}
