#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *file1, *file2, *filegabung;
	char ch, namafile1[20], namafile2[20], namafile3[20];

	printf("\nMenggabung 2 file di File Baru.\n");

	printf("\nMasukkan nama file pertama:");
	scanf("%s",namafile1);
	printf("Masukkan nama file kedua:");
	scanf("%s",namafile2);
	printf("Masukkan nama file baru:");
	scanf("%s",namafile3);
	file1=fopen(namafile1, "r");
	file2=fopen(namafile2, "r");
	if(file1==NULL || file2==NULL)
	{
//		perror("Error Message");
		printf("File tidak ada.\n");
		exit(EXIT_FAILURE);
	}
	filegabung=fopen(namafile3, "w");
	if(filegabung==NULL)
	{
//		perror("Error Message");
		printf("File tidak ada.\n");
		exit(EXIT_FAILURE);
	}
	while((ch=fgetc(file1))!=EOF)
	{
		fputc(ch, filegabung);
	}
	while((ch=fgetc(file2))!=EOF)
	{
		fputc(ch, filegabung);
	}
	printf("File berhasil digabung menjadi %s.\n", namafile3);
	fclose(file1);
	fclose(file2);
	fclose(filegabung);
}
