#include<stdlib.h>
#include<stdio.h>

int main(){

FILE *fp; // ponteiro para o arquivo

char file_name[] = "grass_01.txt"; //caminho do arquivo

fp = fopen(file_name,"r");

int matrix[1025][1025];//linhas/colunas
int l = 0;
int c = 0;
char ch;
char pixel_concatenation[4];
int aux = 0; 
int number=0;

while ( (ch = fgetc(fp))  != EOF ){
	if(ch == ';' )
	{
	pixel_concatenation[aux] = '\0';
	number = atoi(pixel_concatenation);
	if (c == 1024){
	c = 0;
	l++;
	}
	matrix[l][c]=number;
	c++;
	//printf("%d\n",number);
	pixel_concatenation[0] = '.';
	pixel_concatenation[1] = '.';
	pixel_concatenation[2] = '.';
	aux = 0;
	}
	else{
	pixel_concatenation[aux] = ch; 
	aux++;
	}
}
fclose(fp);

for (int a = 0; a < 1025; a++){
	for (int b = 0; b < 1025; b++){
	printf("%d ", matrix[a][b]);
	}
printf ("\n");
}

return 0;
}
