#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	if (!(link = (t_list *)malloc(sizeof(*link))))
		return (NULL);
	link->content = content;
	link->content_size = content_size;
	link->next = NULL;
	return (&link);
}
