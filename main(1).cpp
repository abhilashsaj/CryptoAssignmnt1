#include<iostream> 
using namespace std; 
  
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
  
int main() 
{ 
    int a, m;
    cin>>a>>m;
    
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "\nNo Inverse. "; 
    else
    { 
        int res = (x%m + m) % m; 
        cout << "\nModular multiplicative inverse: " << res; 
    } 
    return 0; 
} 