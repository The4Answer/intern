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



int main() {
	int n;
	cin >> n;
	vector <int> symb(n);
	for (int i = 0; i < n; ++i)
		cin >> symb[i];
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		M[symb[i]] = tmp;
	}
	int k;
	cin >> k;
	int cur;
	cin >> cur;
	int ans = 0;
	for (int i = 1; i < k; ++i) {
		int tmp;
		cin >> tmp;
		if (M[cur] != M[tmp])
			ans++;
		cur = tmp;
	}
	cout << ans;
	return 0;
}
