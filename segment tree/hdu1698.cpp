#include<bits/stdc++.h>
#define mid (l+r)/2
#define rep(i, j, k) for(int i = j; i < k; i++)

using namespace std;

const int N = 100010;

int sum[4*N], col[4*N];

void down(int x, int l, int r){
	if (col[x]){
		col[x*2] = col[x*2+1] = col[x];
		sum[x*2] = (mid-l+1)*col[x];
		sum[x*2+1] = (r-mid)*col[x];
		col[x] = 0;
	}
}

void up(int x){
	sum[x] = sum[x*2]+sum[x*2+1];
}

void build(int x, int l, int r){
	sum[x] = 1;
	col[x] = 0;
	if (l == r) return;
	build(x*2, l, mid);
	build(x*2+1, mid+1, r);
	up(x);
}

void modify(int x, int l, int r, int ql, int qr, int v){
	if (ql <= l && r <= qr){
		col[x] = v;
		sum[x] = (r-l+1)*v;
		//cout << sum[x] << endl;
		return;
	}
	down(x, l, r);
	if (ql <= mid) modify(x*2, l, mid, ql, qr, v);
	if (qr > mid) modify(x*2+1, mid+1, r, ql, qr, v);
	up(x);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
	int t;
	scanf("%d", &t);
	rep(_i, 0, t){
		int n;
		scanf("%d", &n);
		//build(1, 1, n);
		col[1] = 1;
		int q;
		scanf("%d", &q);
		int cnt = 0;
		rep(i, 0, q){
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			modify(1, 1, n, x, y, v);
			cnt++;
		}
		printf("Case %d: The total value of the hook is %d.\n", _i+1, sum[1]);
	}
	return 0;			
}
