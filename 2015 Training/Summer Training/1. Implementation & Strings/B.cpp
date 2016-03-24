//
//  Created by TaoSama on 2015-07-18
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

const string x = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    map<char, char> mp;
    for(int i = 0; i < x.size(); ++i) {
        if(x[i] == '`' || x[i] == 'Q' || x[i] == 'A' || x[i] == 'Z') mp[x[i]] = x[i];
        else mp[x[i]] = x[i - 1];
    }
    char c;
    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n') putchar(c);
        else putchar(mp[c]);
    }
    return 0;
}
