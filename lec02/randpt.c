#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_point(int *var1, int *var2, int *var3){
	int x, y, z;
	x = *var1;
	y = *var2;
	z = *var3;

	x = rand() % 10;
	y = rand() % 10;
	z = rand() % 10;

	*var1 = x;
	*var2 = y;
	*var3 = z;
}

void main() {
	srand(time(0));
	int x,y,z;
	rand_point(&x, &y, &z);
	printf("point: %d, %d, %d\n", x, y, z);
}
