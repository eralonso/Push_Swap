#include	"push_swap.h"

int	ft_check_num(char **input)
{
	int	i;
	int	j;
	
	i = 0;
	while (input[++i])
	{
		j = 0;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]) && !ft_strchr("+-", input[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int	ft_isint(char *input, int sign)
{
	if (ft_strlen(input) > (ft_nbr_size(INT_MAX, 10) + sign))
		return (0);
	return (1);
}
