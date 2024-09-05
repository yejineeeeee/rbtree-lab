#ifndef _RBTREE_H_
#define _RBTREE_H_
#define SENTINEL

#include <stddef.h>

// Tree를 구현하기 위한 구조체와 열거형의 정의
typedef enum {RBTREE_RED, RBTREE_BLACK} color_t;

typedef int key_t; // 각 노드에 저장되는 값의 데이터 형식 정의

typedef struct node_t //tree의 각 노드를 표현하는 구조체
{
  color_t color;
  key_t key; //노드가 저장하는 값
  struct node_t *parent, *left, *right; //부모, 왼쪽, 오른쪽자식 가리키는 포인터
} node_t;

typedef struct //tree 자체를 나타내는 구조체
{
  node_t *root; //루트 노드
  node_t *nil; //nil 노드
} rbtree;

rbtree *new_rbtree(void);
void delete_rbtree(rbtree *);

// 추가된 함수 선언
void free_node(rbtree *t, node_t *node);
void rbtree_insert_fixup(rbtree *t, node_t *node);

node_t *rbtree_insert(rbtree *, const key_t);
node_t *rbtree_find(const rbtree *, const key_t);
node_t *rbtree_min(const rbtree *);
node_t *rbtree_max(const rbtree *);
int rbtree_erase(rbtree *, node_t *);

int rbtree_to_array(const rbtree *, key_t *, const size_t);

#endif  // _RBTREE_H_
