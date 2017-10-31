#include <stdio.h>

void swap(int *a, int *b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int separate (int A[], int N){
	int j = 0, i;
	for(i = 0; i < N; i++){
		if(A[i] <= 0){
			swap(A[i], A[j]);
			j++;
		}
	}
	return j;
}

int findMissingPositive(int A[], int N){

	for(int i = 0; i < N; i++){
		if(abs(A[i]) - 1 < N && A[abs(A[i]) - 1] > 0)
			A[abs(A[i]) - 1] = -A[abs(A[i]) - 1];
	}

	for(int i = 0; i < N; i++){
		if (A[i] > 0)
			return i + 1;
	}

	return N + 1;
}

int solution(int A[], int N){
	int shift = separate(A, N);

	return findMissingPositive(A + shift, N-shift);
}

int main(){
	int A[] = {0, 10, 2, -10, -20};
	int N = 5;
	int missing = solution(A, N);
	printf("The smallest positive missing number is %d ", missing);
	scanf("Get %d", N);
	return 0;
}

