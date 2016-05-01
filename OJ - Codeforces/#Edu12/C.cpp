//
//  Created by TaoSama on 2016-04-20
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

string s;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        for(int i = 0; i < s.size(); ++i) {
            int j = i + 1;
            while(j < s.size() && s[j] == s[i]) ++j;
			if(j - i <= 1) continue;
			char c = -1;
//			pr(i); prln(j);
			for(c = 'a'; c <= 'z'; ++c){
				if(c == s[i]) continue;
				else if(i && c == s[i - 1]) continue;
				else if(j < s.size() && c == s[j]) continue;
				else break;
			}
//			prln(c);
			for(int k = i + 1; k < j; k += 2) s[k] = c;
			i = j - 1;
        }
        cout << s << '\n';
    }
    return 0;
}
