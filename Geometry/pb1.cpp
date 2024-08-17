#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9+7; 

void finddirection(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
    // vec1   (x2-x1)i +(y2-y1)j
    // vec2   (x3-x1)i+ (y3-y1)j 

    ll temp = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);

    if(temp<0) cout<<"RIGHT"<<endl;
    else if(temp>0) cout<<"LEFT"<<endl;
    else cout<<"TOUCH"<<endl;
}
int main()
{
      // there can be several methodloly to do this problem -- one methoed was coming was jee wala
      // you just locate where (0,0) wrt to the line then ax+by+c  put both points in the this equation if both of same sign then same side else opposite side --

      //a better approach is also there -- which uses cross product we know cross product of two vector in xy plane will go to third plane 
      //z plane do A X B if k have positive coeef then A of left side else right side  --

      int t;
      cin>> t;

      while(t--)
      {
          ll x1,y1,x2,y2,x3,y3;
          cin>>x1>>y1>>x2>>y2>>x3>>y3;

           finddirection(x1,y1,x2,y2,x3,y3);
      }
return 0;
}