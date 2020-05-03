/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystdio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <jiin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:17:02 by jiin              #+#    #+#             */
/*   Updated: 2020/04/29 20:35:25 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystdio.h"
#define WCIO_FREE(fp) ((void)(0))

/*
** desc: opens the file
** params: f - *pathname, m - *mode
** return: success - file pointer, fail - errno
** note : possible read, write mode
*/
MYFILE		*myfopen(char *f, char *m)
{
	MYFILE *fp = (MYFILE*)malloc(sizeof(MYFILE));

	if (fp != NULL)
	{
		if (strcmp(m, "r") == 0)
		{
			if ((fp->fd = open(f, O_RDONLY)) < 0)
			{
				free(fp);
				return NULL;
			}
			fp->mode = READONLY_MODE;
		}
		else if (strcmp(m, "w") == 0)
		{
			if ((fp->fd = open(f, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
			{
				free(fp);
				return NULL;
			}
			fp->mode = WRITEONLY_MODE;
		}
		else
		{
			fprintf(stderr, "not supported mode: %s\n", m);
			free(fp);
			return NULL;
		}
		fp->length = fp->offset = 0; //mark the buffer as empty
	}
	return (fp);
}

/*
** desc: read the next character from stream
** params: fp - *MYFILE
** return: success - a character
		   fail - EOF on end of file
*/
char		myfgetc(MYFILE *fp)
{
	if (fp == NULL)
		return EOF;
	if (fp->offset == fp->length)
	{
		if ((fp->length = read(fp->fd, fp->buf, BUFSIZE)) < 1)
			return EOF;
		fp->offset = 0; //set the head to the top of the buffer
	}
	return (fp->buf[fp->offset++]);
}


/*
** desc: writes the character c, cast to an unsigend char
** params: c - character, fp - *MYFILE
** return: success - the character written as an unsigend char 
		   fail - EOF on end of file
*/
int		myfputc(char c, MYFILE *fp)
{
	char uc;

	uc = (unsigned char)c;
	if (fp == NULL)
		return EOF;
	if (write(fp->fd, &uc, 1) < 0)
		return EOF;
	return (uc);
}

/*
** desc: close a stream
** params: fp - *MYFILE
** return: 0 - successful completion
		   EOF - error
** note : fp가 NULL을 가리키게 해서 닫혀진 스트림임을 명시
*/
int			myfclose(MYFILE *fp)
{
	if (fp == NULL)
		return EOF;

	WCIO_FREE(fp);

	if (close(fp->fd) < 0)
	{
		free(fp);
		return EOF;
	}
	else
	{
		fp = NULL;
		free(fp);
		return (0);
	}
}
