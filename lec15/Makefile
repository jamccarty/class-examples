CC=gcc
% :: %.c
	$(CC) -g -Wall -Wvla -Werror $< -o $@

matrix : matrix.c generateMatrix.c
	$(CC) -g -Wall -Wvla -Werror matrix.c generateMatrix.c -o $@
