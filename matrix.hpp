#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

class mtrx
{
public:
	double m, n;
	double **matrix;

	double **make_mtrx(double m, double n);
	double **multipulication_mtrx(double **a, double **b, double am, double an, double bm, double bn);
	double **addition_mtrx(double **a, double **b, double am, double an, double bm, double bn);
	double determinant(void);
	double c(double u);
	double **dct(void);
	void print_mtrx();
};

double **mtrx::make_mtrx(double m, double n)
{
	int i, j;
	double **matrix;
	matrix = (double**)malloc(sizeof(double *) * m);
	for (i=0;i<m;i++) {
		matrix[i] = (double*)malloc(sizeof(double) * n);
	}
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) {
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}

double **mtrx::multipulication_mtrx(double **a, double **b, double am, double an, double bm, double bn)
{
	int i, j, k;
	double **matrix;

	matrix = (double**)malloc(sizeof(double *) * am);
	for (i=0;i<am;i++) {
		matrix[i] = (double*)malloc(sizeof(double) * bn);
	}
	for (i=0;i<am;i++) {
		for (j=0;j<bn;j++) {
			matrix[i][j] = 0;
		}
	}

	if(an != bm){
		printf("二つの行列の積は存在しない");
		return 0;
	}else{
		for(i=0; i < am; i++){
			for(j=0; j < bn; j++){
				for(k=0; k < am; k++){
					matrix[i][j] += a[i][k]*b[k][j];
				}
			}
		}
		return matrix;
	}
}
double **mtrx::addition_mtrx(double **a, double **b, double am, double an, double bm, double bn)
{
	int i, j;
	double **matrix;

	matrix = (double**)malloc(sizeof(double *) * am);
	for (i=0;i<am;i++) {
		matrix[i] = (double*)malloc(sizeof(double) * bn);
	}

	if(am == bm && an == bn){
		for(i = 0; i < am; i++){
			for(j = 0; j < an; j++){
				matrix[i][j] = a[i][j] + b[i][j];
			}
		}
		return matrix;
	}else{
		printf("二つの行列の積は存在しない");
		return 0;
	}
}

double mtrx::determinant(void)
{
	int i;
	double det;
	double determinant = 0;
	double q = 1;
	int count = 0;
	int count1 = 0;
	double l;
	double c;
	double u;
	double w = 1;
	std::vector<double> comparison;

	if(m != n){
		printf("この行列の行列式は存在しない\n");
	}else{
		std::vector<int> nums(m);
		for(i = 1; i <= m; i++){
			nums[i-1] = i;
		}
    	do {
			do{
				do{
					c = 1;
					comparison.push_back(q);
					q = nums[q-1];
					count++;
					for(int k = 0; k < comparison.size(); k++){
						if(q == comparison[k]){
							c = 0;
						}
					}
					if(c == 0){
						count--;
					}
				}while(c!=0);

				count1 = 0;
				for(l = 1; l <= m; l++){
					for(int k = 0; k < comparison.size(); k++){
						if(l == comparison[k]){
							w=0;
							count1++;
						}
					}
					if(w == 0){
						w = 1;
					}else{
						q = l;
					}
				}
			}while(count1 != m);

			det = pow(-1, count);
			count = 0;
			u = comparison.size();
			for(int k = 0; k!= u; k++){
				comparison.pop_back();
			}
			c=1;
			q=1;
			for(i = 0; i < m; i++){
				det *= matrix[i][nums[i]-1];
			}
			determinant += det;
    	} while (next_permutation(nums.begin(), nums.end()));
	}
	return determinant;
}

void mtrx::print_mtrx()
{
	int i,j;
	for (i=0;i<m;i++) {
		printf("|  ");
		for (j=0;j<n;j++) {
			printf("%f  ",matrix[i][j]);
		}
		printf("|\n");
	}
}
double mtrx::c(double u){
	double u1;
	if(u == 0){
		u1 = 1 / sqrt(2);
	} else {
		u1 = 1;
	}
	return u1;
}

double **mtrx::dct(void){
	int i, j, k, l;
	double keisuu;
	double **matrix1;
	double sum;
	double sigma;
	matrix1 = (double**)malloc(sizeof(double *) * m);
	for (i=0;i<m;i++) {
		matrix1[i] = (double*)malloc(sizeof(double) * m);
	}
	for (i=0;i<m;i++) {
		for (j=0;j<m;j++) {
			keisuu = 2 * c(i) * c(j) / m;
			sum = 0;
			for(k=0;k<m;k++){
				for(l=0;l<m;l++){
					sigma = matrix[k][l] * cos(3.141592 * (2 * k +1) * i / (2 * m)) * cos(3.141592 * (2 * l +1) * j / (2 * m));
					if(sigma < 0.001 && sigma > -0.001){
						sigma =0;
					}
					sum += sigma;
				}
			}
			if(sum < 0.001 && sum > -0.001){
						sum =0;
			}
			matrix1[i][j] = keisuu * sum;
		}
	}
	return matrix1;
}