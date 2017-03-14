#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i < k; i++)

using namespace std;

char a[100010];
int fail[100010];
char f[1001];

void getfail(int n){
	int j = -1;
	fail[0] = -1;
	rep(i, 1, n){
		while (j > -1 && a[i] != f[a[j+1]]) j = fail[j];
		if (a[i] == f[a[j+1]]) j++;
		fail[i] = j;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	while (t--){
		char s[100];
		scanf("%s", s);
		int m = strlen(s);
		rep(i, 0, m) f[(int)s[i]] = 'a'+i;
		scanf("%s", a);
		int n = strlen(a);
		getfail(n);
		int j = fail[n-1];
		while ((n-j-1)*2 < n) j = fail[j];
		int res = n-j-1;
		printf("%s", a);
		//cout << res << ' ' << n << endl;
		rep(i, n, 2*res) printf("%c", f[a[i-res]]);
		printf("\n");
	}
	return 0;
}
