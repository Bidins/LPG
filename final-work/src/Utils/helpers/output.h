#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include "../constants/consts.h"
#include "support.h"

void displayEvent(Event evnt) {
	printf("Data do evento:\n");
	printf("%02d/%02d/%4d\n", evnt.date.day, evnt.date.month, evnt.date.year);

	printf("\nComeca as: ");
	printf("%02d:%02d\n", evnt.begin.hour, evnt.begin.minute);

	printf("\nE termina as: ");
	printf("%02d:%02d\n", evnt.end.hour, evnt.end.minute);

	printf("\nDescricao do evento:\n");
	printf("%s\n", evnt.description);

	printf("\nSera no endereco: ");
	printf("%s\n", evnt.place);
}

void displayMultipleEvents(Event *listEvents, int numEvents, int start) {
	for (int i = start; i < numEvents; i++) {
		printf("\n----------------\n");
		printf("    EVENTO %d\n", i + 1);
		printf("----------------\n");
		displayEvent(listEvents[i]);
		printf("\n");
	}
}

void displayEventByDate(Event *listEvents, long date, int listSize) {
	int i = 0, counter = 0;
	Event *filteredEvnts = malloc(1 * sizeof(Event));
	long dateOriginal = 0;

	for (i = 0; i < listSize; i++) {
		dateOriginal = 0;
		dateOriginal = ((listEvents[i]).date.year * 365 * 24);
		dateOriginal += ((listEvents[i]).date.month - 1) * 30 * 24;
		dateOriginal += (((listEvents[i]).date.day - 1) * 24);

		if (date == dateOriginal) {
			counter++;
			filteredEvnts = realloc(filteredEvnts, counter * sizeof(Event));
			filteredEvnts[counter-1] = listEvents[i];
		}
	}

	if (counter) {
		printf("Exibindo eventos com esta data:\n\n");
		displayMultipleEvents(filteredEvnts, counter, 0);
	} else {
		printf("Nenhum evento encontrado dada esta data!\n");
	}
	free(filteredEvnts);
}

void displaySomeDate(Event *listEvents, long date, int listSize) {
	int i = 0, counter = 0, flag = 0;
	long dateOriginal = 0;

	for (i = 0; i < listSize; i++) {
		dateOriginal = 0;
		dateOriginal = ((listEvents[i]).date.year * 365 * 24);
		dateOriginal += ((listEvents[i]).date.month - 1) * 30 * 24;
		dateOriginal += (((listEvents[i]).date.day - 1) * 24);

		if (date <= dateOriginal) {
			flag = i;
			printf("\n----------------\n");
			printf("    EVENTO %d\n", i + 1);
			printf("----------------\n");
			displayEvent(listEvents[i]);
			printf("\n");
			counter++;
			if (counter == 5) break;
		}
	}

	if (!flag) {
		printf("Nenhum evento encontrado dada esta data!\n");
	}
}

#endif