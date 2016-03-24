//
//
//
//  Created by TaoSama on 2015-03-29
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

int n;
string ss = "START", gg = "END";

void read(string& s) {
    string t;
    while(getline(cin, t)) {
        if(t == ss) continue;
        if(t == gg) break;
        if(t == "") t = '\n';
        s += t;
    }
}

bool isWhite(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        string s, t;
        read(s); read(t);
        if(s == t) cout << "Accepted" << endl;
        else {
            string dat1, dat2;
            for(int i = 0; i < s.size(); ++i)
                if(!isWhite(s[i])) dat1 += s[i];
            for(int i = 0; i < t.size(); ++i)
                if(!isWhite(t[i])) dat2 += t[i];
            if(dat1 == dat2) cout << "Presentation Error" << endl;
            else cout << "Wrong Answer" << endl;
        }
    }
    return 0;
}
