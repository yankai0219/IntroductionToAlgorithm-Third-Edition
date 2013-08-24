

/*
* Author:http://mindlee.net/2011/09/29/fibonacci-heaps/
* Date: 2013/08/11
*/

/*
The keyNum = 10
 (1)  (11)  (10)  (9)  (7)  (6)  (5)  (4)  (3)  (2)
 
抽取最小值1之后：
The keyNum = 9
 (2 (3)  (6 (7)  (9 (10) ) )  (4 (5) ) )  (11)
 
查找11成功,减小到8后：
The keyNum = 9
 (2 (3)  (6 (7)  (9 (10) ) )  (4 (5) ) )  (8)
 
删除7成功:
The keyNum = 8
 (2 (3)  (6 (9 (10) ) )  (4 (5) ) )  (8)
 
*/
//说明：
//代码中Fibonacci Heap 用变量heap表示
//结点通常用x，y等表示


#ifndef _FIBONACCI_H_
#define _FIBONACCI_H_

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include <cstring>
using namespace std;
 
//斐波那契结点ADT
struct FibonacciHeapNode {
    int key;       //结点
    int degree;    //度
    FibonacciHeapNode * left;  //左兄弟
    FibonacciHeapNode * right; //右兄弟
    FibonacciHeapNode * parent; //父结点
    FibonacciHeapNode * child;  //第一个孩子结点
    bool marked;           //是否被删除第1个孩子
};
 
typedef FibonacciHeapNode FibNode;
 
//斐波那契堆ADT
struct FibonacciHeap {
    int keyNum;   //堆中结点个数
    FibonacciHeapNode * min;//最小堆，根结点
    int maxNumOfDegree;   //最大度
    FibonacciHeapNode * * cons;//指向最大度的内存区域
};
 
typedef FibonacciHeap FibHeap;
 
 
/*****************函数申明*************************/
//将x从双链表移除
inline void FibNodeRemove(FibNode * x);
 
//将x堆结点加入y结点之前(循环链表中)
void FibNodeAdd(FibNode * x, FibNode * y);
 
//初始化一个空的Fibonacci Heap
FibHeap * FibHeapMake() ;
 
//初始化结点x
FibNode * FibHeapNodeMake();
 
//堆结点x插入fibonacci heap中
void FibHeapInsert(FibHeap * heap, FibNode * x);
 
//将数组内的值插入Fibonacci Heap
void FibHeapInsertKeys(FibHeap * heap, int keys[], int keyNum);
 
//将值插入Fibonacci Heap
void FibHeapInsertKey(FibHeap * heap, int key);
 
//抽取最小结点
FibNode * FibHeapExtractMin(FibHeap * heap);
 
//合并左右相同度数的二项树
void FibHeapConsolidate(FibHeap * heap);
 
//将x根结点链接到y根结点
void FibHeapLink(FibHeap * heap, FibNode * x, FibNode *y);
 
//开辟FibHeapConsolidate函数哈希所用空间
 void FibHeapConsMake(FibHeap * heap);
 
//将堆的最小结点移出，并指向其有兄弟
 FibNode *FibHeapMinRemove(FibHeap * heap);
 
//减小一个关键字
void FibHeapDecrease(FibHeap * heap, FibNode * x, int key);
 
//切断x与父节点y之间的链接，使x成为一个根
 void FibHeapCut(FibHeap * heap, FibNode * x, FibNode * y);
 
//级联剪切
 void FibHeapCascadingCut(FibHeap * heap, FibNode * y);
 
//修改度数
void renewDegree(FibNode * parent, int degree);
 
//删除结点
void FibHeapDelete(FibHeap * heap, FibNode * x);
 
//堆内搜索关键字
FibNode * FibHeapSearch(FibHeap * heap, int key);
 
//被FibHeapSearch调用
FibNode * FibNodeSearch(FibNode * x, int key);
 
//销毁堆
void FibHeapDestory(FibHeap * heap);
 
//被FibHeapDestory调用
void FibNodeDestory(FibNode * x);
 
//输出打印堆
void FibHeapPrint(FibHeap * heap);
 
//被FibHeapPrint调用
 void FibNodePrint(FibNode * x);

#endif

