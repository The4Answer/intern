//#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <ctime>



using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

struct st {
	long long delt;
	long long ind;
};

bool cmp(st f, st s) {
	return f.delt < s.delt;
}

int main() {
	long long n;
	cin >> n;
	long long x;
	cin >> x;
	long long T;
	cin >> T;
	vector <st> a;
	for (long long i = 0; i < n; ++i) {
		long long tmp;
		cin >> tmp;
		st t;
		t.delt = abs(tmp - x);
		t.ind = i + 1;
		a.push_back(t);
	}
	sort(a.begin(), a.end(), cmp);
	vector<long long> ans;
	for (long long i = 0; i < n && T > -1; ++i) {
		if (a[i].delt <= T) 
			ans.push_back(a[i].ind);
		T -= a[i].delt;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (long long i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";

	return 0;
}
