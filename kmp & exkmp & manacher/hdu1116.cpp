#define rep(i, j, k) for(int i = j; i < k; i++)
#define per(i, j, k) for(int i = k-1; i >= j; i--)
#define mid (l+r)/2
#include <bits/stdc++.h>

using namespace std;

const int N = 50010; 

struct Node{
	int val;
	int l, r;
}tree[3*N];

int a[N];

void up(int x){
	tree[x].val = tree[x*2].val + tree[x*2+1].val;
}

void buildtree(int x, int l, int r){
	tree[x].l = l;
	tree[x].r = r;
	if (l == r){
		tree[x].val = a[l];
		return;
	}
	int M = mid;
	buildtree(x*2, l, M);
	buildtree(x*2+1, M+1, r);
	up(x);
}

void modify(int x, int i, int v){
	int l = tree[x].l, r = tree[x].r;
	if (l == r && l == i){
		tree[x].val += v;
		return;
	}
	int M = mid;
	if (i <= M) modify(x*2, i, v);
	else modify(x*2+1, i, v);
	up(x);
}

int query(int x, int ql, int qr){
	int l = tree[x].l, r = tree[x].r;
	if (ql <= l && r <= qr){
		return tree[x].val;
	}
	int M = mid, res = 0;
	if (ql <= M) res += query(x*2, ql, qr);
	if (qr > M) res += query(x*2+1, ql, qr);
	return res;
}

int main(){
	int T;
	scanf("%d", &T);
	rep(t, 1, T+1){
		int n;
		scanf("%d", &n);
		rep(i, 1, n+1) scanf("%d", &a[i]);
		buildtree(1, 1, n);
		string str = "";
		cin >> str;
		printf("Case %d:\n", t); 
		while (str != "End"){
			int x, y;
			scanf("%d%d", &x, &y);
			if (str == "Query"){
				printf("%d\n", query(1, x, y));
			}
			else if (str == "Add"){
				modify(1, x, y);
			}
			else if (str == "Sub"){
				modify(1, x, -y);
			}
			cin >> str;
		}
	}
	return 0;
}
