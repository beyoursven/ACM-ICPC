#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i < k; i++)

using namespace std;

string b[101];
int fail[101];

void getfail(int n, const string &b){
	int j = -1;
	fail[0] = -1;
	rep(i, 1, n){
		while (j > -1 && b[j+1] != b[i]) j = fail[j];
		if (b[j+1] == b[i]) j++;
		fail[i] = j;
	}
}

int kmp(int n, int k, const string &a){
	int j = -1;
	rep(i, 0, n){
		while (j > -1 && a[j+1] != b[k][i]) j = fail[j];
		if (a[j+1] == b[k][i]) j++;
		if (j == a.size()-1) return 1;
	}
	return 0;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while (t--){
		int cnt;
		string a;
		cin >> cnt;
		cin >> a;
		rep(i, 0, cnt-1){ cin >> b[i];}
		int n = a.size();
		int ans = 0;
		rep(len, 1, n+1){
			rep(pos, 0, n-len+1){
				string tmp = a.substr(pos, len);
				getfail(tmp.size(), tmp);
				int f = 1;
				rep(i, 0, cnt-1){
					if (!kmp(b[i].size(), i, tmp)){
						reverse(tmp.begin(), tmp.end());
						if (!kmp(b[i].size(), i, tmp)){
							f = 0;
							break;
						}
					}
				}
				if (f){
					if (ans < len){
						ans = len;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
