#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
int n;
pair<int,int> a[100010];
int bit[1000010];
 
int get(int i) {
	int r = 0;
	for(;i<1000010;i+=i&(-i)) r = max (r, bit[i]);
	return r;
}
 
void update(int i,int v) {
	for(;i>0;i&=(i-1)) bit[i] = max (bit[i], v);
}
 
int main() {
	scanf("%d", &n);
	for(int i=0;i<n;++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
		a[i].second = -a[i].second;
	}
	sort( a, a+n);
	int res = 0;
	for(int i=0;i<n;++i) {
		int t = get( -a[i].second) + 1;
		res = max (res, t);
		update( -a[i].second, t);
	}
	cout << res << endl;
	return 0;