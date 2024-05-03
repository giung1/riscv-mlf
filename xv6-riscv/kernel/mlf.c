#include <stdio.h>
#include "mlf.h"
#include "proc.h"

  void enqueue(struct queue *queue, struct proc *proc)
  {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->proc = proc;  
    newNode->next = NULL;
    if(!queue->head){
        queue->head = newNode;
        queue->last = newNode;
    } else{
        queue->last->next = newNode;
        queue->last = newNode;
    }
  }

  struct proc* dequeue(struct queue *queue)
  {
    struct proc *procToReturn;
    struct node *aux;
    procToReturn = &(queue->head)->proc;
    aux= queue->head;
    queue->head = aux->next;
    return procToReturn;
  }

  void enqueueMlf(struct mlf *mlf, struct proc *proc)
  {
    struct proc *p = proc;   
    if ( p->state != RUNNABLE ){
      panic("Process must be runnable");
    } else {
      enqueue( &mlf->levels[p->level], proc);
      release(&p->lock);
    }
  }

  struct proc* dequeueMlf(struct mlf *mlf)
  {
    struct proc *procToReturn;
    for (int i = 1; i <= 4; i++)
    {
      if(&mlf->levels[i]){
        acquire(&mlf->levels[i].lock);  
        procToReturn = dequeue(&mlf->levels[i]);
        acquire(&procToReturn->lock);
        release(&mlf->levels[i].lock);
        return procToReturn;
      }
    }
    return NULL;
  }
  
  