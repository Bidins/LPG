#ifndef _CREATE_EVENT_H
#define _CREATE_EVENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../constants/consts.h"
#include "support.h"
#include "output.h"

Event createEvent() {
	char trash;
	Event newEvent;

	int day, month, year, hour, minute;
	int valid = 1, timeValidation = 1;

	clearScreen();
	printf("Bem vindo(a) a criacao de eventos!\nPasse as seguintes informacoes necessarias para criacao do mesmo.\n");

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

	newEvent.date.day = day;
	newEvent.date.month = month;
	newEvent.date.year = year;

	do {
		timeValidation = 1;
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
				printf("Hora invalida.\n");
				valid = 0;
			}
			if (minute < 0 || minute > 59) {
				printf("Minuto invalido.\n");
				valid = 0;
			}
		} while (!valid);

		newEvent.begin.hour = hour;
		newEvent.begin.minute = minute;

		do {
			valid = 1;

			printf("\n--------------------------\n");
			printf("    Horario de Termino\n");
			printf("--------------------------\n");

			printf("Hora: ");
			scanf("%d", &hour);
			printf("Minutos: ");
			scanf("%d", &minute);

			if (hour < 0 || hour > 24) {
				printf("Hora invalida.\n");
				valid = 0;
			}
			if (minute < 0 || minute > 59) {
				printf("Minuto invalido.\n");
				valid = 0;
			}
		} while (!valid);

		newEvent.end.hour = hour;
		newEvent.end.minute = minute;

		if (((100 * newEvent.end.hour) + newEvent.end.minute) <= ((100 * newEvent.begin.hour) + newEvent.begin.minute)) {
			printf("Horario invalido, horario de inicio nao pode ser maior ou igual ao horario de fim!\n");
			timeValidation = 0;
		}
	} while(!timeValidation);
	scanf("%c", &trash);


	printf("\nInsira o local onde ocorrera o evento:\n");
	inputString(newEvent.place, 50);

	printf("\nPor fim, a descricao do evento:\n");
	inputString(newEvent.description, 50);

	long id;
	id = (newEvent.date.year * 365 * 24);
	id += (newEvent.date.month - 1) * 30 * 24;
	id += ((newEvent.date.day - 1) * 24);
	id += (newEvent.begin.hour);
	id *= 60;
	id += newEvent.begin.minute;

	newEvent.id = id;

	return newEvent;
}

void addEventToList(Event newEvent, Event **list, int *listSize) {
	int allowed = 1;
	for (int i = 0; i < *listSize; i++) {
		if (newEvent.id == (*list)[i].id) {
			allowed = 0;
		}
	}
	if (allowed) {
		*listSize += 1;
		*list = realloc(*list, *listSize * (sizeof(Event)) + 1);
		(*list)[*listSize-1] = newEvent;
	} else {
		printf("Evento ja criado, impossivel criar outro com o mesmo dia e horario.\n");
	}
}

#endif