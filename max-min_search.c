#include <stdio.h>
#include <stdlib.h>	// exit();

int max_search(int *p, int start, int end, int n) {
	int i;
	int max;
	int max_index = start;

	if (start > end) {
		printf("max_search: [Error] Start index can't bigger than end index!!\n");
		printf("Exiting program...\n");
		exit(1);
	}

	if (end - start + 1 > n) {
		printf("max_search: [Error] Search range exceeded!!\n");
		printf("Exiting program...\n");
		exit(1);
	}

	if (start == end) {
		return max_index;
	}

	max = p[start];

	for (i = start + 1; i <= end; i++) {
		if (p[i] > max) {
			max = p[i];
			max_index = i;
		}
		else
			continue;
	}

	return max_index;
}

int min_search(int *p, int start, int end, int n) {
	int i;
	int min;
	int min_index = start;

	if (start > end) {
		printf("min_search: [Error] Start index can't bigger than end index!!\n");
		printf("Exiting program...\n");
		exit(1);
	}

	if (end - start + 1 > n) {
		printf("min_search: [Error] Search range exceeded!!\n");
		printf("Exiting program...\n");
		exit(1);
	}

	if (start == end) {
		return min_index;
	}

	min = p[start];

	for (i = start + 1; i <= end; i++) {
		if (p[i] < min) {
			min = p[i];
			min_index = i;
		}
		else
			continue;
	}

	return min_index;
}
