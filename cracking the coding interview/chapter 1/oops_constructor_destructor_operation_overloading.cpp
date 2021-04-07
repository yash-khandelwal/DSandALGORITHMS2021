#include <iostream>
using namespace std;

class A{
	int classNum;
	public:
	// static member declairation
	static int x;
	static int heap_sz;
	A(int classNum){
	    x++;
	    this -> classNum = classNum;
	    cout<<"Constructor called: "<<classNum<<"\n";
	}
	~A(){
		cout<<"destructor called: "<<classNum<<"\n";
		x--;
	}
	// to find the class allocated in the heap memory we will overload the "new" operator
	void* operator new(size_t sz){
	    void* p = malloc(sz); // if we will use new again the constructor will be called again
		heap_sz++;
		return p;
	}
	void operator delete(void* p){
        free(p);
        heap_sz--;
	}
};
// static member assignment/initialization/defined
int A::x = 0;
int A::heap_sz = 0;
int main() {
	A a1(1), a2(2); // local variables --> stack memory
	A a3(3), a4(4), a5(5);
	// dynamic allocation --> heap memory
	// A* ptr = (A*)malloc(sizeof(A));  // malloc only allocates memory doesnot call the constructor
	A* ptr2 = new A(6); // new allocates the memory as well as call the constructor
	// free(ptr); // just disallocate the memory but doesnot call the destructor
	delete ptr2; // disallocates the memory as well as call the destructor
	cout<<A::x<<" "<<A::heap_sz<<"\n";
	return 0;
}
