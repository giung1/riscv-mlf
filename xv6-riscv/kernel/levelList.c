#include "levelList.h"
#include <stdio.h>
#include "proc.h"
  void insertNode(struct level *level, struct proc proc){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->proc = proc;  //preguntar
    newNode->next = NULL;
    if(level->size == 0){
        level->head = newNode;
        level->last = newNode;
    } else{
        level->last->next = newNode;
        level->last = newNode;
    }
    level->size++;
  }

  struct proc* levelPop(struct level *level){
    struct proc *procToReturn;
    struct node *aux;
    procToReturn = &(level->head)->proc;
    aux= level->head;
    level->head = aux->next;
    return procToReturn;
  }