#include "ft_printf.h"
#include <limits.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
static void max()
{
	// test->debug = 1;
	//printf("LOL:{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);
}

int		main(void)
{
	int a;
	unsigned long l;
	char *str;
	
/********** FUCKED UP **************************/
	
	ft_printf("%00-2147483648d", 34);
	// printf("%0#2147483648d", 12);
	// ft_printf("%0#.2147483648d", 12);
	//printf("\n");
    //printf("%00-2147483648d", 34);

/********** END OF FUCKED UP **************************/

    
/*
	ft_printf("%llX\n", 4294967296);
	printf("%llX\n", 4294967296);
	

	ft_printf("%jx\n", 4294967296);
	printf("%jx\n", 4294967296);
	

	ft_printf("%jx\n", -4294967296);
	printf("%jx\n", -4294967296);
	

	ft_printf("%jx\n", -4294967297);
	printf("%jx\n", -4294967297);
	
	ft_printf("%llx\n", 9223372036854775807);
	printf("%llx\n", 9223372036854775807);
	
	ft_printf("%llx\n", 9223372036854775808);
	printf("%llx\n", 9223372036854775808);
	
*/
	// ft_printf("%5d\n", -42);
	// printf("%5d\n", -42);

	// ft_printf("%03.2d\n", -1);
	// printf("%03.2d\n", -1);

	// ft_printf("@moulitest: %c[]\n", 0);
	// printf("@moulitest: %c[]\n", 0);

	// ft_printf("null %c and text\n", 0);
	// printf("null %c and text\n", 0);

	// ft_printf("%");
	// printf("\n");
	// printf("%");
	// ft_printf("%.0p, %.p\n", 0, 0);
	// printf("%.0p, %.p\n", 0, 0);

	// int ret = ft_printf("{%3c}", 0);
	// printf("\n");
	// int rat = printf("{%3c}", 0);
	// printf("\n");
	// printf("%d : %d\n", ret, rat);

	// int ret = ft_printf("{%p}", &main);
	// printf("\n");
	// int rat = printf("{%20p}", &main);
	// printf("\n");
	// printf("%d : %d\n", ret, rat);


	// int a = printf("%.");
	// printf("\n");
	// int b = ft_printf("%,");
	// printf("\n%d : %d\n", a, b);


	/* TO-DO
	1.	Realize proper ptr for nums and functions:
			Consider following snippets:
				ft_printf("{%05p}", 0);
				ft_printf("{%05p}", &main);
	2.	Repair the instruct->type taking (when there is 1 char in str):
			Consider following snippets:
				ft_printf("%.");
				ft_printf("%");

	*/
	// int a = ft_printf("%hhO, %hhO", 0, USHRT_MAX);
	// printf("\n");
	// int b = printf("%hhO, %hhO", 0, USHRT_MAX);
	// printf("\n%d : %d\n", a, b);




	// ft_printf("%hhO, %hhO", 0, USHRT_MAX);
	// printf("\n");
	// printf("%hhO, %hhO\n", 0, USHRT_MAX);

	//uintmax_t a = LONG_MAX;
	//printf("%ju\n", a);
	// int b = printf("{%05.c}", 0);
	// printf("\n");
	// int a = ft_printf("{%05.c}", 0);
	// printf("\n");
	// printf("%d:%d\n", a, b);

	// int a = ft_printf("{%30.120S}", L"我是一只猫。");
	// printf("\n");
	// int b = printf("{%30.120S}", L"我是一只猫。");
	// printf("\n");
	// printf("%d:%d\n", a, b);
	// ft_printf("%c\n", 0);
	// int a = printf("{%03.c}\n", 0); // print with cat -e
	// int b = ft_printf("{%03.c}\n", 0); // print with cat -e
	// printf("%d:%d\n", a, b);
	
	// int x = printf("{%03.c}", 0);
	// printf("\n");
	// int y = ft_printf("{%03.c}", 0);
	// // printf("\n%d:%d\n", x, y);
	// printf("\n");
	// int ret = printf("{%05.c}", 0);
	// printf("\n");
	// int rat = ft_printf("{%05.c}", 0);
	// printf("\n");
	// printf("%d:%d\n",ret, rat);


	// printf("\n");
	// printf("@moulitest: %c", 0);

	// ft_printf("% hZ%");
	// printf("\n");
	// printf("% hZ%");
	
	// int ret = ft_printf("{%30.120s}", "olol"); 
	// printf("\n");
	// int rat = printf("{%30.120s}", "olol"); 
	// printf("\n");
	// printf("%d:%d\n", ret, rat);
	// ft_printf("% c\n", 0);
	// printf("% c\n", 0);  

	// ft_printf("%jx\n", -4294967296);
	// printf("%jx\n", -4294967296);
	// ft_printf("%2c[]\n", 0);
	// printf("%2c[]\n", 0);

	// ft_printf("% c[]\n", 0);
	// printf("% c[]\n", 0);    

	// ft_printf("%jx\n", -4294967297);
	// printf("%jx\n", -4294967297);

	// ft_printf("%jx\n", 4294967321);
	// printf("%jx\n", 4294967321);
	

	// ft_printf("%++ d\n", -42);
	// printf("%++ d\n", -42); 
	// ft_printf("%-5d\n", 42);
	// printf("%-5d\n", 42);
	//TEST -> 33



	return (0);
}

//# -> is only used with (o,O), (x,X) -> without bonuses, it is telling special type of variable
// if num is o -> it will print 0num, which means that var is octal, if X -> 0x