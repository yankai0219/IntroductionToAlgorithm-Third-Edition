#include "binomial_heap.h" 

int kp1[8] = {12, 
               7, 25, 
              15, 28, 33, 41};
 
int kp2[20] = {18,
                3, 37,
                6, 8, 29, 10, 44, 30, 23, 2, 48, 31, 17, 45, 32, 24, 50, 55};
 
int kp4[23] = {37, 41,
               10, 28, 13, 77,
               1, 6, 16, 12, 25, 8, 14, 29, 26, 23, 18, 11, 17, 38, 42, 27};
int main() {
    BinHeap H1 = NULL;
    H1 = MakeBinHeapWithArray(kp1, 7);
    puts("第一个二叉堆H1:");
    PrintBinHeap(H1);
 
    BinHeap H2 = NULL;
    H2 = MakeBinHeapWithArray(kp2, 19);
    puts("\n\n第二个二叉堆H2:");
    PrintBinHeap(H2);
 
    BinHeap H3 = NULL;
    H3 = BinHeapUnion(H1, H2);
    puts("\n\n合并H1,H2后，得到H3:");
    PrintBinHeap(H3);
 
    BinHeap H4 = NULL;
    H4 = MakeBinHeapWithArray(kp4, 22);
    puts("\n\n用于测试提取和删除的二叉堆H4:");
    PrintBinHeap(H4);
 
    BinHeap extractNode = BinHeapExtractMin(H4);
    if (extractNode != NULL) {
        printf("\n\n抽取最小的值%d后：\n", extractNode->key);
        PrintBinHeap(H4);
    }
 
    extractNode = BinHeapExtractMin(H4);
    if (extractNode != NULL) {
        printf("\n\n抽取最小的值%d后：\n", extractNode->key);
        PrintBinHeap(H4);
    }
 
    extractNode = BinHeapExtractMin(H4);
    if (extractNode != NULL) {
        printf("\n\n抽取最小的值%d后：\n", extractNode->key);
        PrintBinHeap(H4);
    }
 
    BinHeapDelete(H4, 12);
    puts("\n\n删除12后：");
    PrintBinHeap(H4);
    return 0;
}
