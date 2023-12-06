/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:38:19 by anporced          #+#    #+#             */
/*   Updated: 2023/11/15 23:57:33 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_stash_update(char *stash);
char	*ft_get_line(char *stash);
char	*ft_read(int fd, char *buf, char *stash);
char	*get_next_line(int fd);
char	*ft_strdup(char const *src);
char	*ft_strchr(char const *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
