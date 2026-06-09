/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:42:49 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/09 18:17:25 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		parsing(t_input *input, char **argv);
int		valid_num(char *str);
int		check_dups(t_input *input);
void	free_split(char **arg);
int		parse_argument(t_input *input, char *str);

// split
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
size_t	subs_count(char const *s, char c);
int		fill(char **split, char const *s, char c);
char	**ft_split(char const *s, char c);

#endif