/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:24:39 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/15 18:09:31 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "LIBFTall/libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/wait.h>

char	**envp_path_dir(char **envp);
char    *find_path(char **envp, char *cmd);
char	*ft_sostrjoin(const char *s1, const char *s2);
int		ft_sostrlen(const char *s);
void	redirect_and_close(int fd, int *pipefd, int child_num);
void	first_child(int *fd, int *pipefd, char **argv, char **envp);
void	second_child_crt(int *fd, int *pipefd, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);
void	free_strings(char **strings);
void	error_handle(char *str);
void	error_free_handle(char **cmd, int fd, int *pipefd);

# endif