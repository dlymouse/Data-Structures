#  广义表

### 广义表的构建

1. 广义表头尾链表存储结构类型

``` c
typedef struct GLnode {
    ElemTag tag; // 表示当前节点的类型（原子 or 子表）

    union {
        int atom; // 如果是原子，存储 int 数值
        struct {
            struct GLnode* hp; // 表头指针
            struct GLnode* tp; // 表尾指针
        } htp; // 如果是子表，存储表头和表尾两个指针
    } atom_htp;
} GLNode, *GList;

```

2. 求广义表的长度

``` c
int length(GList L) {
    int k = 0; 
    GLNode* s;
    if(L == NULL) return 0;
    else if(L->tag == ATOM) exit 0;
    s = L;
    while(s != NULL) {
        k++;
        s = s->atom_htp.htp.tp;
    }
    return k;
}
```

3. 求广义表的深度

``` c
int Depth(GList L) {
    int d = 0, max = 0;
    GLNode* s;
    if(L == NULL) return 1;
    if(L->tag == ATOM) return 0;
    s = L;
    while(S != NULL) {
        d = Depth(s->atom_htp.htp.hp);
        if(d > max) max = d;
        s = s->atom_htp.htp.tp;
    }
    return max + 1;
}
```

4. 求广义表的原子结点个数

``` c
int CountAtom(GList L) {
    int n1 = 0, n2 = 0;
    if(L == NULL) return 0;
    else if(L->tag == ATOM) return 1;
    else {
        n1 = CountAtom(s->atom_htp.htp.hp);
        n2 = CountAtom(s->atom_htp.htp.tp);
    }
    return n1 + n2;
}
```

5. 复制广义表

``` c
void CopyGList(GList L, GList* T) {
    if(L == NULL) {*T = NULL;return;}
    *T = (GLNode* )malloc(sizeof(GLNode));
    (*T)->tag = L->tag;
    if(L->tag == ATOM) (*T)->atom = L->atom;
    else {
        CopyGList(L->atom_htp.htp.hp, (*T)->atom_htp.htp.hp);
        CopyGList(L->atom_htp.htp.tp, (*T)->atom_htp.htp.tp);
    }
}
```