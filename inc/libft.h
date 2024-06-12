/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:37:45 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/30 11:54:43 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*****************************************************************************/
/*                               CHECK CHARS                                 */
/*****************************************************************************/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*****************************************************************************/
/*                                 STRINGS                                   */
/*****************************************************************************/

long	ft_atol(const char *str);
/**
 * @brief Converts a string(str) to a int
 * 
 * @param str 
 * @return int 
 */
int		ft_atoi(const char *str);
/**
 * @brief Locates the first occurrence of c (converted to a
 * char) in the string pointed to by s. The function return a pointer to 
 * the located character, or NULL if the character does not appear in the string.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char	*s, int c);
/**
 * @brief Concatenate strings. ft_strlcat() take the full size of the 
 * destination buffer and guarantee NUL-termination if there is room. Note 
 * that room for the NUL should be included in dstsize.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize);
/**
 * @brief ft_strlcpy() copies up to dstsize - 1 characters from the string src
 * to dst, NUL-terminating the result if dstsize is not 0.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
/**
 * @brief The ft_strlen() function returns the number of characters that 
 * precede the terminating NUL character of the string(str).
 * 
 * @param str 
 * @return size_t 
 */
size_t	ft_strlen(const char *str);
/**
 * @brief The strncmp() function lexicographically compare the null-terminated
 * strings s1 and s2. Compares not more than n characters and return an 
 * integer greater than, equal to, or less than 0, according as the string s1
 * is greater than, equal to, or less than the string s2.  The comparison is
 * done using unsigned characters, so that `\200' is greater than `\0'.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
/**
 * @brief The ft_strstr() function locates the first occurrence of the 
 * null-terminated string needle in the null-terminated string haystack,
 * where not more than len characters are searched. Characters that appear 
 * after a `\0' character are not searched.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len);
/**
 * @brief The ft_strrchr() function is identical to ft_strchr(), except it
 * locates the last occurrence of c.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char	*s, int c);
/**
 * @brief The ft_tolower() function converts an upper-case letter to the
 * corresponding lower-case letter.  The argument must be representable as an
 * unsignedchar or the value of EOF.
 * 
 * @param c 
 * @return int 
 */
int		ft_tolower(int c);
/**
 * @brief The ft_toupper() function converts a lower-case letter to the
 * corresponding upper-case letter. The argument must be representable as an
 * unsignedchar or the value of EOF.
 * 
 * @param c 
 * @return int 
 */
int		ft_toupper(int c);
/**
 * @brief The strdup() function allocates sufficient memory for a copy of the
 * string s1, does the copy, and returns a pointer to it.  The pointer may
 * subsequently be used as an argument to the function free(3).
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup(const char *s1);
/**
 * @brief Utilizando malloc(3), genera una string que represente el 
 * valor entero recibido como argumento. Los números negativos tienen 
 * que gestionarse.
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n);
/**
 * @brief Reserva (utilizando malloc(3)) un array de strings resultante 
 * de separar la string ’s’ en substrings utilizando el caracter ’c’ como 
 * delimitador. El array debe terminar con un puntero NULL.
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *s, char c, int i, int count);
/**
 * @brief Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
 * La substring empieza desde el índice ’start’ y tiene una 
 * longitud máxima ’len’.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief Reserva (con malloc(3)) y devuelve una nueva string, 
 * formada por la concatenación de ’s1’ y’s2’.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Elimina todos los caracteres de la string ’set’ desde
 *  el principio y desde el final de ’s1’, hasta encontrar un caracter
 *  no perteneciente a ’set’. La string resultante se devuelve con una 
 * reserva de malloc(3)
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set);

/*****************************************************************************/
/*                                  MEMORY                                   */
/*****************************************************************************/

/**
 * @brief The ft_bzero() function writes n zeroed bytes to the string s. If n
 * is zero, bzero() does nothing.
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief The ft_memchr() function locates the first occurrence of c (converted
 * to an unsigned char) in string s. The memchr() function returns a pointer to
 * the byte located, or NULL if no such byte exists within n bytes.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void	*ft_memchr(const void	*s, int c, size_t n);
/**
 * @brief The ft_memcpy() function copies n bytes from memory area src to
 * memory area dst.  If dst and src overlap, behavior is undefined. 
 * Applications in which dst and src might overlap should use ft_memmove instead.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief The ft_memmove() function copies len bytes from string src to string
 * dst. The two strings may overlap; the copy is always done in a
 * non-destructive manner.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief The ft_memset() function writes len bytes of value c (converted to an
 * unsigned char) to the string b.
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
void	*ft_memset(void *b, int c, size_t len);
/**
 * @brief The ft_memcmp() function compares byte string s1 against byte 
 * string s2. Both strings are assumed to be n bytes long.
 * The memcmp() function returns zero if the two strings are identical,
 * otherwise returns the difference between the first two differing bytes
 * (treated as unsigned char values, so that `\200' is greater than `\0',
 * for example).  Zero-length strings are always identical.  This behavior
 * is not required by C and portable code should only depend on the sign of
 * the returned value.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief The ft_calloc() function contiguously allocates enough space for
 * count objects that are size bytes of memory each and returns a pointer to
 * the allocated memory.  The allocated memory is filled with bytes of
 * value zero.
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size);

/*****************************************************************************/
/*                                   PUTS                                    */
/*****************************************************************************/

/**
 * @brief Envía el carácter ’c’ al file descriptor especificado.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief Envía la string ’s’ al file descriptor especificado.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief Envía la string ’s’ al file descriptor dado, seguido de un salto 
 * de línea.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Envía el número ’n’ como string al file descriptor dado.
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd);

/*****************************************************************************/
/*                              FT INPUT PARAM                               */
/*****************************************************************************/

/**
 * @brief A cada carácter de la string ’s’, aplica la función ’f’ dando como 
 * parámetros el índice de cada carácter dentro de ’s’ y la dirección del 
 * propio carácter, que podrá modificarse si es necesario.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief A cada carácter de la string ’s’, aplica la función ’f’ dando 
 * como parámetros el índice de cada carácter dentro de ’s’ y el propio 
 * carácter. Genera una nueva string con el resultado del uso sucesivo de ’f’
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*****************************************************************************/
/*                                   LIST                                    */
/*****************************************************************************/

/**
 * @brief Crea un nuevo nodo utilizando malloc(3). La variable miembro 
 * ’content’ se inicializa con el contenido del parámetro ’content’. 
 * La variable ’next’, con NULL.
 * 
 * @param content 
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief Añade el nodo ’new’ al principio de la lista ’lst’.
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Cuenta el número de nodos de una lista.
 * 
 * @param lst 
 * @return int 
 */
int		ft_lstsize(t_list *lst);
/**
 * @brief Devuelve el último nodo de la lista.
 * 
 * @param lst 
 * @return t_list* 
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief Añade el nodo ’new’ al final de la lista ’lst’.
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Toma como parámetro un nodo ’lst’ y libera la memoria del 
 * contenido utilizando la función ’del’ dada como parámetro, además 
 * de liberar el nodo. La memoria de ’next’ no debe liberarse.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Elimina y libera el nodo ’lst’ dado y todos los consecutivos de 
 * ese nodo, utilizando la función ’del’ y free(3). Al final, el puntero a 
 * la lista debe ser NULL.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Itera la lista ’lst’ y aplica la función ’f’ en el 
 * contenido de cada nodo.
 * 
 * @param lst 
 * @param f 
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Itera la lista ’lst’ y aplica la función ’f’ al contenido 
 * de cada nodo. Crea una lista resultante de la aplicación correcta 
 * y sucesiva de la función ’f’ sobre cada nodo. La función ’del’ se 
 * utiliza para eliminar el contenido de un nodo si falla la copia/modificación
 * de algún nodo, en cuyo caso se devuelve la nueva lista apuntando a NULL
 * liberando antes la memoria asignada hasta el momento.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*****************************************************************************/
/*                               GET_NEXT_LINE                               */
/*****************************************************************************/

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *pre_read, char *buffer, int bytes_readed);
int		ft_strlen_gnl(char *str);
char	*read_and_save(int fd, char *pre_read);
char	*clean_pre_read(char	*pre_read);
char	*get_new_line(char	*pre_read);
void	copy_read(char *pre_read, char *copy, int j, int len);

/*****************************************************************************/
/*                                 FT_PRINTF                                 */
/*****************************************************************************/

int		ft_printf(char const *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printdecimal(int n);
int		ft_printunsint(unsigned int n);
int		ft_printhex(unsigned long i, char c);

#endif