#include<stdio.h>
int main() {
	int A[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int B[4][3];
	printf("* 전치 행렬 * \n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%3d", A[i][j]);
		}printf("\n");
	}
	printf("* A[3][4]출력 * \n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d", A[i][j]);
		}printf("\n");
	}
	printf("\n* B[4][3]출력 * \n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			B[i][j] = A[j][i];
			printf("%3d", B[i][j]);
		}printf("\n");
	}
}