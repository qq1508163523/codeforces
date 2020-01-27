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
#define pb push_back
#define ull long long int
 
using namespace std;
int t;
ull arr[MAXN];
ull pre[MAXN],last[MAXN];
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin >> t;
 
   while(t--){
       int n;
       ull total = 0;
       cin >> n;
       for(int i = 0;i < n;i++){
           cin >> arr[i];
           total += arr[i];
       }
  
       memcpy(pre,arr,sizeof(arr));
       memcpy(last,arr,sizeof(arr));
 
       ull max1 = pre[0],max2 = last[1];
 
       for(int i = 1;i < n - 1;i++){
           if(pre[i - 1] > 0) pre[i] += pre[i - 1];
       }
 
       for(int i = 1;i < n - 1;i++) max1 = max(max1,pre[i]);
 
       for(int i = 2;i < n;i++){
           if(last[i - 1] > 0) last[i] += last[i - 1];
       }
 
       for(int i = 2;i < n;i++) max2 = max(max2,last[i]);
 
       ull ans = max(max1,max2);
       if(ans >= total) cout << "NO" << endl;
       else cout << "YES" << endl;
 
   }
  
   
   return 0;
}