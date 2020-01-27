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
#define MAXN 200005
#define ll long long int
 
using namespace std;
int t,arr[MAXN];
ll nums[MAXN];
char ans[MAXN];
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin >> t;
 
   for(int i = 1;i < MAXN;i++) nums[i] = nums[i - 1] + i;
 
   while(t--){
       int n;
       cin >> n;
       for(int i = 0;i < n;i++) cin >> arr[i];
 
       memset(ans,'0',sizeof(ans));
       ans[0] = '1';
       ans[n - 1] = '1';
 
       int l = 0,r = n - 1,curr = n;
       ll sum = nums[n];
             //cout << "sum:" << sum << endl;
       while(l < r){
          if(arr[l] < arr[r]){
             sum -= arr[r];
             r--;
          }else{
             sum -= arr[l];
             l++;
          }
          curr--;
          if(sum == nums[curr]) ans[curr - 1] = 49;
       }
 
       for(int i = 0;i < n;i++) cout << ans[i];
       cout << endl;
   }
   
   return 0;
}