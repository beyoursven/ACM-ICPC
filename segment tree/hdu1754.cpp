#define rep(i, j, k) for(int i = j; i < k; i++)
#define per(i, j, k) for(int i = k-1; i >= j; i--)
#define mid (l+r)/2
#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

struct Node{
	int l, r, val;
}tree[6*N];

int a[N];

void up(int x){
	tree[x].val = max(tree[x*2].val, tree[x*2+1].val);
}

void buildtree(int x, int l, int r){
	tree[x].l = l;
	tree[x].r = r;
	if (l == r){
		tree[x].val = a[l];
		return;
	}
	buildtree(x*2, l, mid);
	buildtree(x*2+1, mid+1, r);
	up(x);
}

void modify(int x, int i, int v){
	int l = tree[x].l, r = tree[x].r;
	if (l == r && l == i){
		tree[x].val = v;
		return;
	}
	if (i <= mid) modify(x*2, i, v);
	else modify(x*2+1, i, v);
	up(x);
}

int query(int x, int ql, int qr){
	int l = tree[x].l, r = tree[x].r;
	if (ql <= l && r <= qr){
		return tree[x].val;
	}
	int res = 0;
	if (ql <= mid) res = max(res, query(x*2, ql, qr));
	if (qr > mid) res = max(res, query(x*2+1, ql, qr));
	return res;
} 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF){
		rep(i, 1, n+1) scanf("%d", &a[i]);
		buildtree(1, 1, n);
		int cnt = 0;
		rep(i, 0, m){
			cnt++;
			char c;
			int x, y;
			scanf("%c%c%d%d", &c, &c, &x, &y);
			cout << "111 " << x << ' ' << y << endl;
			if (c == 'Q') printf("%d\n", query(1, x, y));
			else if (c == 'U') modify(1, x, y);
		}
		cout << "cnt = " << cnt << endl;
	}
	return 0;
} 
