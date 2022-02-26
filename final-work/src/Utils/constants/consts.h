#ifndef _CONSTS_H
#define _CONSTS_H

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	int hour;
	int minute;
} Time;

typedef struct {
	Date date;
	Time begin;
	Time end;
	char place[50];
	char description[100];
	long id;
} Event;

#endif