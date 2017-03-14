#include <bits/stdc++.h>

using namespace std;

string a, b;

void getfail(int n){
	int j = -1;
	fail[0] = -1;
	rep(i, 1, n){
		while (j > -1 && b[j+1] != b[i]) j = fail[j];
		if (b[j+1] == b[i]) j++;
		fail[j] = 0;
	}
}

int kmp(int n, int m){
	int j = -1, ans = 0;
	rep(i, 0, n){
		while (j > -1 && b[j+1] != a[i]) j = fail[j];
		if (b[j+1] == a[i]) j++;
		if (j == m){
			ans++;
			j = -1;
		}
	}
	return ans;
}

int main(){
	cin >> a;
	while (a != "#"){
		cin >> b;
		int n = a.size();
		int m = b.size();
		getfail(m);
		cout << kmp(n, m) << endl;
	}
	return 0;
}	
