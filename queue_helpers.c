/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:17:55 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 04:18:21 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_queue	*create_queue(void)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	q->front = q->rear = NULL;
	return (q);
}

void	enqueue(t_queue *q, t_point point)
{
	t_queue_node	*temp;

	temp = (t_queue_node *)malloc(sizeof(t_queue_node));
	temp->point = point;
	temp->next = NULL;
	if (q->rear == NULL)
	{
		q->front = q->rear = temp;
		return ;
	}
	q->rear->next = temp;
	q->rear = temp;
}

t_point	dequeue(t_queue *q)
{
	t_queue_node	*temp;
	t_point			point;

	if (q->front == NULL)
		return ((t_point){-1, -1});
	temp = q->front;
	point = temp->point;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
	return (point);
}
