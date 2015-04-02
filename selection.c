#include <stdio.h>

#include "exchange.h"
#include "max-min_search.h"

void print_selection(int *p, int n, int last) {
	int i;

	for (i = 0; i < n; i++) {
		if (i == last)
			printf("|");
		printf("%d ", p[i]);
	}
	printf("\n");
}

void selection(int *p, int n) {
	int last;
	int max_index;

	for (last = n - 1; last >= 1; last--) {
		max_index = max_search(p, 0, last, n);
		printf("max = %d\n\n", p[max_index]);
		exchange(&p[max_index], &p[last]);
		print_selection(p, n, last);
	}
	printf("\nEnd!\n");
}

void selection_reverse(int *p, int n) {
	int last;
	int min_index;

	for (last = n - 1; last >= 1; last--) {
		min_index = min_search(p, 0, last, n);
		printf("min = %d\n\n", p[min_index]);
		exchange(&p[min_index], &p[last]);
		print_selection(p, n, last);
	}
	printf("\nEnd!\n");
}