// Ivan Carvalho
// Problem V - Educational Dynamic Programming Contest - AtCoder
// Link : https://atcoder.jp/contests/dp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

vector<int> grafo[MAXN];
ll dp[MAXN],correction[MAXN],ansP[MAXN];
int N,M;

void dfs1(int v,int p){

	dp[v] = 1;
	vector<int> children;
	for(int u : grafo[v]){
		if(u == p) continue;
		dfs1(u,v);
		dp[v] = (dp[v] * (1 + dp[u])) % M;
		children.push_back(u);
	}

	vector<ll> prefV,sufV;
	ll pref = 1, suf = 1;
	for(int i = 0;i<(int)children.size();i++){
		int u = children[i];
		prefV.push_back(pref);
		pref = (pref * (1 + dp[u])) % M;
	}
	for(int i = (int)children.size() - 1;i>=0;i--){
		int u = children[i];
		sufV.push_back(suf);
		suf = (suf * (1 + dp[u])) % M;
	}
	reverse(sufV.begin(),sufV.end());
	for(int i = 0;i<(int)children.size();i++){
		int u = children[i];
		correction[u] = (prefV[i]*sufV[i]) % M;
	}

}

void dfs2(int v,int p){

	ansP[v] = (dp[v] * correction[v]) % M;

	for(int u : grafo[v]){
		if(u == p) continue;
		correction[u] = (correction[u] * (correction[v]) + 1) % M;
		dfs2(u,v);
	}

}

int main(){

	scanf("%d %d",&N,&M);
	for(int i = 1;i<N;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	dfs1(1,-1);
	correction[1] = 1;
	dfs2(1,-1);

	for(int i = 1;i<=N;i++) printf("%lld\n",ansP[i]);

	return 0;

}