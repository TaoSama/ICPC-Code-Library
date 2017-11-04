#include <cstring>
#include <cstdio>
#include <ctime>

const int MAXN = 100009 ;

int n , m ;
int a[MAXN] , b[MAXN] , c[MAXN] , d[MAXN] ;
int ans[MAXN] ;

int Power(int x , int t , int mm) {
	int ret = 1LL ;
	for ( ; t > 0 ; t >>= 1 ) {
		if ( t & 1 ) ret = ((long long)ret * x) % mm ;
		x = ((long long)x * x) % mm ;
	}
	return ret ;
}

int F(int i , int x) {
	return ((long long)a[i] * Power(b[i] , x , d[i]) + c[i]) % d[i] ;
}

void Init() {
	for ( int i = 1 ; i <= n ; i ++ ) scanf("%d%d%d%d" , a+i , b+i , c+i , d+i) ;
}

void It(int l , int r , int s , int t) {
	int mid = (l+r) / 2 ;
	int tmp = F(mid , s) , minv ; minv = tmp ; ans[mid] = s ;
	for ( int k = s+1 ; k <= t ; k ++ ) {
		tmp = (((long long)tmp + d[mid] - c[mid]) * b[mid] + c[mid]) % d[mid] ;
		if ( tmp < minv ) {
			minv = tmp ;
			ans[mid] = k ;
		}
	}
	if ( l <= mid-1 ) It(l , mid-1 , s , ans[mid]) ;
	if ( mid+1 <= r ) It(mid+1 , r , ans[mid] , t) ;
}

void Solve() {
	It(1 , n, 1 , m) ;
	for ( int i = 1 ; i <= n ; i ++ ) printf("%d\n" , ans[i]) ;
}

int main() {
	//freopen("innew","r",stdin);
	//freopen("testnew","w",stdout);
	int Test = 0 ;
	while ( 2 == scanf("%d%d" , &n , &m) ) {
		Init() ;
		printf("Case #%d\n" , ++Test) ;
		Solve() ;
		//fprintf(stderr , "Test Case #%d Finished\n" , Test) ;
	}
	//fprintf(stderr,"%.2f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
