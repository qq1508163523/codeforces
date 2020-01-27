#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
//#define LOCAL
#define MAXN 2002
 
using namespace std;
 
int n;
int arr[MAXN];
 
int main(){
#ifdef LOCAL
   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
#endif
 
   scanf("%d",&n);
	
   for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
	
	int ans = 0;
	for(int l = 1; l <= n - 1; l++){
		map<int, int> _map;
		for(int i = l; i < n; i++){
			_map[arr[i]]++;
		}
		int cnt = 0;
		for(auto a : _map){
			cnt += a.second > 1;
		}
		if(!cnt){
			printf("%d\n", l);
			return 0;
		}
		for(int i = 1; i <= n - l; i++){
			_map[arr[i - 1]]++;
			if(_map[arr[i - 1]] == 2)cnt++;
			_map[arr[i + l - 1]]--;
			if(_map[arr[i + l - 1]] == 1)cnt--;
			if(!cnt){
				printf("%d\n", l);
				return 0;
			}
		}
		
	}
	return 0;	
}