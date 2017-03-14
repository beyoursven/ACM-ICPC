#include<bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i < k; i++)
#define mid (l+r)/2
#define LL long long 

using namespace std;

const int N = 100010;

LL sum[N][7];
LL a[N];
int col[16*N];

void down(int x){
	if (col[x] != -1){
		col[x*2] = col[x*2+1] = col[x];
		col[x] = -1;
	}
}

void build(int x, int l, int r){
	if (l == r){
		scanf("%lld", &a[l]);
		return;
	}
	build(x*2, l, mid);
	build(x*2+1, mid+1, r);
}

void modify(int x, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr){
		col[x]++;
		return;
	}
	down(x);
	if (ql <= mid) modify(x*2, l, mid, ql, qr);
	if (qr > mid) modify(x*2+1, mid+1, r, ql, qr);
}

LL query(int x, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr && col[x] != -1){
		int tmp = min(7, col[x]);
		return sum[r][tmp]-sum[l-1][tmp];
	}
	down(x);
	LL res = 0;
	if (ql <= mid) res += query(x*2, l, mid, ql, qr);
	if (qr > mid) res += query(x*2+1, mid+1, r, ql, qr);
	return res;
} 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	int cnt = 0;
	while (scanf("%d", &n) != EOF){
		cnt++;
		printf("Case #%d:\n", cnt);
		col[1] = 0;
		build(1, 1, n);
		rep(i, 1, n+1){
			rep(j, 0, 8){
				sum[i][j] = sum[i-1][j]+a[i];
				if (a[i] > 1) a[i] = sqrt(a[i]);
			}
		}		
		int q;
		scanf("%d", &q);
		rep(i, 0, q){
			int x, l, r;
			scanf("%d%d%d", &x, &l, &r);
			if (l > r) swap(l, r);
			if (x == 0) modify(1, 1, n, l, r);
			else printf("%I64d\n", query(1, 1, n, l, r));
		}
		printf("\n");
	}
	return 0;
}
