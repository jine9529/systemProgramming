/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <jiin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:32:21 by jiin              #+#    #+#             */
/*   Updated: 2020/04/28 02:44:00 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystdio.h"

int main(void)
{
    int c;
    MYFILE *fpin, *fpout;

    if ((fpin = myfopen("a", "r")) == NULL)
    {
        perror("a");
        exit(-1);
    }
    if ((fpout = myfopen("b", "w")) == NULL)
    {
        perror("b");
        exit(-1);
    }
    while((c = myfgetc(fpin)) != EOF)
    {
		myfputc(c, fpout);
    }
    // myfclose(fpin);
    if (myfclose(fpin) != 0)
    {
        perror("fpin");
        exit(-1);
    }
    // myfclose(fpout);
    if (myfclose(fpout) != 0)
    {
        perror("fpout");
        exit(-1);
    }
    myfclose(fpout);
	return (0);
}