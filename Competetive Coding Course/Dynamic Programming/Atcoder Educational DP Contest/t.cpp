
// Problem T - Educational Dynamic Programming Contest - AtCoder
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3010;
const int MOD = 1e9 + 7;

string s;
int vis[MAXN][MAXN],ok[MAXN][MAXN];
ll dp[MAXN][MAXN],somatorio[MAXN][MAXN];
int N;

ll solve(int pos, int ultimo);

ll calc(int pos,int ultimo);

ll solve(int pos,int ultimo){

	if(vis[pos][ultimo]) return dp[pos][ultimo];
	vis[pos][ultimo] = 1;

	if(ultimo > pos + 1) return dp[pos][ultimo] = 0;

	if(pos == 0) return dp[pos][ultimo] = 1;

	if(s[pos-1] == '>'){
		ll tot = calc(pos-1,N) - calc(pos-1,ultimo - 1);
		return dp[pos][ultimo] = ((tot + MOD) % MOD);
	}
	else{
		ll tot = calc(pos-1,ultimo-1);
		return dp[pos][ultimo] = (tot % MOD);
	}

}

ll calc(int pos,int ultimo){

	if(ultimo == 0) return 0;

	if(ok[pos][ultimo]) return somatorio[pos][ultimo];
	ok[pos][ultimo] = 1;

	ll tot = solve(pos,ultimo) + calc(pos,ultimo - 1);
	return somatorio[pos][ultimo] = (tot % MOD);

}

int main(){

	cin >> N;
	cin >> s;

	ll tot = 0;
	for(int i = 1;i<=N;i++){
		tot += solve(N-1,i);
	}

	tot %= MOD;

	cout << tot << endl;

	return 0;

}