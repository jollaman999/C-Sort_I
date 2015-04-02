#include <stdio.h>

void print_insertion(int *p, int n, int i, int loc, int newItem) {
	int j;

	for (j = 0; j < n; j++) {
		if (j == loc)
			printf("^");
		else if (i == j)
			printf("|");
		printf("%d ", p[j]);
	}
	printf("	%d\n", newItem);
}

void insertion(int *p, int n) {
	int i;
	int loc;
	int newItem;
	int is_skip;

	for (i = 1; i < n; i++) {
		loc = i - 1;
		newItem = p[i];
		print_insertion(p, n, i, loc, newItem);
		is_skip = 1;

		while (loc >= 0 && newItem < p[loc]) {
			p[loc + 1] = p[loc];
			loc--;
			is_skip = 0;
		}
		if (is_skip)
			printf("while Skiped!\n");
		else
			print_insertion(p, n, i, loc, newItem);

		p[loc + 1] = newItem;
		print_insertion(p, n, i, loc, newItem);
		printf("\n");
	}
	printf("\nEnd!\n");
}

void insertion_reverse(int *p, int n) {
	int i;
	int loc;
	int newItem;
	int is_skip;

	for (i = 1; i < n; i++) {
		loc = i - 1;
		newItem = p[i];
		print_insertion(p, n, i, loc, newItem);
		is_skip = 1;

		while (loc >= 0 && newItem > p[loc]) {
			p[loc + 1] = p[loc];
			loc--;
			is_skip = 0;
		}
		if (is_skip)
			printf("while Skiped!\n");
		else
			print_insertion(p, n, i, loc, newItem);

		p[loc + 1] = newItem;
		print_insertion(p, n, i, loc, newItem);
		printf("\n");
	}
	printf("\nEnd!\n");
}