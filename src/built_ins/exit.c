
#include "../../inc/mshell_exec.h"

//Esto hay que revisarlo por que aún no entiendo bien como funciona lo de
//los códigos de error en la salida
void	ft_exit(int	error_code, t_minishell *minishell)
{
	ft_free_minishell(minishell);
	exit(error_code);
}