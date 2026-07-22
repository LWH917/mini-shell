all: my_cat my_cp

my_cat: my_cat.c
	gcc my_cat.c -o my_cat

my_cp: my_cp.c
	gcc my_cp.c -o my_cp

clean:
	rm -f my_cat my_cp
