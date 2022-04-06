#include "get_next_line.h"

void ft_cut(char *str)
{
    int i;

    i = 0;
    if (!str)
        return;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    while (str[i])
    {
        str[i] = '\0';
        i++;
    }
}

char *get_next_line(int fd)
{
    static char *stash = "";
    char buff[BUFF_SIZE];
    char *line;
    int read_bytes;

    //line = ft_strdup(stash);
    line = stash;

    //printf("Value of line and stash at the beginning : %s | %s\n", line, stash);

    if (!line || fd < 0)
        return (NULL); 
    if (ft_strchr(line, '\n'))
    {
        stash = ft_strdup(ft_strchr(line, '\n')+1);
        ft_cut(line);
        return line;
    }
    read_bytes = read(fd, buff, BUFF_SIZE);
    if (!read_bytes || read_bytes == -1)
        return (NULL);
    while (read_bytes)
    {
        buff[read_bytes] = '\0';
        line = ft_strjoin(line, buff);
        //printf("Value of line after join : %s\n", line);
        if (ft_strchr(line, '\n'))
        {
            stash = ft_strdup(ft_strchr(line, '\n')+1);
            ft_cut(line);
            return line;
        }           
        read_bytes = read(fd, buff, BUFF_SIZE);
    }
    return line;
}
/*
int main(void)
{
    int fd;
    char *tmp;

    if ((fd = open("text1.txt", O_RDONLY)) != -1)
    {
        tmp = get_next_line(fd);
        printf ("%s", tmp);
        printf("********************************************\n");
         tmp = get_next_line(fd);
         printf ("%s", tmp);
        printf("********************************************\n");
        tmp = get_next_line(fd);
        printf ("%s", tmp);
        printf("********************************************\n");
        tmp = get_next_line(fd);
        printf ("%s", tmp);
        printf("\n");
    }
    else
    {
        printf("%s \n", "File failed to open");
    }
}
*/