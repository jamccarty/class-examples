CC=gcc
% :: %.c
	$(CC) -g -Wall -Wvla -Werror $< -o $@

mybench1 : bench1.c mylloc.c
	$(CC) -g -Wall -Wvla -Werror bench1.c mylloc.c -o $@

mybench2 : bench2.c mylloc.c rand.c
	$(CC) -g -Wall -Wvla -Werror bench2.c mylloc.c rand.c -o $@ -lm

mybench3 : bench2.c mylloc_list.c rand.c
	$(CC) -g -Wall -Wvla -Werror bench2.c mylloc_list.c rand.c -o $@ -lm

origbench1 : bench1.c 
	$(CC) -g -Wall -Wvla -Werror bench1.c -o $@

origbench2 : bench2.c rand.c
	$(CC) -g -Wall -Wvla -Werror bench2.c rand.c -o $@ -lm

clean: 
	rm -i mybench* origbench*
