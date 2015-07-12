#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long gcd( long long a, long long b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int main(){
    long long aux,i,n,x,y,a,b,m,ca,cb;
    vector<string> res;
    cin>>n>>x>>y;
    ca = a = y / gcd(x,y);
    cb = b = x / gcd(x,y);
    while(a!=b){
        if(a<b){
            res.push_back("Vanya");
            a+=ca;
        }
        else{
            res.push_back("Vova");
            b+=cb;
        }
    }
    res.push_back("Both");
    res.push_back("Both");
    m=res.size();
    for(i=0;i<n;i++){
        cin>>aux;
        cout<<res[(aux-1)%m]<<endl;
    }
}
