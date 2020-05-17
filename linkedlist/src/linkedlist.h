#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void(*FreeFunc)(void*);

typedef int(*CmpFunc)(const void*, const void*);

typedef void(*PrintFunc)(const void*);

struct LLNode {
    void* data_ptr;
    struct LLNode* next;
};

typedef struct {
    size_t data_size;
    size_t size;
    FreeFunc free_func;
    struct LLNode* head;
} LinkedList;

/*
 * Construction.
 */

LinkedList* linkedlist_create(LinkedList* ll, size_t data_size, FreeFunc);

/*
 * Destruction.
 */

void linkedlist_free(LinkedList*);

/*
 * Size.
 */

static inline size_t linkedlist_size(const LinkedList* ll)
{
    return ll->size;
}

/*
 * Sizeof.
 */

static inline size_t linkedlist_sizeof(const LinkedList* ll)
{
    return sizeof(LinkedList) + linkedlist_size(ll) * sizeof(struct LLNode);
}

/*
 * Emptiness.
 */

static inline bool linkedlist_is_empty(const LinkedList* ll)
{
    return ll->head == NULL;
}

/*
 * Indexing.
 */

void* linkedlist_get(const LinkedList* ll, size_t pos);

void linkedlist_set(const LinkedList* ll, size_t pos, const void* data_ptr);

/*
 * Insertion.
 */

void linkedlist_push_back(LinkedList* ll, const void* data_ptr);

void linkedlist_push_front(LinkedList* ll, const void* data_ptr);

void linkedlist_insert(LinkedList* ll, size_t pos, const void* data_ptr);

/*
 * Removal.
 */

void* linkedlist_pop_back(LinkedList* ll);

void* linkedlist_pop_front(LinkedList* ll);

void linkedlist_erase(LinkedList* ll, size_t pos);

/*
 * Printing.
 */

void linkedlist_print(const LinkedList* ll, PrintFunc);

#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */
