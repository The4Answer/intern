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
	int delt;
	int ind;
};

bool cmp(st f, st s) {
	return f.delt < s.delt;
}

int main() {
	int n;
	cin >> n;
	int x;
	cin >> x;
	long long T;
	cin >> T;
	vector <st> a;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		st t;
		t.delt = abs(tmp - x);
		t.ind = i + 1;
		a.push_back(t);
	}
	sort(a.begin(), a.end(), cmp);
	vector<int> ans;
	for (int i = 0; i < n && T > 0; ++i) {
		if (a[i].delt < T) 
			ans.push_back(a[i].ind);
		T -= a[i].delt;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";

	return 0;
}
