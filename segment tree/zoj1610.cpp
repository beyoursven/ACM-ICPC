#include <cstring>
#include <cstdio>
#include <iostream>
#define rep(i, j, k) for(int i = j; i < k; i++)
#define mid (l+r)/2

using namespace std;

const int N = 8010;

int cnt[N], v[N], coll[4*N], colr[4*N], col[4*N];

void down(int x, int l, int r){
	if (col[x]){
		col[x*2] = col[x*2+1] = col[x];
		coll[mid] = coll[mid+1] = col[x];
		col[x] = 0;
	}
}

void up(int x){
	col[x*2] == col[x*2+1] ? col[x] = col[x*2] : col[x] = 0;
}

void modify(int x, int l, int r, int ql, int qr, int v){
	if (ql <= l && r <= qr){
		col[x] = coll[l] = coll[r] = v;
		return;
	}
	down(x, l, r);
	if (ql <= mid) modify(x*2, l, mid, ql, qr, v);
	if (qr > mid) modify(x*2+1, mid+1, r, ql, qr, v);
	//up(x);
}

void query(int x, int l, int r){
	if (col[x] != 0){
		//if (col[x] == 4) cout << "yes " << l << ' ' << r << endl;
		if (coll[l] != coll[l-1]) cnt[col[x]]++;
		return;
	}
	if (l == r) return;
	query(x*2, l, mid);
	query(x*2+1, mid+1, r);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	while (scanf("%d", &n) != EOF){
		memset(cnt, 0, sizeof(cnt));
		memset(coll, 0, sizeof(coll));
		memset(colr, 0, sizeof(colr));
		memset(col, 0, sizeof(col));
		memset(v, 0, sizeof(v));
		//build(1, 1, 8001);
		rep(i, 0, n){
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			x++; y++; v++;
			x++;
			modify(1, 1, 8002, x, y, v);
		}
		query(1, 1, 8002);
		rep(i, 1, 8002){
			if (cnt[i]) printf("%d %d\n", i-1, cnt[i]);
		}
		printf("\n");
	}
	return 0;
}
		
