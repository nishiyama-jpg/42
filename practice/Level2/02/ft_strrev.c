char    *ft_strrev(char *str)
{
    int i;
    int last;
    int temp;

    i = 0;

    while(str[i])
    {
        i++;
    }
    last = i - 1;
    i = 0;

    while(last > i)
    {
        temp = str[i]; // temp container temporarily stores str[i]
        str[i] = str[last]; // str[i] is currently overwritten with str[last]
        str[last] = temp; // str[last] will now store temp(previosuly str[i])

        i++; // go to next index in memory
        last--; //next number to store
    }
    return (str);
}