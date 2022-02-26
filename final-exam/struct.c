// create a program that reads a binary file with a list of "Aluno" type
// and create another binary file with "matricula" and "notas[5]" average
// corresponding to each student

#include <stdio.h>
#include <stdlib.h>

// struct given by teacher
typedef struct {
	int matricula;
	char nome[100];
	struct {int dia, mes, ano;} data_nascimento;
	float notas[5];
} Aluno;

void loadFile(Aluno **list, int *listSize) {
	Aluno student;
	int read;
	FILE *fptr = fopen("studs.bin", "a+b");
	if(fptr == NULL) {
		printf("Erro ao abrir arquivo\n");
		exit(-1);
	}

	while (!feof(fptr)) {
		read = fread(&student, sizeof(Aluno), 1, fptr);
		if (!feof(fptr)) {
				*listSize += 1;
				*list = realloc(*list, *listSize * sizeof(Aluno) + 1);
				*list[*listSize - 1] = student;
		}
	}

	fclose(fptr);
}

float *studsAvg(Aluno **list, int *listSize) {
	float *listaMedia;
	float avg;
	listaMedia = malloc(*listSize * sizeof(float));
	for (int i = 0; i < *listSize; i++) {
		avg = 0.0;
		for (int j = 0; j < 5; j++) {
			avg += (*list)[i].notas[j]; 
		}
		avg /= 5;
		listaMedia[i] = avg;
	}
	return listaMedia;
}

void saveFile(Aluno **list, int *listSize, float **avgGrades) {
	FILE *fptr;
	fptr = fopen("grades.bin", "wb");
	if(fptr == NULL) {
		printf("Erro ao criar o arquivo\n");
		exit(-1);
	}

	for (int i = 0; i < *listSize; i++) {
		fwrite(&(*list)[i].matricula, sizeof(int), 1, fptr);
		fwrite(&(*avgGrades)[i], sizeof(float), 1, fptr);
	}
	fclose(fptr);	

}

int main(void) {
	Aluno *list = NULL;
	float *averageStudents;
	int listSize = 0;
	loadFile(&list, &listSize);
	
	averageStudents = malloc(listSize * sizeof(float));
	averageStudents = studsAvg(&list, &listSize);

	saveFile(&list, &listSize, &averageStudents);

	return 0;
}