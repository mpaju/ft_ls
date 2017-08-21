#include "ft_ls.h"

typedef struct s_test {
	char *name;
	struct s_test *next;
}				t_test;

void	swap_nodes(t_test **node1, t_test **node2, t_test **link)
{
	(*node2)->next = *node1;
	*link = *node2;
	(*node1)->next = NULL;
}

int main(int argc, const char *argv[])
{
	t_test *test1, *test2, *test3;

	test1 = (t_test *)ft_memalloc(sizeof(test1));
	test2 = (t_test *)ft_memalloc(sizeof(test2));
	test3 = (t_test *)ft_memalloc(sizeof(test3));
	
	test1->name = "test1";
	test2->name = "test2";
	test3->name = "test3";

	test1->next = test2;
	test2->next = test3;

	swap_nodes(&test2, &test3, &test1->next);
	return 0;
}
