
#include "libft/libft.h"
#include <stdio.h>

int main()
{
	char *line1;
	char *line2;

	line1 = get_next_line(0);
	line2 = get_next_line(0);
	
	if(!ft_strncmp(line1, line2, 4))
		printf("equal lines\n");
	else
		printf("unequal lines\n");
	free(line1);
	free(line2);
	return (0);
}
