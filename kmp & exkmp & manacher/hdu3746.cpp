#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i < k; i++)

using namespace std;

char a[100010];
int fail[100010];

int getfail(int n){
	int j = -1;
	fail[0] = -1;
	rep(i, 1, n){
		while (j > -1 && a[j+1] != a[i]) j = fail[j];
		if (a[j+1] == a[i]) j++;
		fail[i] = j;
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
		scanf("%s", a);
		int n = strlen(a);
		int res = n-getfail(n)-1;
		if (n%res == 0 && n != res) printf("0\n");
		else printf("%d\n", res+n/res*res-n);
	}
	return 0;
}
