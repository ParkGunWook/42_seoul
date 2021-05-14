#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define READ_BUFFER 10

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static	void	ft_putnbr2_fd(int nb, int fd)
{
	int	remainder;

	remainder = nb % 10;
	nb /= 10;
	if (nb == 0)
	{
		ft_putchar_fd('0' + remainder, fd);
		return ;
	}
	ft_putnbr2_fd(nb, fd);
	ft_putchar_fd('0' + remainder, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n >= 0)
		ft_putnbr2_fd(n, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr2_fd(-n, fd);
	}
}

int main()
{
	int fd;
	if (!(fd = open("./alpha", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	char c[READ_BUFFER];
	int	num = 0;
	int k = 0;
	//printf("file id : %d\n", fd);
	while ((k = read(fd, &c, READ_BUFFER)))
	{
		write(1, c, READ_BUFFER);
		write(1, "read : ", 7);
		ft_putnbr_fd(k, 1);
		write(1, "\n", 1);
		//printf("read : %d\n", k);
		num++;
	}
	//printf("num : %d\n", num);
	k = read(fd, &c, READ_BUFFER);
	printf("all read : %d\n", k);
	return (0);
}
