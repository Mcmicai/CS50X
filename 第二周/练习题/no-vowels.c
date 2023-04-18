// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
string replace(string str);

int main(int argc, string argv[])
{
       if (argc == 2)
    {
        printf("%s\n",replace(argv[1]));
    }
    else
    {
        printf("Error!\n");
        return 1;
    }

}


string replace(string str)
{
     for(int i=0; i < strlen(str); i++)
     {
        if(str[i] == 'a')
        {
            str[i] = '6';
        }
        else if(str[i] == 'e')
        {
            str[i] = '3';
        }
        else if(str[i] == 'i')
        {
            str[i] = '1';
        }
        else if(str[i] == 'o')
        {
            str[i] = '0';
        }
        else if(str[i] == 'u')
        {
            str[i] = 'u';
        }
     }
     return str;
}
