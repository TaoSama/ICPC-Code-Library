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

string s, t;
int nxt[N];

void getNext() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < s.size()) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

bool kmp(string& s, string &t) {
    int i = 0, j = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == t[j])
            ++i, ++j;
        else j = nxt[j];
        if(j == t.size()) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
		getNext();
		t = s.substr(1, s.size() - 2);
		string ans = "angry goddess";
		int i = s.size();
		while(nxt[i]){
			string sub = s.substr(0, nxt[i]);
			if(kmp(t, sub)) {
				ans = sub;
				break;
			}
			else i = nxt[i];
		}
        cout << ans << '\n';
    }
    return 0;
}
