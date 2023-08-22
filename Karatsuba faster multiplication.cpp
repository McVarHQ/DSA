#include<iostream>
#include<string>
using namespace std;
int karatsuba(int x, int y) {
    if (x < 10 && y < 10) {
        return x * y;
    } else {
        int n = max(to_string(x).length(), to_string(y).length());
        int half = n / 2;
        int a = x / (int)pow(10, half);
        int b = x % (int)pow(10, half);
        int c = y / (int)pow(10, half);
        int d = y % (int)pow(10, half);
        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);
        int ad_plus_bc = karatsuba(a+b, c+d) - ac - bd;
        return ac * (int)pow(10, 2 * half) + (ad_plus_bc * (int)pow(10, half)) + bd;
    }
}
int main()
{
    int x;
    cout<<"Enter first number:";
    cin>>x;
    int y;
    cout<<"Enter second number:";
    cin>>y;
    cout<<"product="<<karatsuba(x,y)<<endl;

}