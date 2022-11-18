#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int	open_file(char *filename)
{
	int fd = open(filename, O_RDONLY);
	
	if (fd < 0)
		return -1;
	
	return fd;
}

int	decrypt(int c, int itr)
{
	return c - itr;
}

void	read_file(int fd)
{	
	unsigned char buff = 0;
	char string[1024];
	int itr = 0;

	while (read(fd, &buff, 1) > 0)
	{ 
		string[itr] = decrypt(buff, itr);
		itr++;
	}
	string[itr-1] = '\0';
	printf("%s\n", string);
	return ;
}


int	main(int ac, char **av)
{
	int fd;

	if (ac != 2){
		printf("Enter one argument");
		return 1;
	}
	fd = open_file(av[1]);

	read_file(fd);
	
	close(fd);
	return 0;
}
