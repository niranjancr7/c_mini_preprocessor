#include"header.h"
int macro_collection(FILE *fp2, char ***names,char ***values)
{
	int c1=0;
	while((fgetc(fp2))!=EOF)
		c1++;
	rewind(fp2);
	char *s=malloc(c1+1);
	int macro_count=0;
	while((fgets(s,c1+1,fp2))!=NULL)
	{
		if((strncmp(s,"#define",7))==0)
			macro_count++;
	}
	*names=malloc(macro_count *sizeof(char *));
	*values=malloc(macro_count *sizeof(char *));
	rewind(fp2);
	int i=0;
	while((fgets(s,c1+1,fp2))!=NULL)
	{
		if((strncmp(s,"#define",7))==0)
		{
			char *p=s+7;
			while(*p == ' ' || *p == '\t')
				p++;
			char *start=p;
			while(*p!=' ' && *p!='\t' && *p!='\n' && *p!='\0')
				p++;
			int name_len=p-start;
			(*names)[i]=malloc(name_len+1);
			strncpy((*names)[i],start,name_len);
			(*names)[i][name_len]='\0';
			while(*p==' ' || *p == 't')
				p++;
			start=p;
			while(*p!='\n' && *p!='\0')
				p++;
			int value_len=p-start;
			(*values)[i]=malloc(value_len+1);
			strncpy((*values)[i],start,value_len);
			(*values)[i][value_len]='\0';
			i++;
		}
	}
	free(s);
	return macro_count;
}

void macro_replacement(FILE *fp2,char **names,char **values,int c)
{
	FILE *temp1=fopen("temp1.i","w");
	int c1=0;
	while(fgetc(fp2)!=EOF)
		c1++;
	rewind(fp2);
	char *line=malloc(c1+1);
	char ch2;
	int start=0;
	while(fgets(line,c1+1,fp2)!=NULL)
	{
		if(start==0)
		{
			if(strncmp(line,"#define",7)==0)
			{
				char *p=line+7;
				while(*p==' ' || *p=='\t')
					p++;
				int k;
				for(k=0;k<c;k++)
				{
					if(strncmp(p,names[k],strlen(names[k]))==0 &&
					   (p[strlen(names[k])]==' ' || p[strlen(names[k])]=='\t'))
					{
						break;
					}
				}
				if(k<c)
					continue;
			}
			fputs(line,temp1);
			if(strstr(line,"int main")!=NULL)
				start=1;
			continue;
		}
		int i=0,j;
		char word[100];
		for(int pos=0;line[pos]!='\0';pos++)
		{
			ch2=line[pos];
			if((ch2>='A' && ch2<='Z') ||
			   (ch2>='a' && ch2<='z') ||
			   (ch2>='0' && ch2<='9') ||
			   ch2=='_')
			{
				word[i++]=ch2;
				if(line[pos+1]=='\0' ||
				   !((line[pos+1]>='A' && line[pos+1]<='Z') ||
				     (line[pos+1]>='a' && line[pos+1]<='z') ||
				     (line[pos+1]>='0' && line[pos+1]<='9') ||
				     line[pos+1]=='_'))
				{
					word[i]='\0';
					for(j=0;j<c;j++)
					{
						if(strcmp(word,names[j])==0)
						{
							fputs(values[j],temp1);
							break;
						}
					}
					if(j==c)
						fputs(word,temp1);
					i=0;
				}
			}
			else
			{
				fputc(ch2,temp1);
				i=0;
			}
		}
	}
	free(line);
	fclose(temp1);
	fclose(fp2);
	fp2=fopen("abc.i","w");
	temp1=fopen("temp1.i","r");
	char ch3;
	while((ch3=fgetc(temp1))!=EOF)
		fputc(ch3,fp2);
	fclose(temp1);
	fclose(fp2);
	remove("temp1.i");
}


