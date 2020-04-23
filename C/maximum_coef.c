/*최고차항의 지수 배열에 담아 표현하기*/
#include <stdio.h>
#define Max(a,b)(((a)>(b)?(a):(b)))
#define Max_degree 120

typedef struct poly {
	int degree; //최고차항의 지수
	float coef[Max_degree]; //계수들을 저장
}poly;

poly poly_add(poly A, poly B) {
	poly C;
	int A_ptr = 0, B_ptr = 0, C_ptr = 0;
	int a_deg = A.degree;
	int b_deg = B.degree;
	C.degree = Max(A.degree, B.degree);

	while (A_ptr <= A.degree && B_ptr <= B.degree) {
		if (a_deg > b_deg) {
			C.coef[C_ptr++] = A.coef[A_ptr++];
			a_deg--;
		}
		else if (a_deg == b_deg) {

			C.coef[C_ptr++] = A.coef[A_ptr++] + B.coef[B_ptr++];
			a_deg--;
			b_deg--;
		}
		else {
			C.coef[C_ptr++] = B.coef[B_ptr++];
			b_deg--;
		}
	}
	return C;
}

void printPoly(poly P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++) {

		if (P.coef[i] == 0) {
			degree--;
			continue;
		}
		printf("%1.0fx^%d\t", P.coef[i], degree--);
	}
	printf("\n");
}
void main()
{
	poly A = { 10,{3,0,0,0,0,2,7,0,0,0,0} };
	poly B = { 4,{1,10,3,0,1} };
	poly C;

	C = poly_add(A, B);

	printf("   A(x) = "); printPoly(A);
	printf("   B(x) = "); printPoly(B);
	printf("   C(x) = "); printPoly(C);
}
