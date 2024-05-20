/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:52:35 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/26 15:27:28 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ----- INCLUDES ----- */

# include <stdlib.h>
# include <unistd.h>

/* ----- STRUCTURES ----- */

// Linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Double linked list
typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

// Specialized linked list for get_next_line()
typedef struct s_gnl
{
	char			*content;
	size_t			len;
	size_t			i;
	struct s_gnl	*next;
}	t_gnl;

/* ----- PROTOTYPES ----- */

// Character
char	ft_isascii(char c);
char	ft_isalpha(char c);
char	ft_isalnum(char c);
char	ft_isdigit(char c);
char	ft_isprint(char c);
char	ft_tolower(char c);
char	ft_toupper(char c);

// String
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	ft_strcmp(const char *s1, const char *s2);
char	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	**ft_split_set(char const *s, char *set);
size_t	ft_skip_ws(size_t i, char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
char	ft_in(const char c, const char *set);
char	ft_in_set(const char *set, const char *str);

// Memory
void	*ft_memchr(const void *s, int c, size_t n);
char	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// File
char	*gnl(int fd, size_t size, char *error);
// get_next_line - Additionnal prototypes - Start
char	ft_lstnew_back_gnl(t_gnl **fd_arr, int fd, char *content, size_t len);
char	ft_in_gnl(char *s, size_t i_start, size_t len);
char	*ft_gnlclear(t_gnl **fds);
// get_next_line - Additionnal prototypes - End
char	**ft_read_lines(int fd);

// Print
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putendl_fd(char *s, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);

// Linked list
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
char	ft_lstnew_back(t_list **lst, void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
char	**ft_lst_to_arr(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

// Arrays
void	ft_free_arr(void **arr);
void	ft_free_arr_arr(void ***array_of_arrays);

#endif
