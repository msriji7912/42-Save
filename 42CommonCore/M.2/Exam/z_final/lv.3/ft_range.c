#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     *ft_range(int start, int end)
{
    int i;
    int *tab = NULL;

    i = 0;
    if (start == end)
        return (0);
    else if (end >= start)
    {
        tab = malloc (sizeof(int) * (end - start) + 1);
        if (!tab)
            return (NULL);
        while (start <= end)
        {
            tab[i] = start;
            start++;
            i++;
        }
    }
    else if (end <= start)
    {
        tab = malloc (sizeof(int) * (start - end) + 1);
        if (!tab)
            return (NULL);
        while (start >= end)
        {
            tab[i] = start;
            start--;
            i++;
        }
    }
    return (tab);
}

int main(void)
{
    int start = 15;
    int end = -7;
    int i;
    int *tab = ft_range(start, end);
    int size;

    i = 0;
    if (end >= start)
        size = end - start;
    else if (start >= end)
        size = start - end;
    else
        return (0);
    while (i <= size)
    {
        printf("%d, ", tab[i]);
        i++;
    }
    return (0);
}