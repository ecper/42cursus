#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static void	check_return_value(int result1, int result2)
{
	printf("\n");
	if (result1 == result2)
		printf("OK\n");
	else
		printf("KO\n");
	printf("\n");
}

static void	special_test_case(void)
{
	int	result1;
	int	result2;

	result1 = 0;
	result2 = 0;
	printf("test1\n");
	result1 = ft_printf("");
	result2 = printf("");
	check_return_value(result1, result2);
	printf("test2\n");
	result1 = ft_printf(NULL);
	printf("\n");
	result2 = printf(NULL);
	check_return_value(result1, result2);
	printf("test3\n");
	result1 = ft_printf((void *)0);
	printf("\n");
	result2 = printf((void *)0);
	check_return_value(result1, result2);
	printf("test4\n");
	result1 = ft_printf("%c", 0);
	printf("\n");
	result2 = printf("%c", 0);
	check_return_value(result1, result2);
	printf("test5\n");
	result1 = ft_printf("%d", INT_MIN);
	printf("\n");
	result2 = printf("%d", INT_MIN);
	check_return_value(result1, result2);
	printf("test6\n");
	result1 = ft_printf("%d", INT_MAX);
	printf("\n");
	result2 = printf("%d", INT_MAX);
	check_return_value(result1, result2);
	printf("test7\n");
	result1 = ft_printf("%i", INT_MAX);
	printf("\n");
	result2 = printf("%i", INT_MAX);
	check_return_value(result1, result2);
	printf("test8\n");
	result1 = ft_printf("%i", INT_MIN);
	printf("\n");
	result2 = printf("%i", INT_MIN);
	check_return_value(result1, result2);
	printf("test9\n");
	result1 = ft_printf("%u", UINT_MAX);
	printf("\n");
	result2 = printf("%u", UINT_MAX);
	check_return_value(result1, result2);
	printf("test9\n");
	result1 = ft_printf("%u", 0);
	printf("\n");
	result2 = printf("%u", 0);
	check_return_value(result1, result2);
	printf("test10\n");
	result1 = ft_printf("%x", 0);
	printf("\n");
	result2 = printf("%x", 0);
	check_return_value(result1, result2);
	printf("test11\n");
	result1 = ft_printf("%x", UINT_MAX);
	printf("\n");
	result2 = printf("%x", UINT_MAX);
	check_return_value(result1, result2);
	printf("test12\n");
	result1 = ft_printf("%X", 0);
	printf("\n");
	result2 = printf("%X", 0);
	check_return_value(result1, result2);
	printf("test12\n");
	result1 = ft_printf("%X", UINT_MAX);
	printf("\n");
	result2 = printf("%X", UINT_MAX);
	check_return_value(result1, result2);
}

int	main(void)
{
	special_test_case();
}