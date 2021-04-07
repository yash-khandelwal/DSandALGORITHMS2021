#include<bits/stdc++.h>
using namespace std;
int x = 0;

class A{
    public:
	A(){
//        cout<<”hello from constructor\n”;
        x++;
    }

    ~A(){
        x--;
    }
};

int main(){
	A a,b,c;
	A* temp = (A*)malloc(sizeof(A));
	A* newptr = new A();
	delete newptr;
	cout<<x<<"\n";
    return 0;
}
