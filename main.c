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
		printf("몇개를 입력 받으시겠습니까?: ");
		scanf("%d", &n); getchar();

		if (n <= 0)
			printf("\n양의 정수를 입력해 주십시오!\n");
		else
			break;
	}

	p = (int *)malloc(sizeof(int) * n);
	p_copy = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		printf("p[%d] 입력: ", i);
		scanf("%d", &p[i]); getchar();
	}

	memcpy(p_copy, p, sizeof(int) * n);

/////////////////////////////////////////////////////////
re_sort:
/////////////////////////////////////////////////////////
	while (1) {
		printf("\n역정렬을 수행하시겠습니까? (y/n): ");
		scanf("%s", &yesno); getchar();

		if (yesno[0] == 'y' || yesno[0] == 'Y') {
			reverse = 1;
			break;
		} else if (yesno[0] == 'n' || yesno[0] == 'N') {
			reverse = 0;
			break;
		} else
			printf("\n잘 못 입력하셨습니다!\n");
	}

	while (1) {
		printf("\n어떤 정렬을 수행 하시겠습니까?\n");
		printf("1. 선택 정렬 (Selection Sort)\n");
		printf("2. 버블 정렬 (Bubble Sort)\n");
		printf("3. 버블 정렬 수정판 (Bubble Sort Fix)\n");
		printf("4. 삽입 정렬 (Insertion Sort)\n");
		printf("\n입력: ");
		scanf("%d", &select); getchar();

		if (select >= 1 && select <= 4)
			break;
		else
			printf("\n잘 못 입력하셨습니다!\n");
	}


	printf("\n정렬하기 전의 배열은 다음과 같습니다.\n");
	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");

	switch (select) {
		case SELECTION:
			if (reverse) {
				printf("\n선택 역정렬을 수행합니다\n\n");
				selection_reverse(p, n);
			} else {
				printf("\n선택 정렬을 수행합니다\n\n");
				selection(p, n);
			}
			break;
		case BUBBLE:
			if (reverse) {
				printf("\n버블 역정렬을 수행합니다\n\n");
				bubble_reverse(p, n);
			} else {
				printf("\n버블 정렬을 수행합니다\n\n");
				bubble(p, n);
			}
			break;
		case BUBBLE_FIX:
			if (reverse) {
				printf("\n버블 역정렬 수정판을 수행합니다\n\n");
				bubble_fix_reverse(p, n);
			} else {
				printf("\n버블 정렬 수정판을 수행합니다\n\n");
				bubble_fix(p, n);
			}
			break;
		case INSERTION:
			if (reverse) {
				printf("\n삽입 역정렬을 수행합니다\n\n");
				insertion_reverse(p, n);
			} else {
				printf("\n삽입 정렬을 수행합니다\n\n");
				insertion(p, n);
			}
			break;
	}

	while (1) {
		printf("\n기존 입력값으로 다른정렬을 수행하시겠습니까? (y/n): ");
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
			printf("\n잘 못 입력하셨습니다!\n");
	}

	while (1) {
		printf("\n배열을 새로 입력 받으시겠습니까? (y/n): ");
		scanf("%s", &yesno); getchar();

		if (yesno[0] == 'y' || yesno[0] == 'Y') {
			printf("\n");
			goto re_input;
			break;
		}
		else if (yesno[0] == 'n' || yesno[0] == 'N') {
			printf("\n프로그램을 종료합니다.\n");
			break;
		}
		else
			printf("\n잘 못 입력하셨습니다!\n");
	}

	printf("\n");

	free(p);
	free(p_copy);

	return 0;
}