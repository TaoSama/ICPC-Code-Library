#include <bits/stdc++.h>

using namespace std;

void see(vector<int> v) {
    for(int x : v) cout << x << ' '; cout << endl;
}

void see2(int* a, int sz) {
    for(int i = 0; i < sz; ++i) cout << a[i] << ' '; cout << endl;
}

int main() {

//    vector<int> v = {1, 2, 3, 5};
//    int position = find(v.begin(), v.end(), 3) - v.begin();
//    cout << position << endl;
//
//    int notFound = find(v.begin(), v.end(), 4) - v.begin();
//    cout << notFound << ' ' << v.size() <<  endl;
//
//    {
//        int a[4] = {1, 2, 3, 5};
//        //           0  1  2  3  4
//        int position = find(a, a + 4, 3) - a;
//        cout << position << endl;
//
//        int notFound = find(a, a + 4, 4) - a;
//        cout << notFound << endl;
//    }

//    vector<int> v(4);
//    see(v);
//    fill(v.begin(), v.end(), 100);
//    see(v);

//   int a[4] = {1, 2, 2, 4};  //O(n)
//   int m = unique(a, a + 4) - a;
//   printf("%d\n", m);
//   for(int i = 0; i < m; ++i) printf("%d ", a[i]); puts("");

//    int a[4] = {1, 2, 2, 4};  //O(n)
//    see2(a, 4);
//
//    replace(a, a + 4, 2, 3);
//    see2(a, 4);

//    int a[4] = {1, 2, 2, 4};  //O(n)
//    see2(a, 4);
//
//    reverse(a, a + 4);
//    see2(a, 4);

    // >= x [
    // >    )

//    int a[4] = {1, 2, 2, 4};  //O(logn)
//
//    int twoFirst = lower_bound(a, a + 4, 2) - a;
//    int twoSecond = upper_bound(a, a + 4, 2) - a;
//    printf("%d %d\n", twoFirst, twoSecond);
//    // [1, 3)

//    int a[4] = {1, 2, 2, 4};
//    see2(a, 4);
//    for(int i = 0; i < 4; ++i) {
//        random_shuffle(a, a + 4);
//        see2(a, 4);
//    }

//  O(n);
//	int a[4] = {1, 2, 2, 4}, b[3] = {2, 3, 5};
//	int c[10];
//	merge(a, a + 4, b, b + 3, c);
//	see2(c, 7);

//	int minv = min(2, 3);
//	int maxv = max(2, 3);
//	printf("%d %d\n", minv, maxv);

//	int a[4] = {1, 2, 2, 4};
//	int minv = *min_element(a, a + 4);
//	int maxv = *max_element(a, a + 4);
//	printf("%d %d\n", minv, maxv);

//	int a[4] = {1, 2, 3, 4}; //4! = 24
//	do{
//		see2(a, 4);
//	}while(next_permutation(a, a + 4));

//	int minv = min({2, 3, 4, 5});
//	printf("minv = %d\n", minv);

//    pair<int, int> v = {1, 2};
//    printf("%d %d\n", v.first, v.second);
//
//	tuple<int, char, int> v(1, '2', 3); // <
//	cout << get<0>(v) << endl;
//	cout << get<1>(v) << endl;
//	cout << get<2>(v) << endl;

//	complex<double> c(1, 2);  //1+2i
//	cout << c.real() << ' ' << c.imag() << endl;
//	cout << abs(c) << endl;
//	cout << arg(c) << endl;

//	int a[4] = {2, 4, 1, 3};
//	sort(a, a + 4, less<int>());
//	see2(a, 4);
////    reverse(a, a + 4);
////    see2(a, 4);
//
//	sort(a, a + 4, greater<int>());
//	see2(a, 4);


    return 0;
}
