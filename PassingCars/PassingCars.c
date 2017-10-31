#include <stdio.h>

int solution(int A[], int N){

	int passing = 0;

	for(int i = 0; i < N; i++){
		if(A[i] == 0){
			for(int j = i; j < N; j++){
				if(A[j] == 1)
					passing++;
			} 
		}
	}

	if(passing > 1000000000)
		return -1;
	else 
		return passing;
}

int main(){
	int A[] = {0,1,0,1,1};
	int N = 5;

	int res = solution(A,N);
	printf("O resultado é %d", res);
	scanf(" %d", N);
	return 0;
}
