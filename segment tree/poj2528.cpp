#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

#define rep(i, j, k) for (int i = j; i < k; i++)
#define mid (l+r)/2

using namespace std;

const int N = 10010; 

struct Node{
	int col;
	int l, r;
}tree[15*N];

map<int, int> m;
vector<int> tmp;
int tmpl[N], tmpr[N], vis[N];
int ans;

void down(int x){
	if (tree[x].col){
		tree[x*2].col = tree[x*2+1].col = tree[x].col;
		tree[x].col = 0;	
	}
}

void buildtree(int x, int l, int r){
	tree[x].l = l;
	tree[x].r = r;
	tree[x].col = 0;
	if (l == r) return;
	buildtree(x*2, l, mid);
	buildtree(x*2+1, mid+1, r);
}

void modify(int x, int ql, int qr, int v){
	int l = tree[x].l, r = tree[x].r;
	if (ql <= l && r <= qr){
		tree[x].col = v;
		return;
	}
	down(x);
	if (ql <= mid) modify(x*2, ql, qr, v);
	if (qr > mid) modify(x*2+1, ql, qr, v);
}

int query(int x){
	int l = tree[x].l, r = tree[x].r;
	if (tree[x].col != 0){
		if (!vis[tree[x].col]){
			vis[tree[x].col] = 1;
			return 1;
		}
		return 0;
	}
	if (l == r) return 0;
	return query(x*2)+query(x*2+1);
}	

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	while (t--){
		m.clear();
		tmp.clear();
		memset(vis, 0, sizeof(vis));
		int n;
		scanf("%d", &n);
		rep(i, 0, n){
			int l, r;
			scanf("%d%d", &l, &r);
			tmp.push_back(l);
			tmp.push_back(r);
			tmpl[i] = l;
			tmpr[i] = r;
		}
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		int res = 0;
		rep(i, 0, tmp.size()){
			if (tmp[i] != res){
				if (tmp[i]-res > 1) tmp.insert(tmp.begin()+i, tmp[i]);
				res = tmp[i];
			}
		}
		int cnt = tmp.size();
		buildtree(1, 1, cnt);
		rep(i, 0, n){
			int l = upper_bound(tmp.begin(), tmp.end(), tmpl[i])-tmp.begin();
			int r = upper_bound(tmp.begin(), tmp.end(), tmpr[i])-tmp.begin();
			//cout << l << ' ' << r << endl;
			modify(1, l, r, i+1);
		}
		printf("%d\n", query(1));
	}
	return 0;
}
