#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int a=count_letters(text),b = count_words(text),c = count_sentences(text);

    double L,S;
    L = a/(double)b*100;
    S = c/(double)b*100;

    double index = 0.0588 * L- 0.296*S-15.8;
    int X=(int)round(index);

    if(index<1){printf("Before Grade 1\n");}
    else if(index>0 && index<16)
    {
        printf("Grade %d\n",X);
    }
    else {printf("Grade 16+\n");}
}

int count_letters(string text)
{
    int num = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            num++;
        }
    }
    return num;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{
    int n=0;
    for (int i=0;i<strlen(text);i++)
    {
        if(text[i] =='!'|| text[i] == '.'|| text[i] =='?')
        {
            n++;
        }
    }
    return n;
}
