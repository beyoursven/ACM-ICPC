#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#define rep(i, j, k) for(int i = j; i < k; i++)
#define mid (l+r)/2

using namespace std;

const int N = 50010;

int maxv[4*N], minv[4*N];

void up(int x){
	maxv[x] = max(maxv[x*2], maxv[x*2+1]);
	minv[x] = min(minv[x*2], minv[x*2+1]);
}

void build(int x, int l, int r){
	maxv[x] = 0;
	minv[x] = INT_MAX;
	if (l == r){
		int t;
		scanf("%d", &t);
		maxv[x] = minv[x] = t;
		return;
	}
	build(x*2, l, mid);
	build(x*2+1, mid+1, r);
	up(x);
}

void query(int x, int l, int r, int ql, int qr, int &tmp1, int &tmp2){
	if (ql <= l && r <= qr){
		tmp1 = max(tmp1, maxv[x]);
		tmp2 = min(tmp2, minv[x]);
		return;
	}
	if (ql <= mid) query(x*2, l, mid, ql, qr, tmp1, tmp2);
	if (qr > mid) query(x*2+1, mid+1, r, ql, qr, tmp1, tmp2);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, q;
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	rep(i, 0, q){
		int x, y;
		scanf("%d%d", &x, &y);
		int tmp1 = 0, tmp2 = INT_MAX;
		query(1, 1, n, x, y, tmp1, tmp2);
		printf("%d\n", tmp1-tmp2);
	}
	return 0;
}
