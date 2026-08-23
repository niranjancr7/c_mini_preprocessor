#include"header.h"
void comments_removal(FILE *, FILE *);
void headerfile_inclusion(FILE *);
int macro_collection(FILE *,char ***,char ***);
void macro_replacement(FILE *,char **names,char **values,int);
int main(int argc, char **argv)
{
	if(argc!=2)
	{
	printf("Usage: ./my_preprocessor abc.c \n");
	return 1;
	}
	FILE *fp1=fopen(argv[1],"r");
	if(fp1==0)
	{
		printf("File not present \n");
		return 1;
	}
	FILE *fp2=fopen("abc.i","w");
	comments_removal(fp1,fp2);
	fclose(fp2);
	fp2=fopen("abc.i","r");
	char **macro_n,**macro_v;
	int macro_c=0;
	macro_c=macro_collection(fp2,&macro_n,&macro_v);
	rewind(fp2);
	headerfile_inclusion(fp2);
	fp2=fopen("abc.i","r");
	macro_replacement(fp2,macro_n,macro_v,macro_c);
	for(int i=0;i<macro_c;i++)
	{
		free(macro_n[i]);
		free(macro_v[i]);
	}
	free(macro_n);
	free(macro_v);
	fclose(fp1);
	return 0;
}

