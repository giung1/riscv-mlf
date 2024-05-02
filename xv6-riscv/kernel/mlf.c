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

  void enqueueMlf( struct mlf *mlf, struct proc proc, int level){
    struct proc *p = proc;
    if ( p->state != RUNNABLE ){
      panic();
    } else {
      acquire(&p->lock);
      enqueue( mlf[level-1], proc);
    }
  }

  struct proc* dequeuMlf(struct mlf *mlf){
    struct proc *procToReturn;
    for (int i = 0; i < 4; i++)
    {
      if( mlf[i+1].size != 0 ){
        procToReturn = dequeue(mlf[i+1]);
        return procToReturn;
      }
    }
  }