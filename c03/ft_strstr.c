        #include <stdio.h>
        #include <string.h>
        char *ft_strstr(char *str, char *to_find)
        {
            int i;
            int j;

            i   = 0;
            if (to_find[0] == '\0') //this means that IF the string is empty....
            {
                return(str);
            }
            
            while(str[i]) //looping thru first string
            {
                j = 0;
                while(to_find[j] != '\0' && (str[i+j] == to_find[j])) //looping thru second string and matching characters
                {
                    j++;
                }
                if (to_find[j] == '\0')
                {
                    return(&str[i]);
                }
                i++;
            }
            return(0); 
        }

        int main(void)
        {
            char    str1[] = "abcdef";
            char    find1[] = "";

            printf("ft_strstr: %s\n", ft_strstr(str1, find1));
        }