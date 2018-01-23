#include <stdio.h>
#include <unistd.h>

int global_static_var1 = 20;
int unassigned_var;

int rando_math_func(int bar){

	printf(" %p <= Stack segment address \n", &bar);
	if(bar < global_static_var1)
		rando_math_func(bar + 1);
	else
		return(bar);
}

int main(void)
{
	int foo = 0;
	printf("\n %d  <= Process ID \n", getpid());
	printf(" %p  <= Text Segment starts around here \n", &rando_math_func);
	printf(" %p  <= Data Segment starting address \n", &global_static_var1);
	printf(" %p  <= BSS Segment starting address \n", &unassigned_var);
	printf(" %d  <= 'bar' after 21 iterations from 0 \n", rando_math_func(foo));
	printf(" %d  <= 'bar' after 6 iterations from 15 \n", rando_math_func(15));
	printf(" %d  <= 'bar' after 3 iterations from 18 \n", rando_math_func(18));
}
