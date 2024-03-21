#include<iostream>
using namespace std;

void f(int x){
    cout<<x ;
    while (x>4)
    {
        f(x-1);
        x--;
    }
    
}

int main(){
    f(7);
} 