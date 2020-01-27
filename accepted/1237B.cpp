#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
//#define LOCAL 
#define MAXN 100005
 
using namespace std;
int n;
int arr[MAXN];
int arr2[MAXN];
set<vector<int>> _set[MAXN]; 
int ans = 0;
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   
   scanf("%d",&n);
   for(int i=  0;i < n;i++){
       int tmp;
       scanf("%d",&tmp);
       arr[tmp] = i;
   }
 
   for(int i = 0;i < n;i++){
       scanf("%d",&arr2[i]);
   }
 
   int j = n;
   while(j--){
       int t = arr[arr2[j]];
       ans += t > n;
       n = t > n?n:t;
   }
   
   printf("%d",ans);
   return 0;
}
