#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include "matrix.hpp"

int main()
{
	mtrx a;
	double ad;
	
	//行列Aの設定
	std::cout << "Aの行列m×n\n";
	std::cin >> a.m >> a.n;
	a.matrix = a.make_mtrx(a.m, a.n);

	//行列のアウトプット
	printf("行列 A\n");
	a.print_mtrx(); printf("\n");

	//行列Aの行列式
	ad = a.determinant();
	printf("行列Aの行列式の値：%f\n", ad);
}