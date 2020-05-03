/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystdio.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <jiin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:16:50 by jiin              #+#    #+#             */
/*   Updated: 2020/04/28 21:56:39 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTDIO_H
# define MYSTDIO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFSIZE			1024
# define READONLY_MODE		0
# define WRITEONLY_MODE		1

typedef struct				s_myfile
{
    int						fd;
    char					mode;
	char					buf[BUFSIZE];
	int						length;
	int						offset;
}							MYFILE;

MYFILE						*myfopen(char *file, char *mode);
int							myfclose(MYFILE *fp);
char						myfgetc(MYFILE *fp);
int							myfputc(char c, MYFILE *fp);

#endif