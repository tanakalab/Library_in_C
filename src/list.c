/* list.c */

#include <list.h>

/********** for unsigned ***********/
bool list_unsigned_member(list_unsigned* L, unsigned u) {
  list_unsigned_cell* x;
  for (x = L->head; NULL != x; x = x->next) {
    if (x->key == u) { return true; }
  }
  return false;
}

void list_unsigned_remove_head(list_unsigned* L) {
  list_unsigned_delete_sub(L, L->head);
}

bool list_unsigned_is_empty(list_unsigned* L) { return (L->size == 0); }

list_unsigned_cell* list_unsigned_search(list_unsigned* L, unsigned u) {
  list_unsigned_cell* x = L->head;
  while (NULL != x && x->key != u) { x = x->next; }
  return x;
}

void list_unsigned_insert(list_unsigned* L, unsigned u) {
  list_unsigned_cell* new = (list_unsigned_cell*)malloc(sizeof(list_unsigned_cell));
  L->size = L->size + 1;
  new->key = u;
  list_unsigned_insert_sub(L,new);
}

void list_unsigned_insert_sub(list_unsigned* L, list_unsigned_cell* x) {
  x->next = L->head;
  if (NULL != L->head) { L->head->prev = x; }
  else { L->last = x; }
  L->head = x;
  x->prev = NULL;
}

void list_unsigned_insert_b(list_unsigned* L, unsigned u) {
  list_unsigned_cell* new = (list_unsigned_cell*)malloc(sizeof(list_unsigned_cell));
  L->size = L->size + 1;
  new->key = u;
  list_unsigned_insert_b_sub(L,new);
}

void list_unsigned_insert_b_sub(list_unsigned* L, list_unsigned_cell* x) {
  x->prev = L->last;
  /* L is empty */
  if (NULL != L->last) { L->last->next = x; }
  else { L->head = x; }
  L->last = x;
  x->next = NULL;
}

void list_unsigned_delete(list_unsigned* L, unsigned u) {
  list_unsigned_cell* x = list_unsigned_search(L, u);
  if (NULL != x) { list_unsigned_delete_sub(L, x); }
}

void list_unsigned_delete_sub(list_unsigned* L, list_unsigned_cell* x) {
  L->size = L->size-1;
  if (NULL != x->prev) { x->prev->next = x->next; }
  else { L->head = x->next; }
  if (NULL != x->next) { x->next->prev = x->prev; }
  else { L->last = x->prev; }
  free(x);
}

list_unsigned* list_unsigneds_concat(list_unsigned* L1, list_unsigned* L2) {
  if (NULL == L1) { return L2; }
  L1->last->next = L2->head;
  if (NULL != L2) { L2->head->prev = L1->last; }
  L1->size = L1->size + L2->size;
  return L1;
}

void list_unsigned_clear(list_unsigned* L) {
  list_unsigned_cell* p, *q;
  for (p = L->head; NULL != p; ) {
    q = p;
    p = p->next;
    free(q);
  }
}

void show_list_unsigned(list_unsigned* L) {
  list_unsigned_cell* p;
  for (p = L->head; NULL != p; p = p->next) { printf("%u\n", p->key); }
}



/********** for unsigned pair ***********/
void list_pair_unsigned_remove_head(list_pair_unsigned* L) {
  list_pair_unsigned_delete_sub(L, L->head);
}

pair_unsigned list_pair_unsigned_head(list_pair_unsigned* L) {
  list_pair_unsigned_cell* h = L->head;
  pair_unsigned p = { h->first, h->second };

  return p;
}

bool list_pair_unsigned_is_empty(list_pair_unsigned* L) { return (L->size == 0); }

list_pair_unsigned_cell* list_pair_unsigned_search(list_pair_unsigned* L, unsigned f, unsigned s) {
  list_pair_unsigned_cell* x = L->head;
  while (NULL != x && x->first != f && x->second != s) { x = x->next; }
  return x;
}

void list_pair_unsigned_insert(list_pair_unsigned* L, unsigned f, unsigned s) {
  list_pair_unsigned_cell* new = (list_pair_unsigned_cell*)malloc(sizeof(list_pair_unsigned_cell));
  L->size = L->size + 1;
  new->first = f;
  new->second = s;
  list_pair_unsigned_insert_sub(L,new);
}

void list_pair_unsigned_insert_sub(list_pair_unsigned* L, list_pair_unsigned_cell* x) {
  x->next = L->head;
  if (NULL != L->head) { L->head->prev = x; }
  else { L->last = x; }
  L->head = x;
  x->prev = NULL;
}

void list_pair_unsigned_delete(list_pair_unsigned* L, unsigned f, unsigned s) {
  list_pair_unsigned_cell* x = list_pair_unsigned_search(L, f, s);
  if (NULL != x) { list_pair_unsigned_delete_sub(L, x); }
}

void list_pair_unsigned_delete_sub(list_pair_unsigned* L, list_pair_unsigned_cell* x) {
  L->size = L->size - 1;
  if (NULL != x->prev) { x->prev->next = x->next; }
  else { L->head = x->next; }
  if (NULL != x->next) { x->next->prev = x->prev; }
  else { L->last = x->prev; }
}

list_pair_unsigned* list_pair_unsigneds_concat(list_pair_unsigned* L1, list_pair_unsigned* L2) {
  if (NULL == L1) { return L2; }
  L1->last->next = L2->head;
  if (NULL != L2) { L2->head->prev = L1->last; }
  L1->size = L1->size + L2->size;
  return L1;
}

void list_pair_unsigned_clear(list_pair_unsigned* L) {
  list_pair_unsigned_cell* p, *q;
  for (p = L->head; NULL != p; ) {
    q = p;
    p = p->next;
    free(q);
  }
}

void show_list_pair_unsigned(list_pair_unsigned* L) {
  list_pair_unsigned_cell* p;
  for (p = L->head; NULL != p; p = p->next) { printf("(%u, %u)\n", p->first, p->second); }
}
