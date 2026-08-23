#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void comments_removal(FILE *, FILE *);
void headerfile_inclusion(FILE *);
int macro_collection(FILE *,char ***names,char ***values);
void macro_replacement(FILE *,char **names,char **values,int);
