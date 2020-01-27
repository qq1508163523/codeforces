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
#define MAXN 2005
#define pb push_back
#define ull long long int
 
using namespace std;
int t;
 
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
       cin >> n;
       int cnt = 0;
       int arr[3];    
       
       int sqr = floor(sqrt(n));
       int tmp = n;
       int flag = 0;
       for(int i = 2;i <= sqr;i++){
           if(n % i == 0){
               arr[cnt] = i;
               cnt++;
               n /= i;
           }
 
           if(cnt == 2 && n > 1){
               flag = 1;
               break;
           }
       }
 
       if(flag && arr[0] != n && arr[1] != n){
          cout << "YES\n"; 
 
          cout << arr[0] << " " << arr[1] << " " << tmp/(arr[0]*arr[1]) << endl;
       }else{
          cout << "NO\n";
       }
   }
 
 
   return 0;
}