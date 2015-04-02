#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#include "selection.h"
#include "bubble.h"
#include "insertion.h"

enum SELECT {
	SELECTION = 1,
	BUBBLE,
	BUBBLE_FIX,
	INSERTION,
};

int main(void) {
	int *p = NULL;
	int *p_copy = NULL;
	int n, i;
	int select, reverse;
	char yesno[255];

	printf("			Sort Algorithm v1.0\n");
	printf("					- By jollaman999 -\n\n");

/////////////////////////////////////////////////////////
re_input:
/////////////////////////////////////////////////////////
	while (1) {
		printf("How many inputs?: ");
		scanf("%d", &n); getchar();

		if (n <= 0)
			printf("\nPlease enter the positive number!\n");
		else
			break;
	}

	p = (int *)malloc(sizeof(int) * n);
	p_copy = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		printf("p[%d] Input: ", i);
		scanf("%d", &p[i]); getchar();
	}

	memcpy(p_copy, p, sizeof(int) * n);

/////////////////////////////////////////////////////////
re_sort:
/////////////////////////////////////////////////////////
	while (1) {
		printf("\nTry reverse sorting? (y/n): ");
		scanf("%s", &yesno); getchar();

		if (yesno[0] == 'y' || yesno[0] == 'Y') {
			reverse = 1;
			break;
		} else if (yesno[0] == 'n' || yesno[0] == 'N') {
			reverse = 0;
			break;
		} else
			printf("\nWrong input!\n");
	}

	while (1) {
		printf("\nWhich sorting you want to proceed?\n");
		printf("1. Selection Sort\n");
		printf("2. Bubble Sort\n");
		printf("3. Bubble Sort Fix\n");
		printf("4. Insertion Sort\n");
		printf("\nInput: ");
		scanf("%d", &select); getchar();

		if (select >= 1 && select <= 4)
			break;
		else
			printf("\nWrong input!\n");
	}


	printf("\nThe original array looks like..\n");
	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");

	switch (select) {
		case SELECTION:
			if (reverse) {
				printf("\nProceed reverse selection sort.\n\n");
				selection_reverse(p, n);
			} else {
				printf("\nProceed selection sort.\n\n");
				selection(p, n);
			}
			break;
		case BUBBLE:
			if (reverse) {
				printf("\nProceed reverse bubble sort.\n\n");
				bubble_reverse(p, n);
			} else {
				printf("\nProceed bubble sort.\n\n");
				bubble(p, n);
			}
			break;
		case BUBBLE_FIX:
			if (reverse) {
				printf("\nProceed reverse bubble sort fixed.\n\n");
				bubble_fix_reverse(p, n);
			} else {
				printf("\nProceed bubble sort fixed.\n\n");
				bubble_fix(p, n);
			}
			break;
		case INSERTION:
			if (reverse) {
				printf("\nProceed reverse insertion sort.\n\n");
				insertion_reverse(p, n);
			} else {
				printf("\nProceed insertion sort.\n\n");
				insertion(p, n);
			}
			break;
	}

	while (1) {
		printf("\nTry other sorting with existing inputs? (y/n): ");
		scanf("%s", &yesno); getchar();

		if (yesno[0] == 'y' || yesno[0] == 'Y') {
			memcpy(p, p_copy, sizeof(int) * n);
			goto re_sort;
			break;
		}
		else if (yesno[0] == 'n' || yesno[0] == 'N') {
			break;
		}
		else
			printf("\nWrong input!\n");
	}

	while (1) {
		printf("\nMake new array? (y/n): ");
		scanf("%s", &yesno); getchar();

		if (yesno[0] == 'y' || yesno[0] == 'Y') {
			printf("\n");
			goto re_input;
			break;
		}
		else if (yesno[0] == 'n' || yesno[0] == 'N') {
			printf("\nExiting program...\n");
			break;
		}
		else
			printf("\nWrong input!\n");
	}

	printf("\n");

	free(p);
	free(p_copy);

	return 0;
}
