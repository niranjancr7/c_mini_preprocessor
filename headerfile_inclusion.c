#include "header.h"
void comments_removal(FILE *fp1, FILE *fp2)
{
    char ch,next;
    while((ch = fgetc(fp1)) != EOF)
    {
        if(ch == '/')
        {
            next = fgetc(fp1);
            if(next == '/')
            {
                while((ch = fgetc(fp1)) != EOF && ch != '\n');
                if(ch == '\n')
                fputc(ch, fp2);
            }
            else if(next == '*')
            {
                while((ch = fgetc(fp1)) != EOF)
                {
                    if(ch == '*')
                    {
                        next = fgetc(fp1);

                        if(next == '/')
                          break;
                        if(next != EOF)
                            fseek(fp1, -1, SEEK_CUR);
                    }
                }
            }
            else
            {
                fputc('/', fp2);

                if(next != EOF)
                    fseek(fp1, -1, SEEK_CUR);
            }
        }
        else
        {
            fputc(ch, fp2);
        }
    }
}

