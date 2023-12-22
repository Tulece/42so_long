/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:02:08 by antoine           #+#    #+#             */
/*   Updated: 2023/12/21 17:04:50 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	gnl_ft_strlen(char const *str);
char	*gnl_ft_strjoin(char *s1, char const *s2);
char	*ft_stash_update(char *stash);
char	*ft_get_line(char *stash);
char	*ft_read(int fd, char *buf, char *stash);
char	*get_next_line(int fd);
char	*gnl_ft_strdup(char const *src);
char	*gnl_ft_strchr(char const *str, int c);
char	*gnl_ft_substr(const char *s, unsigned int start, size_t len);

#endif
