/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:04:03 by dsoporan          #+#    #+#             */
/*   Updated: 2017/05/12 15:57:58 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "ft_printf/includes/ft_printf.h"

void get_file_time(char *path)
{
	struct stat buf;
	stat(path, &buf);
   	ft_printf("time :%s", ctime(&buf.st_mtime));	
}

int main(int argc, char **argv)
{
	argc = 42;
	DIR *dir;
	struct dirent *files;

	dir = opendir(argv[1]);
	if (dir == NULL)
	{
		perror("Error ");
		exit(0);
	}
	else
	{
		files = readdir(dir);
		while (files != NULL)
		{
			get_file_time(__FILE__);
			ft_printf("files: %s\n", files->d_name);
			files = readdir(dir);
		}
	}
	closedir(dir);
	return (0);
}
