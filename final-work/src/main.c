#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils/constants/consts.h"
#include "Utils/helpers/support.h"
#include "Utils/helpers/output.h"
#include "Utils/helpers/createEvent.h"
#include "Utils/helpers/options.h"

void pushFromFile(char *path, Event **list, int *listSize) {
	Event evnt;

	FILE *fptr = fopen(path, "a+b");
	if(fptr == NULL) {
		printf("Erro ao abrir arquivo\n");
	}

	while (!feof(fptr)) {
		fread(&evnt, sizeof(evnt), 1, fptr);
		if (!feof(fptr)) {
			addEventToList(evnt, &(*list), &(*listSize));
		}
	}
	sortList(&(*list), *listSize);

	fclose(fptr);
}

int main(void) {
	int listSize = 0;
	Event *list = NULL;
	int option = 0;
	char trash;

	// import list from file if theres any
	pushFromFile("agenda.bin", &list, &listSize);

	do {
		printf("1. Cadastrar evento\n");
		printf("2. Exibir todos os eventos cadastrados\n");
		printf("3. Exibir eventos de uma data\n");
		printf("4. Exibir 5 proximos eventos\n");
		printf("5. Remover evento\n");
		printf("6. Salvar e encerrar programa\n");
		printf("\n");
		printf("Digite sua escolha: ");
		scanf("%d", &option);
		scanf("%c", &trash);

		switch (option) {
			case 1:
				option1(&list, &listSize);
			break;

			case 2:
				option2(&list, &listSize);
			break;

			case 3:
				option3(&list, &listSize);
			break;

			case 4:
				option4(&list, &listSize);
			break;

			case 5:
				option5(&list, &listSize);
			break;

			case 6:
				option6(&list, &listSize);
			break;
			default:
				printf("Opcao invalida!\n");
				systemPause();
				clearScreen();
			break;
		}
	} while (option != 6);

	return 0;
}
