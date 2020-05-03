/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <jiin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:51:52 by jiin              #+#    #+#             */
/*   Updated: 2020/04/28 21:38:24 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
** desc: remove files
** params: argc, argv[]
** return: 0 - 정상적인 종료
** note : 매개변수가 없거나 파일이 아닌경우, 경고 메시지 출력. 파일이 들어온 경우 삭제.
*/
int main(int argc, char *argv[])
{
	struct stat		buf;
	int				i;

	i = 1;
	if (argc <= 1)
	{
		printf("usage : myrm files...\n");
		printf("please check your input counts\n");
		return (0);
	}
	while (i < argc)
	{
        if (stat(argv[i], &buf) >= 0)
        {
            if ((S_ISDIR(buf.st_mode)))
                fprintf(stderr, "%s is not a file\n", argv[i]);
        }
		unlink(argv[i]);
		i++;
	}
	return (0);
}

