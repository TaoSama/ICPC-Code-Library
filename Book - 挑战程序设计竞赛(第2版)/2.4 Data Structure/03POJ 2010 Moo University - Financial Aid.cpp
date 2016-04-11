//
//  POJ 2010 Moo University - Financial Aid
//
//  Created by TaoSama on 2015-03-16
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

int n, m, f;
pair<int, int> cow[N];
int l[N], h[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m >> f) {
		for(int i = 1; i <= m; ++i)
			cin >> cow[i].first >> cow[i].second;
		int half = n >> 1;
		sort(cow + 1, cow + 1 + m);

		{
			int total = 0;   //前半最小和
			priority_queue<int> pq;
			for(int i = 1; i <= m; ++i) {
				l[i] = pq.size() == half ? total : INF;
				pq.push(cow[i].second);
				total += cow[i].second;
				if(pq.size() > half) {
					total -= pq.top();
					pq.pop();
				}
			}
		}
		{
			int total = 0;		//后半最小和
			priority_queue<int> pq;
			for(int i = m; i >= 1; --i) {
				h[i] = pq.size() == half ? total : INF;
				pq.push(cow[i].second);
				total += cow[i].second;
				if(pq.size() > half) {
					total -= pq.top();
					pq.pop();
				}
			}
		}

		int ans = -1;
		for(int i = m; i >= 1; --i) {
			if(l[i] + cow[i].second + h[i] <= f) {
				ans = cow[i].first;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
