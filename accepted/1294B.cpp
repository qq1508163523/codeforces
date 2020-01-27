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
#define MAXN 1005
#define pb push_back
#define ull long long int
 
using namespace std;
int t;
pair<int,int> pack[MAXN];
vector<char> ans; 
 
bool comp(const pair<int,int>& p1,const pair<int,int>& p2){
   if(p1.first == p2.first){
      return p1.second < p2.second;
   }else{
      return p1.first < p2.first;
   }
}
 
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
       for(int i = 0;i < n;i++){
           cin >> pack[i].first >> pack[i].second;
       }
 
       sort(pack,pack+n,comp);
 
      /* for(int i = 0;i < n;i++){
          cout << pack[i].first << " " << pack[i].second << endl;
       }*/
 
       int currX = 0,currY = 0;
       bool flag = 0;
       for(int i = 0;i < n;i++){
           int f = pack[i].first;
           int s = pack[i].second;
           if(currX <= f && currY <= s){
              for(int j = 0;j < f - currX;j++) ans.push_back('R');
              for(int j = 0;j < s - currY;j++) ans.push_back('U');
              currX = f;
              currY = s;
           }else{
              flag = 1;
              break;
           }
       }
 
       if(flag){
          cout << "NO\n";
       }else{
          cout << "YES\n";
          for(int i = 0;i < ans.size();i++) cout << ans[i];
          cout << endl;
       }
       ans.clear();
   }
   
   
   return 0;
}