#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	puthex(unsigned char tmp)
{
	char	*hex = "0123456789abcdef";

	ft_putchar(hex[tmp / 16]);
	ft_putchar(hex[tmp % 16]);
}

void	printchar(unsigned char tmp)
{
	if (tmp > 31 && tmp < 127)
		ft_putchar(tmp);
	else
		ft_putchar('.');
}

void	printhex(unsigned char *tmp, size_t cur, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (i && i % 2 == 0)
			ft_putchar(' ');
		if (cur * 16 + i < size)
			puthex(tmp[i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		++i;
	}
	ft_putchar(' ');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			cur;

	cur = 0;
	tmp = (unsigned char*)addr;
	while (cur * 16 < size)
	{
		i = 0;
		if (cur * 16 + i < size)
			printhex(tmp, cur, size);
		while (i < 16)
		{
			if (cur * 16 + i < size)
				printchar(tmp[i]);
			++i;
		}
		ft_putchar('\n');
		cur++;
		tmp += 16;
	}
}
