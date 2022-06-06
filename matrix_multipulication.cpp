#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include "matrix.hpp"

int main()
{
	mtrx a,b,c,d,e;
	
	//行列Aの設定
	std::cout << "Aの行列m×n\n";
	std::cin >> a.m >> a.n;
	a.matrix = a.make_mtrx(a.m, a.n);

	//行列Bの設定
	std::cout << "Bの行列m×n\n";
	std::cin >> b.m >> b.n;
	b.matrix = b.make_mtrx(b.m, b.n);

	//行列 C ＝ AB
	c.m = a.m; c.n = b.n;
	c.matrix = c.multipulication_mtrx(a.matrix, b.matrix, a.m, a.n, b.m, b.n);

	//行列のアウトプット
	printf("行列 A\n");
	a.print_mtrx(); printf("\n");

	printf("行列 B\n");
	b.print_mtrx(); printf("\n");

	printf("行列　C = AB\n");
	c.print_mtrx(); printf("\n");
}