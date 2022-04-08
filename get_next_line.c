#include "get_next_line.h"

char *ft_getline(char *line)
{
    int length;
    int i;
    char *result;

    length = 0;

    if (!line || line[0] == '\0')
        return (NULL);

    while (line[length] && line[length] != '\n')
        length++;
    if (line[length] == '\n')
        length++;
    
    result = malloc(sizeof(*result) * length + 1);
    if(!result)
        return (NULL);
    i = -1;
    while (++i < length)
        result[i] = line[i];
    result[i] = '\0';
    return (result);
}

char *ft_computestash(char *stash, int fd)
{
    char buff[BUFF_SIZE + 1];
    int read_bytes;

    read_bytes = 1;
    while (read_bytes && !ft_strchr(stash, '\n'))
    {
        read_bytes = read(fd, buff, BUFF_SIZE);
        if (read_bytes == -1)
            return (NULL);
        buff[read_bytes] = '\0';
        stash = ft_strjoin(stash, buff);
    }
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    char *tmp;

    if (fd < 0 || BUFF_SIZE <= 0)
        return (NULL); 

    stash = ft_computestash(stash, fd);
    line = ft_getline(stash);
    if (ft_strchr(stash, '\n'))
    {
        tmp = stash;
        stash = ft_strdup(ft_strchr(stash, '\n') + 1);
        free(tmp);
    }      
    else 
    {
        free(stash);
        stash = NULL;
    }
    return line;
}
/*
int main(void)
{
    //int fd;
    int fd2;
    char *tmp;

    //fd = open("text1.txt", O_RDONLY);
    fd2 = open("texr2.txt", O_RDONLY);
    
        // tmp = get_next_line(fd);
        // printf ("%s", tmp);
        // printf("********************************************\n");
        // tmp = get_next_line(fd);
        // printf ("%s", tmp);
        // printf("********************************************\n");
        // tmp = get_next_line(fd);
        // printf ("%s", tmp);
        // printf("********************************************\n");
        // tmp = get_next_line(fd);
        // printf ("%s", tmp);
        tmp = get_next_line(fd2);
        printf("%s \n", tmp);
        tmp = get_next_line(fd2);
        printf("%s \n", tmp);
        // printf("\n");
        // printf("********************************************\n");
        // tmp = get_next_line(fd);
        // printf ("%s", tmp);
    

}
*/
