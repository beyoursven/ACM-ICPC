#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i < k; i++)

using namespace std;

char a[200010];
int fail[200010];
int cnt[200010];

int getfail(int n){
	int j = -1;
	fail[0] = -1;
	rep(i, 1, n){
		while (j > -1 && a[j+1] != a[i]) j = fail[j];
		if (a[j+1] == a[i]) j++;
		fail[i] = j;
	}
	rep(i, 0, n){
		int j = i;
		while (j != -1){
			cnt[j]++;
			cnt[j] %= 10007;
			j = fail[j];
		}
	}
	return fail[n-1];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	while (t--){
		memset(cnt, 0, sizeof(cnt));
		int n;
		scanf("%d%s", &n, a);
		getfail(n);
		int ans = 0;
		rep(i, 0, n) ans = (ans+cnt[i])%10007;
		printf("%d\n", ans);
	}
	return 0;
}
