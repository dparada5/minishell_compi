
#include "../inc/mshell_exec.h"

t_env	*ft_get_envvar(t_env *env, char *var_name)
{
	t_env	*aux;

	aux = env;
	while (aux)
	{
		if (!ft_strncmp(aux->key, var_name, ft_strlen(aux->key)))
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

int	ft_change_envvar(t_env *env, char *var_name, char *new_value)
{
	t_env	*aux;

	aux = env;
	while (aux->key != var_name && aux)
		aux = aux->next;
	if (!aux)
		return (0);
	free (aux->content);
	aux->content = ft_strdup(new_value);
	return (1);
}
