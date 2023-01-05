#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define LINE 256
#define WORD 30

/**
 * check if str1 is a substring of str2
*/
int substring( char * str1, char * str2)
{
    if(strstr(str2, str1) != NULL){
        return 1;
    }
    return 0;
}

/**
 * check if s is similar to t (s is longer by n)
 * 
*/
int similar (char *s, char *t, int n)
{
    if(n == 0) // if they are have 0 diffrence
    {
        return (strcmp(s, t) == 0); //check if they are equals
    }

    int lens = strlen(s);
    int lent = strlen(t);

    if(lens != lent + n) //check it hey have the same length
    {
        return 0;
    }

    char *ps = s;// make a copy
    char *pt = t;
    int count = 0; //check if the word s include all the the letters from t 
    for (size_t i = 0; i < lens; i++)
    {
        if(*pt == *ps)
        {
            count++;
            pt++;
        }
        ps++;
    }

    if(count == lent)
    {
        return 1;
    }
    return 0;
}

int getLine(char *s)
{
    int count = 0;
    char *c = s;
    char ch = '0'; 
    ch = getchar();
    while (ch != '\n' && count < LINE && ch != EOF)
    {
        c = strncat(c , &ch , 1);
        ch = getchar();
        count++;
    }
    s = c;
    return count;
}

int getWord(char *w)
{
    int count = 0;
    char *c = w;
    char ch = '0'; 
    ch = getchar();
    while (ch != '\n' && ch != '\t' && ch != ' ' && count < WORD  && ch != EOF)
    {
        c = strncat(c , &ch , 1);
        ch = getchar();
        count++;
    }
    w = c;
    return count;
}

void print_lines(char * str) 
{
    char line[LINE];
    for(int i = 0; i < LINE; i++)
    {
        memset(line , '\0' , LINE);
        if(getLine(line) == 0)
        {
            break;
        }
        if(substring(str , line) == 1)
        {
            printf("%s\n", line);
        }
    }
}

void print_similar_words(char * str)
{
    char word[WORD];
    for(int i = 0; i<LINE; i++)
    {
        memset(word , '\0' , WORD);
        if(getWord(word) == 0)
        {
            break;
        }
        int sim = 1;
        if(strlen(word) == strlen(str))
        {
            sim = 0;
        }
        if(similar(word , str , sim) == 1)
        {
            printf("%s\n" ,word);
        }
    }
}

int main()
{
    char word[WORD];
    getWord(word);
    char ch = '0';
    ch = getchar();
    if(ch == 'a')
    {
        char *c = NULL;
        scanf("%s" , c);
        print_lines(word);
    }
    else if(ch == 'b')
    {
        char *c = NULL;
        scanf("%s" , c);
        print_similar_words(word);
    }

    
    return 0;
}
