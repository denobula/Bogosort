#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

/* pseudo random only on unix
int ft_rnd(int max)
{
	int	*prnd;
	int ret;

	ret = 0;
	prnd = (int*)malloc(sizeof(int));
	if (*prnd < 0)
		*prnd *= -1;
	ret = (int)prnd % max;
	free(prnd);
	return(ret);
}*/

int		ft_strlen(char* str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		ft_check_list(int* list, int len, int rnd)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (list[i] == rnd)
			return (0);
		i++;
	}
	return (1);
}

void	ft_clear(int* tab, int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		tab[i] = -1;
		i++;
	}
}

char	*ft_new_universe(char* src, int len)
{
	int				i;
	unsigned int	rnd;
	int				*tab;
	char			*copy;

	if ((copy = (char*)malloc(sizeof(char) * len+1)) == NULL)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * len);
	ft_clear(tab, len);
	i = 0;
	rnd = 0;
	while (i < len)
	{
		while (1)
		{
			rnd = rand() % len;
			if (ft_check_list(tab, len, rnd))
				break;
		}
		tab[i] = rnd;
		copy[rnd] = src[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

int		ft_check_one_dimensional_reality(char* src)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(src);
	if (len == 0)
		return (1);
	while (i < len - 1)
	{
		if (src[i] > src[i + 1])
			return 1;
		i++;
	}
	return (0);
}

void	main(void)
{
	char	*spaceship;
	char	*virtual_reality;
	int		stargate;
	int		passengers;

	spaceship = "This is a test";
	stargate = 0;
	passengers = 0;
	while (stargate < 1000000)
	{
		passengers = ft_strlen(spaceship);
		virtual_reality = ft_new_universe(spaceship, passengers);
		if (!ft_check_one_dimensional_reality(virtual_reality))
			break;
		printf("Spaceship %s has reached the end of virtual reality: '%s', tried stargate %d.\n", spaceship, virtual_reality, stargate);
		stargate++;
	}
	printf("Found the alternating reality: '%s'! Choosen stargate is: %d\n", virtual_reality, stargate);
}