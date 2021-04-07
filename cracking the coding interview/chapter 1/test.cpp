#include <bits/stdc++.h>
using namespace std;


vector<int> ParentNodes(int N, int* arrptr){
    N--;
	int A[N][2];
	int* ptr = (int*)A;
	for(int i = 0; i < 2*N; i++){
		*ptr = *arrptr;
		ptr++;
		arrptr++;
	}
	vector<int> result(N);
	result[0] = -1;
	for(int i = 0; i < N; i++){
		result[A[i][1]-1] = A[i][0];
	}
	return result;
}

int main() {
	int N;
	cin>>N;

	int A[N][2];

	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < 2; j++){
			cin>>A[i][j];
		}
	}

	int* arrptr = (int*) A;
	vector<int> res = ParentNodes(N, arrptr);
	for(int i = 0; i < N; i++){
		cout<<res[i]<<"\n";
	}
	return 0;
}
