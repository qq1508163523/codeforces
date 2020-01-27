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
#define MAXN 205
#define pb push_back
#define ull long long int
 
using namespace std;
ull n;
char str[MAXN];
vector<int> vt;
vector<int> vt2;
vector<int> org;
vector<int> ans;
char target;
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&n);
   scanf("%s",str + 1);
 
   for(int i = 1;i <= n;i++){
       if(str[i] == 'B') vt.push_back(i);
       else vt2.push_back(i);
   }
 
   if(!(vt.size() % 2 == 0 || vt2.size() % 2 == 0)){
       printf("-1");
       return 0;
   }
 
   org.push_back(0);
   if(vt.size() % 2 == 0){
       for(int i = 0;i < vt2.size();i++) org.push_back(vt2[i]);
   }else{
       for(int i = 0;i < vt.size();i++) org.push_back(vt[i]);
   }
   org.push_back(n+1);
   for(int i = 0;i < org.size() - 1;i++){
       if((org[i+1] - org[i]) % 2 == 0){
           org[i+1]--;
           ans.push_back(org[i+1]);
       }
       for(int j = org[i] + 1;j < org[i+1];j += 2)
            ans.push_back(j);
   }
 
   cout << ans.size() << endl;
   for(int i = 0;i < ans.size();i++){
      cout << ans[i]<< " ";
   }
   return 0;
}