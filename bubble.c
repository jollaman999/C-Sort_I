#include <stdio.h>

#include "exchange.h"

int pass = 0;

void print_bubble(int *p, int n, int last) {
	int i;

	for (i = 0; i < n; i++) {
		if (i == last - pass + 1)
			printf("|");
		printf("%d ", p[i]);
	}
	printf("\n");
}

void bubble(int *p, int n) {
	int last;
	int i;

	for (last = n - 1; last >= 1; last--) {
		printf("\nPass %d\n", pass + 1);
		for (i = 0; i <= last - 1; i++) {
			print_bubble(p, n, n - 1);
			if (p[i] > p[i + 1])
				exchange(&p[i], &p[i + 1]);
		}
		print_bubble(p, n, n - 1);
		pass++;
	}
	printf("\nEnd!\n");
	pass = 0;
}

void bubble_reverse(int *p, int n) {
	int last;
	int i;

	for (last = n - 1; last >= 1; last--) {
		printf("\nPass %d\n", pass + 1);
		for (i = 0; i <= last - 1; i++) {
			print_bubble(p, n, n - 1);
			if (p[i] < p[i + 1])
				exchange(&p[i], &p[i + 1]);
		}
		print_bubble(p, n, n - 1);
		pass++;
	}
	printf("\nEnd!\n");
	pass = 0;
}

void bubble_fix(int *p, int n) {
	int last;
	int i;
	int is_chage;

	for (last = n - 1; last >= 1; last--) {
		printf("\nPass %d\n", pass + 1);
		is_chage = 0;
		for (i = 0; i <= last - 1; i++) {
			print_bubble(p, n, n - 1);
			if (p[i] > p[i + 1]) {
				exchange(&p[i], &p[i + 1]);
				is_chage = 1;
			}
		}
		if (!is_chage)
			break;

		print_bubble(p, n, n - 1);
		pass++;
	}
	printf("\nEnd!\n");
	pass = 0;
}

void bubble_fix_reverse(int *p, int n) {
	int last;
	int i;
	int is_chage;

	for (last = n - 1; last >= 1; last--) {
		printf("\nPass %d\n", pass + 1);
		is_chage = 0;
		for (i = 0; i <= last - 1; i++) {
			print_bubble(p, n, n - 1);
			if (p[i] < p[i + 1]) {
				exchange(&p[i], &p[i + 1]);
				is_chage = 1;
			}
		}
		if (!is_chage)
			break;

		print_bubble(p, n, n - 1);
		pass++;
	}
	printf("\nEnd!\n");
	pass = 0;
}