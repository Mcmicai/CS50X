#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
        int s1,s2;
        do
        {
            s1 = get_int("Start size: ");
        }
        while(s1<9);

        do
        {
            s2 = get_int("End size: ");
        }
        while(s2<=s1);

        int num = s1;
        int n = 0;
        while(num<s2)
        {
            num = num+(num/3)-(num/4);
            n++;
        }
        printf("Years: %d\n",n);

}
