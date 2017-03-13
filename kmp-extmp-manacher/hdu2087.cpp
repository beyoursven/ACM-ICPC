#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i < k; i++)

using namespace std;

const int N = 1010;

int fail[N];
char a[N], b[N];

void getfail(int n){
	int j = -1;
	fail[0] = -1;
	rep(i, 1, n){
		while (j > -1 && b[j+1] != b[i]) j = fail[j];
		if (b[j+1] == b[i]) j++;
		fail[i] = j;
	}
}

int kmp(int n, int m){
	int j = -1, ans = 0;
	rep(i, 0, n){
		while (j > -1 && b[j+1] != a[i]) j = fail[j];
		if (b[j+1] == a[i]) j++;
		if (j == m-1){
			ans++;
			j = -1;
		}
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	scanf("%s", a);
	while (a[0] != '#'){
		scanf("%s", b);
		int n = strlen(a);
		int m = strlen(b);
		getfail(m);
		printf("%d\n", kmp(n, m));
		scanf("%s", a);
	}
	return 0;
}	
