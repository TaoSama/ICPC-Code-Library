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

string s, t = "acdream";
int nxt[8], tt = 7;

int kmp() {
    int i = 0, j = 0, ret = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
        if(j == tt) ++ret;
    }
    return ret;
}

void getNext() {
    nxt[0] = -1;
    int i = 0, j = - 1;
    while(i < tt) {
        if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

bool isWhite(char& c) {
    return c == ' ' || c == '\n';
}
bool isOver(char& c) {
    return c == '.' || c == '?' || c == '!';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    getNext(); char c;
    for(int i = 0; i <= tt; ++i)
        cout<<nxt[i]<<' ';
    cout<<endl;
    while((c = getchar()) != EOF) {
        if(isWhite(c)) continue;

        c = tolower(c); s += c;

        if(isOver(c)) {
            //cout << s << endl;
            printf("%d\n", kmp());
            s.clear();
        }
    }
    return 0;
}
