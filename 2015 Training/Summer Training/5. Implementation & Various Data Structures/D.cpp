//
//  Created by TaoSama on 2015-07-23
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

char s[N];
int cur, last, nxt[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> (s + 1)) {
        cur = last = 0; //the cursor's position and the last
        nxt[0] = 0; // to virtual a node
        for(int i = 1; s[i]; ++i) {
            if(s[i] == '[') cur = 0;
            else if(s[i] == ']') cur = last;
            else {
                nxt[i] = nxt[cur]; //point i to the cursor
                nxt[cur] = i; //insert the node
                if(cur == last) last = i; //update the last
                cur = i; //move the cursor
            }
        }
        for(int i = nxt[0]; i; i = nxt[i]) cout << s[i];
        cout << '\n';
    }
    return 0;
}
