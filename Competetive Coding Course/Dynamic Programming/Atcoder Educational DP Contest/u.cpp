// Ivan Carvalho
// Problem U - Educational Dynamic Programming Contest - AtCoder
// Link : https://atcoder.jp/contests/dp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 16;
const int MAXL = (1 << 16) + 10;
const ll NEG = -1e18;

vector<int> grafo[MAXL];
ll valor[MAXL],dp[MAXL],mat[MAXN][MAXN];
int vis[MAXL],N;

void brute(int pos,int bitmask,int submask){

	if(pos == N){
		if(__builtin_popcount(submask) == 0) return;
		grafo[bitmask].push_back(submask);
		return;
	}

	brute(pos+1,bitmask,submask);
	brute(pos+1, bitmask | (1 << pos), submask );
	brute(pos+1, bitmask | (1 << pos), submask | (1 << pos) );

}

void calcula(){

	for(int bitmask = 1;bitmask < (1 << N);bitmask++){
		for(int i = 0;i<N;i++){
			if(!(bitmask & (1 << i))) continue;
			for(int j = i+1;j<N;j++){
				if(!(bitmask & (1 << j))) continue;
				valor[bitmask] += mat[i][j];
			}
		}
	}

}

ll solve(int bitmask){

	if(bitmask == 0) return 0;
	if(vis[bitmask]) return dp[bitmask];

	vis[bitmask] = 1;

	ll best = NEG;

	for(int submask : grafo[bitmask]){
		best = max(best, solve(bitmask ^ submask) + valor[submask] );
	}

	return dp[bitmask] = best;

}

int main(){

	cin >> N;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			cin >> mat[i][j];
		}
	}

	brute(0,0,0);
	calcula();

	cout << solve((1 << N) - 1) << endl;

	return 0;

}