// Ivan Carvalho
// Problem W - Educational Dynamic Programming Contest - AtCoder
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2*1e5 + 10;

vector<int> adiciona[MAXN],retira[MAXN];
ll seg[4*MAXN],lazy[4*MAXN],dp[MAXN],valor[MAXN];
int N,M,ini[MAXN],fim[MAXN];

void propagate(int pos,int left,int right){

	if(lazy[pos] == 0) return;

	if(left != right){
		lazy[2*pos] += lazy[pos];
		lazy[2*pos+1] += lazy[pos];
	}

	seg[pos] += lazy[pos];
	lazy[pos] = 0;

}

void update(int pos,int left, int right,int i,int j,ll delta){

	propagate(pos,left,right);
	if(left > right || left > j || right < i) return;

	if(left >= i && right <= j){
		lazy[pos] += delta;
		propagate(pos,left,right);
		return;
	}

	int mid = (left+right)/2;
	update(2*pos,left,mid,i,j,delta);
	update(2*pos+1,mid+1,right,i,j,delta);

	seg[pos] = max(seg[2*pos],seg[2*pos+1]);

}

ll query(int pos,int left,int right,int i,int j){

	propagate(pos,left,right);

	if(left >= i && right <= j) return seg[pos];

	int mid = (left+right)/2;
	if(j <= mid) return query(2*pos,left,mid,i,j);
	else if(i >= mid + 1) return query(2*pos+1,mid+1,right,i,j);
	else return max(query(2*pos,left,mid,i,j), query(2*pos+1,mid+1,right,i,j));

}

int main(){

	scanf("%d %d",&N,&M);

	for(int i = 1;i<=M;i++){
		scanf("%d %d %lld",&ini[i],&fim[i],&valor[i]);
		adiciona[ini[i]].push_back(i);
		retira[fim[i]].push_back(i);
	}

	for(int i = 1;i<=N;i++){
		for(int j : adiciona[i]){
			update(1,0,N,0,ini[j] - 1,valor[j]);
		}
		dp[i] = query(1,0,N,0,i-1);
		update(1,0,N,i,i,dp[i]);
		for(int j : retira[i]){
			update(1,0,N,0,ini[j] - 1,-valor[j]);
		}
	}

	ll best = 0;
	for(int i = 1;i<=N;i++) best = max(best,dp[i]);
	printf("%lld\n",best);

	return 0;

}