/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:09:37 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 18:49:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define FT_LLMAX 9223372036854775807ull

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** bonus
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_putchar(int c);
int					ft_atoi(const char *str);
int					ft_putchar_fd(int c, int fd);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

long				ft_atol_base(const char *str, const char *base);

size_t				ft_numlen(long long int nb);
size_t				ft_strlen(const char *str);
size_t				ft_unsignedlen(unsigned long long int nb);
size_t				ft_idxof(char c, const char *str);
size_t				ft_numlen_base(long long int nb, const char *base);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_unsignedlen_base(unsigned long long int nb,
						const char *base);

void				ft_putnbr(int n);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_putnbr_base(int n, const char *base);
void				ft_putnbr_base_fd(int n, const char *base, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, const size_t len);

char				ft_isbase(const char *base);
char				ft_contains(char c, const char *str);

char				*ft_itoa(int n);
char				*ft_lltoa(long long int nb);
char				*ft_lltoa_base(long long int nb, const char *base);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strmcat(const char *s1, const char *s2, int n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);

char				**ft_strsplit(char const *s, char c);

long long int		ft_abs(long long int nb);
long long int		ft_min(long long int a, long long int b);
long long int		ft_max(long long int a, long long int b);
long long int		ft_freturn(void *ptr, long long int ret);

#endif
