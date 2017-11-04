#include <bits/stdc++.h>

using namespace std;

void see(vector<int> v) {
    for(int x : v) cout << x << ' '; cout << endl;
}

void see2(int* a, int sz) {
    for(int i = 0; i < sz; ++i) cout << a[i] << ' '; cout << endl;
}

int main() {

//    list<int> l;
//    l.insert(l.end(), 1);
//    l.insert(l.begin(), 2); // 2 1 ^
//    l.insert(--l.end(), 3);
//    for(list<int>::iterator iter = l.begin();
//            iter != l.end(); ++iter)
//        cout << *iter << ' ';
//    cout << endl;


//    forward_list<int> l2;

//    ++l2.begin();

//  顺序容器 1->2->3->4
//  关联容器

//    map<int, int> mp = {{1, 2}, {2, 3}}; //BBST
//    set<int> s = {1, 2, 3};
//    cout << mp.lower_bound(2)->first << endl;
//    cout << mp.lower_bound(2)->second << endl;
//    cout << *s.lower_bound(2); //logn

//  deque<int> deq;
//  deq.pop

//  int a[3 * N];
//  int f = N, e = N - 1;
//  a[--s] = x; //push_front
//    a[++e] = x;  //push_back;
//    ++s;  //pop_front;
//    --e;  //pop_back;
//
//    if(f <= e)

//  priority_queue<int> q;
//  q.push(1);
//  q.push(2);
//  q.push(3);
//  cout << q.top() << endl;

//    priority_queue<int, vector<int>, greater<int> > q;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//    cout << q.top() << endl;


//  priority_queue<int> q;
//  q.push(-1);
//  q.push(-2);
//  q.push(-3);
//  cout << -q.top() << endl;

//  vector<int> v(10, -1);
//  see(v);

//  vector<int> v1 = {0, 2, 3};
//  vector<int> v2 = {1, 2, 3};
//  cout << (v1 < v2) << endl;

//  bitset<10> b;
//  cout << b << endl;  //   /64
//  b[0] = 1;
//  cout << b << endl;

//  b ^= bitset<10>().flip();
//   000000001  ^ 111111111 = 111111110
//  b.flip();
//  cout << b << endl;

//	array<int, 4> a;
//	// int a[4];
//	fill(a.begin(), a.end(), 0);
//	for(int i = 0; i < 4; ++i) cout << a[i] << ' '; cout << endl;

	// 哈希表
	//	unordered_map<int, int> mp;


//    vector<int> v = {1, 2, 3};
//    cout << v.front() << endl;
//    cout << v.back() << endl;

//	string s = "123456";
//	cout << s.find("2347") << endl;
//	cout << (s.find("2347") == string::npos) << endl;
//	printf("%s\n", s.c_str());
//	cout << (s + "78") << endl;
//	s += "78";
//	cout << s << endl;

//	char line[100]; gets(line);

//	string line;
//	getline(cin, line);
//	stoi, stof, stod, stol, stoll
	cout << to_string(12345) << endl;

    return 0;
}
