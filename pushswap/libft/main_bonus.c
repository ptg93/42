#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

void free_content(void *content)
{
    free(content);
}

void *duplicate_content(void *content)
{
    char *str = (char *)content;
    char *new_str = malloc(ft_strlen(str) + 1);
    if (!new_str)
        return (NULL);
    ft_strlcpy(new_str, str, ft_strlen(str) + 1);
    return (new_str);
}

int main(void)
{
    t_list *node1 = ft_lstnew(ft_strdup("Node 1"));
    t_list *node2 = ft_lstnew(ft_strdup("Node 2"));
    t_list *node3 = ft_lstnew(ft_strdup("Node 3"));
    t_list *head = NULL;

    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    printf("Lista tras añadir nodos al frente:\n");
    ft_lstiter(head, print_content);

    printf("\nTamaño de la lista: %d\n", ft_lstsize(head));

    t_list *last = ft_lstlast(head);
    printf("\nÚltimo nodo: %s\n", (char *)last->content);

    t_list *new_node = ft_lstnew(ft_strdup("New Node"));
    ft_lstadd_back(&head, new_node);

    printf("\nLista tras añadir un nodo al final:\n");
    ft_lstiter(head, print_content);

    if (head == node2)
    {
        head = node2->next;
        ft_lstdelone(node2, free_content);
    }
    else
    {
        t_list *temp = head;
        while (temp && temp->next != node2)
            temp = temp->next;
        if (temp && temp->next == node2)
        {
            temp->next = node2->next;
            ft_lstdelone(node2, free_content);
        }
    }

    printf("\nLista tras eliminar el nodo 2:\n");
    ft_lstiter(head, print_content);

    t_list *new_list = ft_lstmap(head, duplicate_content, free_content);

    printf("\nNueva lista duplicada con ft_lstmap:\n");
    ft_lstiter(new_list, print_content);

    printf("\nLimpiando nueva lista...\n");
    ft_lstclear(&new_list, free_content);

    if (!new_list)
        printf("Nueva lista limpiada correctamente.\n");

    printf("\nLimpiando lista original...\n");
    ft_lstclear(&head, free_content);

    if (!head)
        printf("Lista original limpiada correctamente.\n");

    return (0);
}
