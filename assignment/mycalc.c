/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mycalc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <jiin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:24:24 by jiin              #+#    #+#             */
/*   Updated: 2020/04/28 21:38:15 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
** desc: 매개변수값이 정수인지 확인하는 함수
** params: 문자열
** return:  0 - 정수
**			1 - 실수, 문자 등 정수를 제외한 type
*/
int		is_num(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (s[i] <= 48 || s[i] >= 57)
			return (1);
		i++;
	}
	return (0);
}

/*
** desc: calculate integers
** params: argc, argv[]
** return: 0 - 정상적인 종료
** note : 매개변수가 없거나 정수가 아닌경우, 경고 메시지 출력. 정상적인 경우 합계 출력.
*/
int main(int argc, char *argv[])
{
	int sum;
	int i;

	sum = 0;
	i = 1;
	if (argc <= 1)
	{
		printf("usage : mycalc numbers...\n");
		printf("please check your input counts\n");
		return (0);
	}
	while (i < argc)
	{
		if (is_num(argv[i]))
			{
				printf("plese input only integer(s)\n");
				return (0);
			}
		sum += atoi(argv[i]);
		i++;
	}
	printf("%d\n", sum);

	return (0);
}

