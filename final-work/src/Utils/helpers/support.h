#ifndef SUPPORT_H
#define SUPPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../constants/consts.h"

void sortList(Event **listEvents, int listSize) {
	int i = 0, j = 0;
	Event *tempEvnt = malloc(1 * sizeof(Event));

	for (i = 0; i < listSize; ++i) {
		for (j = i + 1; j < listSize; ++j) {
			if ((*listEvents)[i].id > (*listEvents)[j].id) {
				*tempEvnt = (*listEvents)[i];
				(*listEvents)[i] = (*listEvents)[j];
				(*listEvents)[j] = *tempEvnt;
			}
		}
	}
	free(tempEvnt);
}

void removeEvent(Event **list, int *listSize, long date) {
	int flag = 0;
	int i, j;

	for (i = 0; i < *listSize - 1; i++) {
		if (date == (*list)[i].id) {
			for (j = i; j < *listSize - 1; j++) {
				flag++;
				(*list)[j] = (*list)[j + 1];
			}
		}
	}

	if (flag) {
		*listSize -= 1;
		*list = realloc(*list, *listSize * sizeof(Event));
		printf("Evento removido com sucesso.\n\n");
	} else {
		printf("Evento nao encontrado.\n\n");
	}
}

void systemPause(void) {
  printf("Pressione enter para continuar...\n");
  getchar();
}

void inputString(char *string, int max) {
  long unsigned int i = 0;

  fgets(string, max, stdin);

  do {
    if (string[i] == '\n') {
      string[i] = '\0';
      break;
    }
    i++;
  } while (i < strlen(string));

}

	#ifdef WIN32
		void clearScreen(void) {
			system("cls");
		}
	#else
		void clearScreen(void) {
			system("clear");
		}
	#endif
	
#endif