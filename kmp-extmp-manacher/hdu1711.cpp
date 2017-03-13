#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i < k; i++)

using namespace std;

const int N = 1000000+10;

char a[N], b[N];
int fail[N];

void getfail(int n){
	int j = -1;
	fail[0] = -1;
	rep(i, 1, n){
		while (j > -1 && b[j+1] != b[i]) j = fail[j];
		if (b[j+1] == b[i]) j++;
		fail[i] = j;
		//cout << fail[i] << endl;
	}
}

int getpos(int n, int m){
	int j = -1;
	int ans = 0;
	rep(i, 0, n){
		while (j > -1 && b[j+1] != a[i]) j = fail[j];
		if (b[j+1] == a[i]) j++;
		if (j == m-1){
			ans++;
			j = fail[j];
		}
		//cout << i << ' ' << j << endl;
	}
	return ans;
}
		
int main(){
	int t;
	scanf("%d", &t);
	rep(i, 0, t){
		scanf("%s%s", b, a);
		int n = strlen(a), m = strlen(b);
		getfail(m);
		printf("%d\n", getpos(n, m));
	}
	return 0;
}
