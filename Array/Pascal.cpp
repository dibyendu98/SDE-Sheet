#include<iostream>
#include<vector>
using namespace std;

long long int nCr(int n,int r)
{
    long long int res=1;

    for(int i=0;i<r;i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

void Var1(int r)
{
    for(int i=0;i<r;i++)
    {

        cout<<nCr(r-1,i)<<" ";
    }
}

void Var1_2(int r)
{
   int prev=1;
   cout<<prev<<" ";
   for(int i=1;i<r;i++)
   {
       int curr=prev*(r-i)/(i);
       prev=curr;

       cout<<curr<<" ";
   }
}

void Var1_3(int r)
{
    for(int i=1;i<=r;i++)
    {
        Var1_2(i);
    }
}

int main()
{
    int r,c;
    cin>>r>>c;

   cout<<"VAriation 1 : Element at "<<r<<"th row "<<"and "<<c<<"th column is :=> "<<nCr(r-1,c-1);

   cout<<endl<<"Variation 2 : Elements for "<<r<<"th Row :=> ";
   Var1(r);
   cout<<endl;
   Var1_2(r);
   cout<<"Variation 3: ";
   Var1_3(r);
    return 0;
}