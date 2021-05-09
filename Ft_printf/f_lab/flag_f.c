/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpark <gpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:19:56 by gpark             #+#    #+#             */
/*   Updated: 2021/05/09 17:05:59 by gpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include "./libft/libft.h"

void ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

int flag_f(double d)
{
	int	temp;
	printf("%f\n", d);
	while (d != 0)
	{
		temp = d * 10;
		//printf("temp : %d\n", temp);
		ft_putchar(1, '0' + temp);
		ft_putchar_fd(1, '0' + temp);
		d = d * 10 - temp;
	}
	write(1, "\n", 1);
	return (0);
}

void ft_revbits(unsigned char *bits, size_t size)
{
	size_t			left;
	size_t			right;
	unsigned char	temp;

	left = 0;
	right = size - 1;
	while(left < right)
	{
		temp = bits[left];
		bits[left] = bits[right];
		bits[right] = temp;
		left++;
		right--;
	}
}

void print_bits(double d)
{
	unsigned char	bits[8 + 1];
	int		i;
	int		k;

	k = d;
	i = 0;
	ft_memcpy(bits, &d, 8);
	ft_revbits(bits, 8);
	bits[8] = 0;
	printf("bits : ");
	for(int i = 0; i < 8; i++)
	{
		printf("%x ", *(bits + i));
	}
	printf("\n");
}

int	main(void)
{
	//double d = 1;
	int i = 0;
	//print_bits(0.9);
	for(int i = 0; i< 10;i++){
		print_bits(0.1 * i);
	}
	/*while(i < 32)
	{
		print_bits(d);
		printf("%.32f\n", d);
		d /= 2;
		i++;
	}*/
	i = 0;
	printf(NULL);
	/*while(i < 32)
	{
		d *= 2;
		//printf("%.32f\n", d);
		i++;
	}*/
}
