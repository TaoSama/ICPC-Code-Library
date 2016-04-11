//
//
//
//  Created by TaoSama on 2015-02-25
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

char s[105], t[105];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> (s + 1) >> (t + 1)) {
		int n = strlen(s + 1);
		bool ok = true;
		if(s[n] == 'z') {
			s[n] = 'a';
			bool more = true;
			for(int i = n - 1; i > 0; --i) {
				if(more) {
					if(s[i] == 'z') {
						if(i == 1) {ok = false; break;}
						s[i] = 'a';
					} else s[i] += 1, more = false;
				} else break;
			}
		}
		else s[n] += 1;
		if(!strcmp(s + 1, t + 1)) ok = false;
		if(ok) cout<<s+1<<endl;
		else	cout<<"No such string"<<endl;
	}
	return 0;
}
