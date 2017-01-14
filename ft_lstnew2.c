#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	if (!(link = (t_list *)malloc(sizeof(*link))))
		return (NULL);
	if (content)
	{
		if (link->content = malloc(content_size))
		{
			ft_memcpy(link->content, content, content_size);
			link->content_size = content_size;
		}
		else
			return (NULL);
	}
	else
	{
		link->content = NULL;
		link->content_size = 0;
	}
	link->next = NULL;
	return (link);
}
