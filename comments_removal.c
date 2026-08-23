#include"header.h"
void headerfile_inclusion(FILE *fp2)
{
	char ch;
	int c=0;
	FILE *temp=fopen("temp.i","w");
	while((fgetc(fp2))!=EOF)
		c++;
	rewind(fp2);
	char s[c+1];
	while((fgets(s,c+1,fp2))!=NULL)
	{
		if((strncmp(s,"#include",8))==0)
		{
		int len = strlen(s);
		if (s[len - 1] == '\n')
		s[len -2] = '\0';
		int i = 8;
		while(s[i] == ' ' || s[i] == '\t')
		i++;
			if(s[i]=='<')
			{
			char path[50];
			strcpy(path,"/usr/include/");
			strcat(path, s + i+1);
			FILE *header=fopen(path,"r");
			while((ch=fgetc(header))!=EOF)
			fputc(ch,temp);
			fputc('\n',temp);
			fclose(header);
			}
			else if(s[i]=='"')
			{
			char path1[100];
			strcpy(path1,s+i+1);
			FILE *header=fopen(path1,"r");
			while((ch=fgetc(header))!=EOF)
			fputc(ch,temp);
			fclose(header);
			}
		}
		else
			fputs(s,temp);
	}
	fclose(temp);
	fclose(fp2);
	fp2=fopen("abc.i","w");
	temp=fopen("temp.i","r");
	while((ch=fgetc(temp))!=EOF)
		fputc(ch,fp2);
	fclose(temp);
	fclose(fp2);
	remove("temp.i");
}
