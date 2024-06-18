#include "minishell.h"

int main(void)
{
	int	fd = open("adios", O_RDWR | O_CREAT | O_TRUNC, 0644);
	printf("%d\n", fd);
	fd = open("adios", O_RDWR | O_CREAT | O_TRUNC, 0644);
	printf("%d\n", fd);
}