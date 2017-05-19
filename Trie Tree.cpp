/*
Trie树的基本性质可以归纳为： 
（1）根节点不包含字符，除根节点意外每个节点只包含一个字符。
（2）从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。 
（3）每个节点的所有子节点包含的字符串不相同。
Trie树有一些特性：
1）根节点不包含字符，除根节点外每一个节点都只包含一个字符。
2）从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
3）每个节点的所有子节点包含的字符都不相同。
4）如果字符的种数为n，则每个结点的出度为n，这也是空间换时间的体现，浪费了很多的空间。
5）插入查找的复杂度为O(n)，n为字符串长度。
1、插入
  假设存在字符串str，Trie树的根结点为root。i=0，p=root。
  1)取str[i]，判断p->next[str[i]-97]是否为空，若为空，则建立结点temp，并将p->next[str[i]-97]指向temp，然后p指向temp；
   若不为空，则p=p->next[str[i]-97]；
  2)i++，继续取str[i]，循环1)中的操作，直到遇到结束符'\0'，此时将当前结点p中的 exist置为true。
2、查找
  假设要查找的字符串为str，Trie树的根结点为root，i=0，p=root
  1)取str[i]，判断判断p->next[str[i]-97]是否为空，若为空，则返回false；若不为空，则p=p->next[str[i]-97]，继续取字符。
  2)重复1)中的操作直到遇到结束符'\0'，若当前结点p不为空并且 exist 为true，则返回true，否则返回false。
3、删除
  删除可以以递归的形式进行删除。
*/
#include <iostream>  
#include <cstring>  
using namespace std;  
  
typedef struct Trie_node  {  
    int count;                    // 统计单词前缀出现的次数  
    struct Trie_node* next[26];   // 指向各个子树的指针  
    bool exist;                   // 标记该结点处是否构成单词    
}TrieNode , *Trie;  
  
TrieNode* createTrieNode()  {  
    TrieNode* node = (TrieNode *)malloc(sizeof(TrieNode));  
    node->count = 0;  
    node->exist = false;  
    memset(node->next , 0 , sizeof(node->next));    // 初始化为空指针  
    return node;  
}  
  
void Trie_insert(Trie root, char* word)  {  
    Trie node = root;  
    char *p = word;  
    int id;  
    while( *p )  
    {  
        id = *p - 'a';  
        if(node->next[id] == NULL)  
        {  
            node->next[id] = createTrieNode();  
        }  
        node = node->next[id];  // 每插入一步，相当于有一个新串经过，指针向下移动  
        ++p;  
        node->count += 1;      // 这行代码用于统计每个单词前缀出现的次数（也包括统计每个单词出现的次数）  
    }  
    node->exist = true;        // 单词结束的地方标记此处可以构成一个单词  
}  
  
int Trie_search(Trie root, char* word){  
    Trie node = root;  
    char *p = word;  
    int id;  
    while( *p )  
    {  
        id = *p - 'a';  
        node = node->next[id];  
        ++p;  
        if(node == NULL)  
            return 0;  
    }  
    return node->count;  
}  
  
int main(void)  
{  
    Trie root = createTrieNode();     // 初始化字典树的根节点  
    char str[12] ;  
    bool flag = false;  
    while(gets(str)){  
        if(flag)  
            printf("%d\n",Trie_search(root , str));  
        else{  
            if(strlen(str) != 0)  
                Trie_insert(root , str); 
            else  
                flag = true;  
        }  
    }  
    return 0;  
} 
