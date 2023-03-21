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
	int val;
	int ind;
};

int n;
vector<int> a;
vector <st> maxT;
vector <st> minT;
int inf = 100000000;

void buildMax(int v, int tl, int tr) {
	if (tl == tr) {
		maxT[v].val = a[tl];
		maxT[v].ind = tl;
	}
	else {
		int tm = (tl + tr) / 2;
		buildMax(v * 2, tl, tm);
		buildMax(v * 2 + 1, tm + 1, tr);
		//maxT[v] = max(maxT[v * 2], maxT[v * 2 + 1]);
		if (maxT[v * 2].val < maxT[v * 2 + 1].val)
			maxT[v] = maxT[v * 2 + 1];
		else
			maxT[v] = maxT[v * 2];
	}
}

void buildMin(int v, int tl, int tr) {
	if (tl == tr) {
		minT[v].val = a[tl];
		minT[v].ind = tl;
	}
	else {
		int tm = (tl + tr) / 2;
		buildMin(v * 2, tl, tm);
		buildMin(v * 2 + 1, tm + 1, tr);
		//minT[v] = min(minT[v * 2], minT[v * 2 + 1]);
		if(minT[v * 2].val < minT[v * 2 + 1].val)
			minT[v] = minT[v * 2];
		else
			minT[v] = minT[v * 2 + 1];
	}
}

st findMax(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		st tmp;
		tmp.val = -1;
		return tmp;
	}
	if (l == tl && r == tr)
		return maxT[v];
	int tm = (tl + tr) / 2;
	//return max(findMax(v * 2, tl, tm, l, min(r, tm)),
	//	findMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	st f = findMax(v * 2, tl, tm, l, min(r, tm));
	st s = findMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	if (f.val < s.val)
		return s;
	else
		return f;
}

st findMin(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		st tmp;
		tmp.val = inf;
		return tmp;
	}
	if (l == tl && r == tr)
		return minT[v];
	int tm = (tl + tr) / 2;
	//return min(findMin(v * 2, tl, tm, l, min(r, tm)),
	//	findMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	st f = findMin(v * 2, tl, tm, l, min(r, tm));
	st s = findMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	if (f.val < s.val)
		return f;
	else
		return s;
}

int main() {
	cin >> n;
	maxT.resize(4 * n);
	minT.resize(4 * n);
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	buildMax(1, 0, n - 1);
	buildMin(1, 0, n - 1);

	int ansI1 = -1, ansI2 = -1, ansI3 = -1, ansI4 = -1;
	int tansI1 = -1, tansI2 = -1, tansI3 = -1, tansI4 = -1;

	int maxAns = -1;
	for (int i = 0; i < n; ++i) {
		int maxLeft = 0;
		if (i > 0) {
			st maxL = findMax(1, 0, n - 1, 0, i - 1);
			st minL = findMin(1, 0, n - 1, 0, maxL.ind);
			int maxLeft1 = maxL.val - minL.val;
			tansI1 = minL.ind;
			tansI2 = maxL.ind;
			minL = findMin(1, 0, n - 1, 0, i - 1);
			maxL = findMax(1, 0, n - 1, minL.ind, i - 1);
			int maxLeft2 = maxL.val - minL.val;
			//int maxLeft = max(maxLeft1, maxLeft2);
			maxLeft = maxLeft1;
			if (maxLeft2 > maxLeft1) {
				maxLeft = maxLeft2;
				tansI1 = minL.ind;
				tansI2 = maxL.ind;
			}
		}
		///////

		st maxR = findMax(1, 0, n - 1, i, n - 1);
		st minR = findMin(1, 0, n - 1, i, maxR.ind);
		int maxR1 = maxR.val - minR.val;
		tansI3 = minR.ind;
		tansI4 = maxR.ind;
		minR = findMin(1, 0, n - 1, i, n - 1);
		maxR = findMax(1, 0, n - 1, minR.ind, n - 1);
		int maxR2 = maxR.val - minR.val;
		//int maxRight = max(maxR1, maxR2);
		int maxRight = maxR1;
		if (maxR2 > maxR1) {
			maxRight = maxR2;
			tansI3 = minR.ind;
			tansI4 = maxR.ind;
		}
		////
		//maxAns = max(maxAns, maxLeft + maxRight);
		if (maxAns < maxLeft + maxRight ) {
			maxAns = maxLeft + maxRight;
			ansI1 = tansI1, ansI2 = tansI2, ansI3 = tansI3, ansI4 = tansI4;
		}
	}
	//cout << maxAns << "\n";
	if (maxAns <= 0)
		cout << 0;
	else {
		if (ansI1 < ansI2 && ansI3 < ansI4) {
				cout << 2 << "\n";
				cout << ansI1 + 1 << " " << ansI2 + 1 << "\n" << ansI3 + 1 << " " << ansI4 + 1;
		}
		else if (ansI1 < ansI2) {
			cout << 1 << "\n";
			cout << ansI1 + 1 << " " << ansI2 + 1;
		}
		else {
			cout << 1 << "\n";
			cout << ansI3 + 1 << " " << ansI4 + 1;
		}
	}
	return 0;
}
