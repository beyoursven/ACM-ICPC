#include <cstdio>
#include <iostream>
#include <cstring>
#define LL long long
#define rep(i, j, k) for (int i = j; i < k; i++)
#define per(i, j, k) for (int i = k-1; i >= j; i--)
#define mid (l+r)/2

using namespace std;

const int N = 100010;

struct Node{
	LL val;
	int add;
	int l, r;
}tree[4*N];

int a[N];

void up(int x){
	tree[x].val = tree[x*2].val+tree[x*2+1].val;
}

void down(int x){
	if (tree[x].add != 0){
		tree[x*2].add += tree[x].add;
		tree[x*2].val += (LL)(tree[x*2].r-tree[x*2].l+1)*tree[x].add;
		tree[x*2+1].add += tree[x].add;
		tree[x*2+1].val += (LL)(tree[x*2+1].r-tree[x*2+1].l+1)*tree[x].add;
		tree[x].add = 0;
	}
}

void buildtree(int x, int l, int r){
	tree[x].l = l;
	tree[x].r = r;
	tree[x].add = 0;
	if (l == r){
		tree[x].val = a[l];
		return;
	}
	buildtree(x*2, l, mid);
	buildtree(x*2+1, mid+1, r);
	up(x);
}

void modify(int x, int ql, int qr, int v){
	int l = tree[x].l, r = tree[x].r;
	if (ql <= l && r <= qr){
		tree[x].val += (LL)(r-l+1)*v;
		tree[x].add += v;
		return;
	}
	down(x);
	if (ql <= mid) modify(x*2, ql, qr, v);
	if (qr > mid) modify(x*2+1, ql, qr, v);
	up(x);
}

LL query(int x, int ql, int qr){
	int l = tree[x].l, r = tree[x].r;
	LL res = 0;
	if (ql <= l && r <= qr){
		return tree[x].val;
	}
	down(x);
	if (ql <= mid) res += query(x*2, ql, qr);
	if (qr > mid) res += query(x*2+1, ql, qr);
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, q;
	scanf("%d%d", &n, &q);
	rep(i, 1, n+1) scanf("%d", &a[i]);
	buildtree(1, 1, n);
	rep(i, 1, q+1){
		char str, c;
		scanf("%c%c", &c, &str);
		if (str == 'C'){
			 int a, b, c;
			 scanf("%d%d%d", &a, &b, &c);
			 modify(1, a, b, c);
		}
		else if (str == 'Q'){
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%lld\n", query(1, a, b));
		}
		//cout << str << endl;
	}
	return 0;
}

