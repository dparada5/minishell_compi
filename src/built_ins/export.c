
#include "../../inc/mshell_exec.h"

void	ft_print_exp(t_env *exp)
{
	t_env *runner;

	while (runner)
	{
		ft_printf("declare -x %s=\"%s\"\n", runner->key, runner->content);
		runner = runner->next;
	}
}

void	ft_export_print(t_env **exp)
{
	t_env	*prev_node;
	t_env	*swap_aux;
	t_env	*run;

	run = *exp;
	while (run)
	{
		if (ft_strncmp(run->content, run->next->content, ft_strlen(run->content)) > 0)
		{
			if (!prev_node)
			{
				swap_aux = run->next->next;
				*exp = run->next;
				run->next->next = run;
				run->next = swap_aux;
			}
			else
				ft_swap_envnodes(prev_node, run, run->next, run->next->next);
			prev_node = NULL;
			run = *exp;
		}
	}
	ft_print_exp(*exp);
}

void	ft_export_insert(t_minishell *mshll, char *str)
{
	char	*key;
	char	*content;
	int		i;

	i = 0;
	if (ft_strchr(str, '=') == NULL)
		ft_lstadd_back_env(&(mshll->exp), new_env_exp(str, NULL));
	else
	{
		while (str[i] != '=')
			i++;
		key = ft_substr(str, 0, i);
		content = ft_substr(str, i + 1, ft_strlen(str) - (i + 1));
		ft_lstadd_back_env(&(mshll->exp), new_env_exp(key, content));
		ft_lstadd_back_env(&(mshll->env), new_env_exp(key, content));
		ft_save_env_mat(mshll);
	}
}
