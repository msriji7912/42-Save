
    new_node = ft_lstnew((*f)(lst->content));
    if (!new_node)
    {
        ft_lstclear(&lst, del);
        return (NULL);
    }
    new_list = new_node;
    lst = lst->next;
    while (lst)
    {
        new_node = ft_lstnew((*f)(lst->content));
        if (!mew_node)
        {
            ft_lstclear(&lst, del);
            return (NULL);
        }
        lst = lst->next;
        ft_lstadd_back(&new_list, new_node);
    }
    return (new_list);
}
/*void del(void *content)
{
    free(content);
}
int main()
{
    t_list *Chainsaw = ft_lstnew("Pablito");
    t_list *Man = ft_lstnew("Dozo");
    t_list *Zergling = ft_lstnew("Chnowa");

    Chainsaw->next = Man;
    Man->next = Zergling;
    
    t_list *map = ft_lstmap(Chainsaw, (void *)ft_toupper, del);
    t_list *temp = map;

    while(temp)
    {
        printf("%s ", (char *)temp->content);
        temp = temp->next;
    }
    
    
}*/