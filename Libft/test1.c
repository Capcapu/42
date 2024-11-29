/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:00 by csolari           #+#    #+#             */
/*   Updated: 2024/11/13 11:37:54 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
    /*
    ft_isalpha

        printf("%d\n", ft_isalpha('a'));
        printf("%d\n", isalpha('a'));
        printf("%d\n", ft_isalpha('Z'));
        printf("%d\n", isalpha('Z'));
        printf("%d\n", ft_isalpha(' '));
        printf("%d\n", isalpha(' '));
    */
   
    /*
    ft_isdigit

        printf("%d\n", ft_isdigit('0'));
        printf("%d\n", isdigit('0'));
        printf("%d\n", ft_isdigit('9'));
        printf("%d\n", isdigit('9'));
        printf("%d\n", ft_isdigit(' '));
        printf("%d\n", isdigit(' '));
    */
   
    /*
    ft_isalnum

        printf("%d\n", ft_isalnum('U'));
        printf("%d\n", isalnum('U'));
        printf("%d\n", ft_isalnum('3'));
        printf("%d\n", isalnum('3'));
        printf("%d\n", ft_isalnum(' '));
		printf("%d\n", isalnum(' '));
    */
   
    /*
    ft_isascii

        printf("%d\n", ft_isascii(200));
        printf("%d\n", isascii(200));
        printf("%d\n", ft_isascii('3'));
        printf("%d\n", isascii('3'));
        printf("%d\n", ft_isascii(' '));
		printf("%d\n", isascii(' '));
	*/

    /*
    ft_isprint
	
        printf("%d\n", ft_isprint('U'));
        printf("%d\n", isprint('U'));
        printf("%d\n", ft_isprint('\v'));
        printf("%d\n", isprint('\v'));
        printf("%d\n", ft_isprint(' '));
		printf("%d\n", isprint(' '));
	*/

    /*
    ft_strlen

	    printf("%d\n", ft_strlen("Un chapeau"));
        printf("%lu\n", strlen("Un chapeau"));
        printf("%d\n", ft_strlen("v"));
        printf("%lu\n", strlen("v"));
        printf("%d\n", ft_strlen(""));
		printf("%lu\n", strlen(""));
	*/

    /*
    ft_memset
	
		char s1[] = "";
		char s2[] = "";
		ize_t n;
		size_t	o;
    
		n = 4;
		o = 4;
    	ft_memset(s1, '7', n);
		memset(s2, '7', o);
   		printf("%s\n", s1);
    	printf("%s", s2);
	*/

    /*
    ft_bzero
	
		char s1[] = "r";
		size_t n;
	    int	i;

		i = 0;
		n = 3;
    	ft_bzero(s1, n);
		while(i< 7)
		{
	   		printf("%c\n", s1[i++]);
		}
	*/

    /*
    ft_memcpy

		char	src[] = "hey";
		char	dest[] = "";
		size_t n;
    	int	i;

		i = 0;
		n = 3;
    	ft_memcpy(dest, src, n);
		printf("%s\n", dest);
	*/

	/*
    ft_memmove

		char	dest[] = "la";
		char	src[] = "hey";

		size_t n;
    	int	i;

		i = 0;
		n = 3;
    	ft_memmove(dest, src, n);
		printf("%s\n", dest);
	*/

	/*
	ft_strlcpy
	
		char src[]="oups";
		char dst[]="hephep";
		size_t res;

		printf("%s\n", dst);
		printf("%s\n", src);
		res = ft_strlcpy(dst, src, 6);
		printf("%zu\n",res);
    	printf("%s\n", dst);
    	printf("%s\n", src);	

		//  -> Don't forget : compiler avec -lbsd ;)
	*/
	
	/*
	ft_strlcat

		char	dest[]="blabla";
		char	src[]="hey";
		int	res;
	
		res = ft_strlcat(dest, src, 4);
		printf("%d\n", res);
		printf("%s\n", dest);
		printf("%s\n", src);
		return(0);
	*/

	/*
	ft_toupper

		printf("%c\n", ft_toupper('x'));
		printf("%c", ft_toupper(' '));
	*/

	/*
	ft_tolower

		printf("%c\n", ft_tolower('x'));
		printf("%c", ft_tolower('A'));
	*/

	/*
	ft_strchr

		char	t[]= "bonjour je m'appelle capucine";
		printf("%s", ft_strchr(t, ' '));
	*/

	/*
	ft_strrchr

		char	t[]= "bonjour je m'appelle capucine";
		printf("%s", ft_strrchr(t, 'b'));
	*/

	/*
	ft_strncmp

		char	t[]= "bonjour je m'appelle Alfred2";
		char	c[] = "bonjour je m'appelle Alfred ";
		printf("%d", ft_strncmp(t,c,27));
	*/

	/*
	ft_memchr

		char	s[]="bonjour";
    	printf("%s",ft_memchr(s,'j', 3));
	*/

	/*
	ft_memcmp

		char	t[]= "bonjou";
		char	c[] = "bonjou";
		printf("%d", ft_memcmp(t,c,6));
	*/

	/*
	ft_strnstr

		char	b[]= "bonejour je m'appelle Alfred";
		char	l[] = "";
		printf("%s", strnstr(b,l,30));
	*/

	/*
	ft_atoi

		printf("%d", atoi("147483647"));
	*/

	/*
	ft_calloc

		int	*p;
		int	i;

		i = 0;
		p = ft_calloc(9, sizeof(int));
		while (i < 12)
		{
		printf("%d", p[i]);
		i++;
		}
		free(p);
	*/

	/*
	ft_strdup

		char	s1[]="helloyoupi heyyyy";
		char	*s2;

		s2 = ft_strdup(s1);
		printf("%s", s2);
		free(s2);
	*/

	/*
	ft_substr
	
		char	s1[] = "bonjour Alfred";

		char	*sub;

//		sub = ft_substr(s1, 2, 8);
		sub = ft_substr("hola", 4294967295, 0);
		printf("%s", sub);
		free(sub);
	*/
	
	/*
	ft_strjoin

		char	s1[] = "bonjourr ";
		char	s2[] = "comment tu vas ?";
		char	*join;

		join = ft_strjoin(s1, s2);
		printf("%s", join);
		free(join);
	*/

	/*
	ft_strtrim

		char	s1[] = "  \t \t \n   \n\n\n\t"; //"========//bonjourr===o--";
		char	set[] = " \n\t"; // "==//-o";
		char	*trim;

		trim = ft_strtrim(s1, set);
		printf("%s\n", trim);
		free(trim);
	*/	

	/*
	ft_split

		char	*test = "bonjoururje m'appelle Alfred et je suis heureux !";
		char	**tab;
		int 	i = 0;
		
		tab = ft_split(test, 'r');
		while (tab[i] != NULL)
		{
			printf("%s\n", tab[i]);
			free (tab[i]);
			i++;
		}
		free(tab);
	*/

	/*
	ft_itoa
	*/
		int	n = -156;
		char	*p;

		p = ft_itoa(n);
		printf("%s", p);
		free(p);


	/*
	ft_strmapi

		char	s[] = "hello";
		char	*sup;

		sup = ft_strmapi(s, ft_toupper);
		printf("%s", sup);
	*/

	/*
	ft_striteri
	*/

	/*
	ft_putchar_fd
	
		ft_putchar_fd('c', 1);
	*/

	/*
	ft_putstr_fd

		ft_putstr_fd("hello", 1);
	*/

	/*
	ft_putendl_fd

		ft_putendl_fd("hello", 1);
	*/

	/*
	ft_putnbr_fd
	
		ft_putnbr_fd(0, 1);
		ft_putchar_fd('\n',1);
		ft_putnbr_fd(-2147483648, 1);
	*/




	return (0);
}

