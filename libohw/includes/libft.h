/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:47:29 by ohw               #+#    #+#             */
/*   Updated: 2022/07/24 11:57:31 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define LONG_MAX 9223372036854775807
# define LONG_MIN -9223372036854775808U

typedef struct s_list_node
{
	void				*content;
	struct s_list_node	*next;
	struct s_list_node	*prev;
}	t_list_node;

typedef struct s_list
{
	t_list_node	*front;
	t_list_node	*rear;
	int			len;
}			t_list;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
char		*ft_itoa_base(int n, int base, int capital);
t_list_node	*ft_new_node(void *item);
t_list		*ft_lstnew(void);
void		ft_lstadd_front(t_list *lst, void *item);
int			ft_lstsize(t_list *lst);
t_list_node	*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list *lst, void *item);
void		ft_lstclear(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
