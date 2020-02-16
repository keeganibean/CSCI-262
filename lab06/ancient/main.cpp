#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    double n, x, xold;
    double est1, est2;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"What is your guess?";
    cin>>x;
    while(true)
    {
        est1=n/x;
        xold=x;
        x=(x+est1)/2;
        cout<< setprecision(8)<<fixed<<x<<endl;
        if (abs(xold-x)<=.00000001)
            break;
    }
    return 0;
}