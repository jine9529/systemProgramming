/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mycp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <jiin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:01:52 by jiin              #+#    #+#             */
/*   Updated: 2020/04/28 21:40:28 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE	100

/*
** desc: check is it file
** params: argc, argv[]
** return: 0 - 모두 파일,
		   1 - 파일이 아닌게 하나라도 있음
** note : 파일이 아닌경우 경고 메시지 출력 후 함수 종료
*/
int					is_file(int argc, char *argv[])
{
	int				i;
	struct stat		buf;

	i = 1;
	while (i < argc)
	{
        if (stat(argv[i], &buf) >= 0)
        {
            if ((S_ISDIR(buf.st_mode)))
			{
                fprintf(stderr, "%s is not a file\n", argv[i]);
				return (1);
			}
        }
		i++;
	}
	return (0);
}


/*
** desc: copy files
** params: argc, argv[]
** return: 0 - 정상적인 종료
** note : 첫번째 인자가 파일이 아닌 경우 or 존재하지 않는 경우
		  두번째 인자가 파일이 아닌 경우 or 존재하는 경우
		  인자의 개수가 두 개가 아닌 경우
		  경고 메시지 출력 후 함수 종료.
*/
int				main(int argc, char *argv[])
{
	int			fdin;
	int			fdout;
	ssize_t 	nread;
	char		buf[BUFSIZE];

	if (argc != 3)
	{
		printf("usage : mycp file1 file2\n");
		printf("please cheak your input counts\n");
		return (0);
	}

	if(is_file(argc, argv))
		return (0);

	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
	{
		perror(argv[1]);
		close(fdin);
		return (0);
	}

	fdout = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
	if (fdout == -1)
	{
		printf("파일 %s가 이미 존재합니다.\n", argv[2]);
		close (fdin);
		close(fdout);
		return (0);
	}

	while ((nread = read(fdin, buf, BUFSIZE)) > 0)
	{
		if (write(fdout, buf, nread) > nread)
		{
			break;
		}
	}
	close(fdin);
	close(fdout);
	return (0);
}
