/*
	Problem I. MarsCity
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std ;

#define MP make_pair
#define PB push_back

const int MAXN = 1009 ;

int N , P ;
int _x[MAXN] , _y[MAXN] , _z[MAXN] , Fa[MAXN] ;

map<int,vector<int>> Node ;
multimap<int,pair<int,int>> Edge ;

void Init() {
	cin >> N >> P ;
	Node.clear() ;
	for ( int i = 1 ; i <= N ; i ++ ) {
		cin >> _x[i] >> _y[i] >> _z[i] ;
		Node[0-_z[i]].PB(i) ;
	}
	for ( int i = 1 ; i <= N ; i ++ ) Fa[i] = i ;
}

int dist(int u , int v) {
	return abs(_x[u]-_x[v]) + abs(_y[u]-_y[v]) + abs(_z[u]-_z[v]) ;
}

int FindFa(int u) {
	if ( Fa[u] != u ) Fa[u] = FindFa(Fa[u]) ;
	return Fa[u] ;
}

int Union(int val , int u , int v) {
	int Fu = FindFa(u) ;
	int Fv = FindFa(v) ;
	if ( Fu == Fv ) return 0 ;
	else {
		Fa[Fu] = Fv ;
		return val ;
	}
}

int Solve() {
	int ret = 0 ;
	
	Edge.clear() ;
	auto vec = (*Node.begin()).second ;
	for ( int i = 0 ; i < vec.size() ; i ++ )
		for ( int j = 0 ; j < vec.size() ; j ++ )
			Edge.insert( MP(dist(vec[i],vec[j]),MP(vec[i],vec[j])) ) ;
	for ( auto e : Edge ) ret += Union(e.first , e.second.first , e.second.second) ;
	
	for ( map<int,vector<int>>::iterator it = Node.begin() ; it != Node.end() ; it ++ ) {
		map<int,vector<int>>::iterator it2 = it ; it2 ++ ;
		if ( it2 == Node.end() ) break ;
		
		auto veci = (*it).second ;
		auto vecj = (*it2).second ;
		
		Edge.clear() ;
		for ( int i = 0 ; i < vecj.size() ; i ++ )
			for ( int j = i+1 ; j < vecj.size() ; j ++ )
				Edge.insert( MP(dist(vecj[i],vecj[j]),MP(vecj[i],vecj[j])) ) ;
		for ( int i = 0 ; i < vec.size() ; i ++ )
			for ( int j = 0 ; j < vecj.size() ; j ++ )
				Edge.insert( MP(dist(vec[i],vecj[j]),MP(vec[i],vecj[j])) ) ;
		
		for ( auto e : Edge ) ret += Union(e.first , e.second.first , e.second.second) ;
		for ( auto item : vecj ) vec.PB(item) ;
	}
	return ret ;
}

int main() {
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		Init() ;
		int _ans = Solve() ;
		cout << "Case #" << i << ":\n" << _ans*P << "\n" ;
	}
}