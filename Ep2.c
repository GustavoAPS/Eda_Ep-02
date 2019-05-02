#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int ilbp(int a ,int b);

int main () {
	int a,b;
	printf("entre com a linha: ");
	scanf("%d", &a);
	printf("entre com a coluna: ");
	scanf("%d", &b);
	printf("Numero na posição : %d \n", ilbp(a,b));

	return 0;
}

int ilbp(int a ,int b) {
	FILE *fp; // ponteiro para o arquivo

	char file_name[] = "grass_01.txt"; //caminho do arquivo

	fp = fopen(file_name,"r");

	int matrix[1025][1025];//linhas/colunas
	char line[2125];
	int l = 0;
	int c = 0;
	char ch;
	char pixel_concatenation[4];
	int aux = 0; 
	int number=0;

	if ( fp != NULL ) {
		while ( fgets ( line, sizeof line, fp ) != NULL ) {/* read a line */	
			for (int i = 0 ; i < strlen(line) ; i++) {
				if(line[i] == ';' || line[i] < 48 || line[i] > 57 ) {			
					pixel_concatenation[aux] = '\0';//garante o funcionamento de atoi
					number = atoi(pixel_concatenation);
					matrix[l][c]=number;

					if (c == 1024) {
						c = 0;
						l++;
					} else {
						c++;
					}

					pixel_concatenation[0] = '.';
					pixel_concatenation[1] = '.';
					pixel_concatenation[2] = '.';
					aux = 0;
				} else {
					pixel_concatenation[aux] = line[i];
					aux++;
				}

			}
//			printf("%c", line[i]);

		//printf("\n");
		//printf("%s \n", line);
			//fputs ( line, stdout ); /* write the line */
		}
	}
	/*
	while ( (ch = fgetc(fp))  != EOF ){
		if(ch == ';') {
			pixel_concatenation[aux] = '\0';
			number = atoi(pixel_concatenation);

			if (c == 1024) {
				c = 0;
				l++;
			}

			matrix[l][c]=number;
			c++;
			pixel_concatenation[0] = '.';
			pixel_concatenation[1] = '.';
			pixel_concatenation[2] = '.';
			aux = 0;
		} else {
			pixel_concatenation[aux] = ch; 
			aux++;
		}
	}*/
	fclose(fp);

	return matrix[a][b];
}
