/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_unix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 01:32:15 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/22 02:18:46 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UNIX_H
# define LIST_UNIX_H

typedef struct s_list_head	t_list_head;

struct					s_list_head
{
	t_list_head		*next;
	t_list_head		*prev;
};

# define OFFSETOF(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

# define CONTAINER_OF(ptr, type, member) ({ \
		const typeof( ((type *)0)->member ) *__mptr = (ptr); \
		(type *)( (char *)__mptr - OFFSETOF(type,member) );})

# define LIST_ENTRY(ptr, type, member) \
		CONTAINER_OF(ptr, type, member)

# define LIST_FIRST_ENTRY(ptr, type, member) \
		LIST_ENTRY((ptr)->next, type, member)

# define LIST_LAST_ENTRY(ptr, type, member) \
		LIST_ENTRY((ptr)->prev, type, member)

# define LIST_NEXT_ENTRY(pos, member) \
			LIST_ENTRY((pos)->member.next, typeof(*(pos)), member)

# define LIST_PREV_ENTRY(pos, member) \
			LIST_ENTRY((pos)->member.prev, typeof(*(pos)), member)

# define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

#endif
