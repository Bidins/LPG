#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../constants/consts.h"
#include "createEvent.h"
#include "support.h"
#include "output.h"

void option1(Event **list, int *listSize) {
	clearScreen();
	Event newEvnt;

	newEvnt = createEvent();
	addEventToList(newEvnt, &(*list), &(*listSize));
	sortList(&(*list), *listSize);

	systemPause();
	clearScreen();
}

void option2(Event **list, int *listSize) {
	clearScreen();
	if (!(*listSize)) {
		printf("Nao ha eventos para mostrar. Lista vazia.\n");
		systemPause();
		clearScreen();
		return;
	}
	displayMultipleEvents(*list, *listSize, 0);
	systemPause();
	clearScreen();
}

void option3(Event **list, int *listSize) {
	clearScreen();
	if (!(*listSize)) {
		printf("Nao ha eventos para buscar. Lista vazia.\n");
		systemPause();
		clearScreen();
		return;
	}
	char trash;
	int valid;
	int day, month, year;

	printf("Insira a data que deseja buscar eventos\n");
	do {
		valid = 1;
		printf("\n------------\n");
		printf("    Data\n");
		printf("------------\n");

    printf("Dia: ");
    scanf("%d", &day);
    printf("Mes: ");
    scanf("%d", &month);
    printf("Ano: ");
    scanf("%d", &year);

		if (month < 1 || month > 12) {
			printf("Mes invalido.\n");
			valid = 0;
		}
		if (day < 1 || day > 31) {
			printf("Dia invalido.\n");
			valid = 0;
		}
		if (year < 1000 || year > 9999) {
			printf("Ano invalido.\n");
			valid = 0;
		}
	} while (!valid);

	scanf("%c", &trash);
	long date;
	date = (year * 365 * 24);
	date += (month - 1) * 30 * 24;
	date += ((day - 1) * 24);

	displayEventByDate(*list, date, *listSize);
	systemPause();
	clearScreen();
}

void option4(Event **list, int *listSize) {
	clearScreen();
	if (!(*listSize)) {
		printf("Nao ha eventos para buscar. Lista vazia.\n");
		systemPause();
		clearScreen();
		return;
	}
	int day, month, year;
	int valid;
	char trash;

	printf("Deseja ver os eventos a partir de qual data: \n");

	do {
		valid = 1;
		printf("\n------------\n");
		printf("    Data\n");
		printf("------------\n");

		printf("Dia: ");
		scanf("%d", &day);
		printf("Mes: ");
		scanf("%d", &month);
		printf("Ano: ");
		scanf("%d", &year);

		if (month < 1 || month > 12) {
			printf("Mes invalido.\n");
			valid = 0;
		}
		if (day < 1 || day > 31) {
			printf("Dia invalido.\n");
			valid = 0;
		}
		if (year < 1000 || year > 9999) {
			printf("Ano invalido.\n");
			valid = 0;
		}
	} while (!valid);

	scanf("%c", &trash);

	long date;
	date = (year * 365 * 24);
	date += (month - 1) * 30 * 24;
	date += ((day - 1) * 24);

	printf("Os 5 proximos eventos sao: \n");
	displaySomeDate(*list, date, *listSize);
	systemPause();
	clearScreen();
}

void option5(Event **list, int *listSize) {
	clearScreen();
	if (!(*listSize)) {
		printf("Nao ha eventos para remover. Lista vazia.\n");
		systemPause();
		clearScreen();
		return;
	}
	int day, month, year;
	int hour, minute;
	int valid;
	char trash;

	printf("Remover um evento\n");

	do {
		valid = 1;
		printf("\n------------\n");
		printf("    Data\n");
		printf("------------\n");

    printf("Dia: ");
    scanf("%d", &day);
    printf("Mes: ");
    scanf("%d", &month);
    printf("Ano: ");
    scanf("%d", &year);

		if (month < 1 || month > 12) {
			printf("Mes invalido.\n");
			valid = 0;
		}
		if (day < 1 || day > 31) {
			printf("Dia invalido.\n");
			valid = 0;
		}
		if (year < 1000 || year > 9999) {
			printf("Ano invalido.\n");
			valid = 0;
		}
	} while (!valid);

	do {
		valid = 1;
		printf("\n-------------------------\n");
		printf("    Horario de Inicio\n");
		printf("-------------------------\n");

		printf("Hora: ");
		scanf("%d", &hour);
		printf("Minutos: ");
		scanf("%d", &minute);

		if (hour < 0 || hour > 24) {
			printf("Por favor, insira uma hora valida.\n");
			valid = 0;
		}
		if (minute < 0 || minute > 59) {
			printf("minuto invalido.\n");
			valid = 0;
		}
	} while (!valid);

	scanf("%c", &trash);

	long id;
	id = (year * 365 * 24);
	id += (month - 1) * 30 * 24;
	id += ((day - 1) * 24);
	id += (hour);
	id *= 60;
	id += minute;

	removeEvent(&(*list), &(*listSize), id);
	systemPause();
	clearScreen();
}

void option6(Event **list, int *listSize) {
	clearScreen();
	FILE *fptr;

	fptr = fopen("agenda.bin", "wb");
	if(fptr == NULL) {
		printf("Erro ao criar o arquivo\n");
		exit(-1);
	}

	fwrite(*list, *listSize * sizeof(Event), 1, fptr);
	fclose(fptr);
	
	printf("Encerrando programa. Ate a proxima.\n");
	systemPause();
	clearScreen();
}

#endif