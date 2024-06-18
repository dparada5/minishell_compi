
#include "../../inc/mshell_exec.h"

void	ft_check_and_delete(t_env **envxp, char *key)
{
	t_env	*previous;
	t_env	*runner;

	runner = *envxp;
	while (runner)
	{
		if (!ft_strncmp(runner->key, key, ft_strlen(key)))
		{
			if (runner->index == 0)
				*envxp = runner->next;
			else
				previous->next = runner->next;
			free(runner->content);
			free(runner->key);
			free(runner);
			break;
		}
		previous = runner;
		runner = runner->next;
	}

}

//cambiar los arg cuando delfi añada el exp a la struct de minishell
void	ft_unset(t_minishell *mshll, t_env *exp, char *key_to_delete)
{
	ft_check_and_delete(&(mshll->env), key_to_delete);
	ft_check_and_delete(&exp, key_to_delete);
}