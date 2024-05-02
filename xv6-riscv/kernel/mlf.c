#include "mlf.h"
#include <stdio.h>
#include "proc.h"
  void enqueue(struct queue *queue, struct proc proc){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->proc = proc;  //preguntar
    newNode->next = NULL;
    if(queue->size == 0){
        queue->head = newNode;
        queue->last = newNode;
    } else{
        queue->last->next = newNode;
        queue->last = newNode;
    }
    queue->size++;
  }

  struct proc* dequeue(struct queue *queue){
    struct proc *procToReturn;
    struct node *aux;
    procToReturn = &(queue->head)->proc;
    aux= queue->head;
    queue->head = aux->next;
    return procToReturn;
  }