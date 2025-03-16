#include <stdio.h>

char **ft_split(char *str)
{
    static char buffer[1000][1000];
    static char *res[1000];
    int count_word = 0;

    while(*str)
    {
        while(*str == ' ' || *str == '\t' || *str == '\n')
            str++;

        int i = 0;
        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
        {
            buffer[count_word][i] = *str;
            i++;
            str++;
        }
        buffer[count_word][i] = '\0';
        res[count_word] = buffer[count_word];
        count_word++;
    }
    res[count_word] = '\0';
    return (res);
}

int main()
{
    char *str = "aspokaos kasodka askodkasod   askdoaskd";
    char **res;

    res = ft_split(str);
    while (*res)
    {
        printf("%s\n", *res);１１１１
        res++;
    }
}