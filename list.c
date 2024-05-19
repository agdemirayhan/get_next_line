#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

void print_list(Node *head);
Node *insert_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
int length(Node *head);
int recursive_length(Node *node);
bool is_member(Node *node, int find_value);
int count_matches(Node *node, int find_value);
void replace_matches(Node *node, int find_value, 
                     int replace_value);
Node *delete_first_match(Node *head, int delete_value,
                         bool *was_deleted);
Node *delete_all_matches(Node *head, int delete_value,
                         int *num_deleted);
Node *efficient_delete_match(Node *head, int delete_value,
                             int *num_deleted);
Node *append_list(Node *head1, Node *head2);
Node *reverse_list(Node *head);
void sort_list(Node *head);
void delete_duplicates(Node *head);
Node *insert_after(Node *head, int new_value,
                   int after_value);
Node *delete_list(Node *node);

int main()
{
  Node *list = NULL; 

  list = insert_at_tail(list, 5);
  list = insert_at_tail(list, 9);
  list = insert_at_tail(list, 1);
  list = insert_at_tail(list, 8);
  list = insert_at_tail(list, 4);
  
  printf("List before insert:\n");
  print_list(list);
  list = insert_after(list, 20, 1);
  printf("List after insert:\n");
  print_list(list);

  list = delete_list(list);
  printf("List after delete:\n");
  print_list(list);
  
}


Node *delete_list(Node *node)
{
  if (node != NULL)
  {
    delete_list(node->next);
    free(node);
  }
  return NULL;
}

Node *insert_after(Node *head, int new_value,
                   int after_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  
  if (head == NULL) return new_node; 
  else
  {
    Node *current = head;
    while (current->next != NULL)
    {
      if (current->value == after_value)
      {
        new_node->next = current->next; 
        current->next = new_node;
        return head;
      }
      else current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
  }

}

void delete_duplicates(Node *head)
{
  if (head == NULL) return ;
  if (head->next == NULL) return ;

  Node *current1, *current2, *duplicate; 
  current1 = head; 

  while (current1 != NULL && current1->next != NULL)
  {
    current2 = current1;

    while (current2->next != NULL)
    {
      if (current1->value == current2->next->value)
      {
        duplicate = current2->next; 
        current2->next = current2->next->next;
        free(duplicate);
      }
      else current2 = current2->next;
    }

    current1 = current1->next;
  }

}

void sort_list(Node *head)
{
  if (head == NULL) return ;
  if (head->next == NULL) return ;

  bool swapped = false; 
  do
  {
    swapped = false; 
    Node *current = head; 
    Node *prev = NULL; 

    while (current->next != NULL)
    {
      prev = current;
      current = current->next; 
      if (current != NULL)
      {
        if (current->value < prev->value)
        {
          int temp;
          temp = prev->value;
          prev->value = current->value; 
          current->value = temp;
          swapped = true;
        }
      }      
    }
    
  } while (swapped);

}



Node *reverse_list(Node *head)
{
  if (head == NULL) return NULL; 
  if (head->next == NULL) return head;

  Node *current = head;
  Node *next_node = head->next; 

  current->next = NULL;

  while (next_node != NULL)
  {
    Node *tmp = next_node->next; 
    next_node->next = current; 
    current = next_node;
    next_node = tmp;
  }

  return current;
}



Node *append_list(Node *head1, Node *head2)
{
  if (head1 == NULL) return head2;

  Node *current = head1;
  while (current->next != NULL) current = current->next;
  current->next = head2;
  return head1;
}


Node *efficient_delete_match(Node *head, int delete_value,
                             int *num_deleted)
{
  *num_deleted = 0;
  if (head == NULL) return NULL;

  Node *current, *temp, *new_head;
  current = head;
  while (current->value == delete_value)
  {
    temp = current;
    current = current->next;
    free(temp);
    *num_deleted = *num_deleted + 1;

    if (current == NULL) return NULL;
  }

  new_head = current;

  while (current->next != NULL)
  {
    if (current->next->value == delete_value)
    {
      temp = current->next;
      current->next = current->next->next;
      free(temp);
      *num_deleted = *num_deleted + 1;
    }
    else current = current->next;
  }

  return new_head;
}


Node *delete_all_matches(Node *head, int delete_value,
                         int *num_deleted)
{
  Node *current = head;
  bool deleted = false;
  *num_deleted = 0;

  do 
  {
    current = delete_first_match(current, delete_value, 
                                 &deleted);
    if (deleted) *num_deleted = *num_deleted + 1;
  } while (deleted);

  return current;
}

Node *delete_first_match(Node *head, int delete_value,
                         bool *was_deleted)
{
  if (head == NULL)
  {
    *was_deleted = false;
    return NULL;
  }

  if (head->value == delete_value)
  {
    Node *temp = head->next;
    free(head);
    *was_deleted = true;
    return temp;
  }

  Node *current = head->next;
  Node *prev = head;

  while (current != NULL)
  {

    if (current->value == delete_value)
    {
      prev->next = current->next;
      free(current);
      *was_deleted = true;
      return head;
    }

    prev = current;
    current = current->next;
  }

  *was_deleted = false;
  return head;
}


void replace_matches(Node *node, int find_value, 
                     int replace_value)
{
  if (node != NULL)
  {
    if (node->value == find_value)
      node->value = replace_value;
    
    replace_matches(node->next, find_value, 
                    replace_value);
  }
}


int count_matches(Node *node, int find_value)
{
  if (node == NULL) return 0;
  else if (node->value == find_value)
    return 1 + count_matches(node->next, find_value);
  else return count_matches(node->next, find_value);
}

bool is_member(Node *node, int find_value)
{
  if (node == NULL) return false;
  else if (node->value == find_value) return true;
  else return is_member(node->next, find_value);
}

int recursive_length(Node *node)
{
  if (node == NULL) return 0;
  else return 1 + recursive_length(node->next);
}

int length(Node *head)
{
  Node *current;
  current = head;
  int length = 0;
  while (current != NULL)
  {
    length++;
    current = current->next;
  }
  return length;
}

Node *delete_at_tail(Node *head)
{
  if (head == NULL) return NULL; 
  else if (head->next == NULL)
  {
    free(head);
    return NULL;
  }
  else 
  {
    Node *current = head;
    Node *prev = NULL;

    while (current->next != NULL)
    {
      prev = current;
      current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
  }
}

Node *delete_at_head(Node *head)
{
  if (head == NULL) return NULL;
  else 
  {
    Node *to_return = head->next;
    free(head);
    return to_return;
  }
}


Node *insert_at_tail(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  if (head == NULL) return new_node;
  else 
  {
    Node *current = head;
    while (current->next != NULL) current = current->next;
    current->next = new_node;
    return head;
  }  
}

Node *insert_at_head(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  if (head == NULL) return new_node;
  else 
  {
    new_node->next = head;
    return new_node;
  }
}

void print_list(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  while (current != NULL)
  {
    printf("Node %d: %d\n", i, current->value);
    i++;
    current = current->next;
  }
}
