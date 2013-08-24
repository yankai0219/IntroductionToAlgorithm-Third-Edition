/*
* Author:http://mindlee.net/2011/09/26/binomial-heaps/
* Date: 2013/08/11
*/

#ifndef _BINOMIAL_HEAP_H_
#define _BINOMIAL_HEAP_H_

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
using namespace std;
 
typedef struct BinHeapNode BinNode;
typedef struct BinHeapNode * BinHeap;
typedef struct BinHeapNode * Position;
 
//结点ADT
struct BinHeapNode {
    int key;
    int degree;
    Position parent;
    Position leftChild;
    Position sibling;
};
 
//用数组内的值建堆
BinHeap MakeBinHeapWithArray(int keys[], int n);
 
//两个堆合并
BinHeap BinHeapUnion(BinHeap &H1, BinHeap &H2);
 
//将H1, H2的根表合并成一个按度数的单调递增次序排列的链表
BinHeap BinHeapMerge(BinHeap &H1, BinHeap &H2);
 
//使H2成为H1的父节点
void BinLink(BinHeap &H1, BinHeap &H2);
 
//返回最小根节点的指针
BinHeap BinHeapMin(BinHeap heap);
 
//减少关键字的值
void BinHeapDecreaseKey(BinHeap heap, BinHeap x, int key);
 
//删除一个关键字
BinHeap BinHeapDelete(BinHeap &heap, int key);
 
//找出一个关键字
BinHeap BinHeapFind(BinHeap &heap, int key);
 
//打印输出堆结构
void PrintBinHeap(BinHeap heap);
 
//销毁堆
void DestroyBinHeap(BinHeap &heap);
//抽取有最小关键字的结点
BinHeap BinHeapExtractMin(BinHeap &heap);


#endif 
 
