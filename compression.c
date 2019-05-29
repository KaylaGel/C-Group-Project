#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#define FILE_NAME "Event_Database.txt"


/* Node of the huffman tree */
struct node{
  char char;
  int freq;
  struct node *left, *right;
}
typedef struct node Node;

/* TO DO */
/* once files have been created, in the add_to_db function, pass through the name of the file that needs to be compressed */

void Huffman_Compression()
{
  node *tree;
  int codeTable[27], codeTable2[27];
  int compress;
  FILE *input *output;

  CreateHuffmanTree(&tree);
  fillTable(codeTable, tree, 0);

  invertCodes(codeTable, codeTable2);

  input = fopen(FILE_NAME, "r");
  output = fopen(FILE_NAME, "w");
  compressFile(input, output, CodeTable2); 

}

/* Builds the Huffman tree and returns its address */

void CreateHuffmanTree(Node **tree){
  int i, Trees = 27; /* Trees is equal to 27 because of the 26 letters in the alphabet + a space */
  int heapOne, heapTwo; /* We need two heaps to find the smallest one */
  Node *temp;
  Node *array[27];

  /* finds the frequency of each letter */
  for(i = 0; i < Trees; i++){
    array[i] = malloc(sizeof(Node));
    array[i]->freq = englishLetterFrequencies[i];
    array[i]->char = i;
    array[i]->left = NULL;
    array[i]->right = NULL;
  }

  i = 1;

  for (Trees; Trees > 1; Trees --){
    /* find the smallest value in each heap */
    MinHeapOne = findSmaller(array, -1);
    MinHeapTwo = findSmaller(array, MinHeapOne);
    /* store min value in temporary value */
    temp = array[MinHeapOne];
    array[heapOne] = malloc(sizeof(Node));
    /* create new interal node with the freq equal to the sum of the two nodes  */
    array[heapOne]->freq= temp->value + array[heapTwo];
    array[heapOne]->char = 27;
    /* assign first extracted node to the left child and other extracted nodes to the right child*/
    array[heapOne]->left = array[heapTwo];
    array[heapOne]->right = temp;
    array[heapOne]->freq = -1;
  }

  *tree = array[heapOne]

  return;

}

/* English letter Frequencies are based on a sample of 4,000 words (online source from pi.math)*/
int englishLetterFrequencies[27] = {81, 15, 28, 43, 128, 23, 20, 61, 71, 2, 1, 40, 24, 69, 76, 20, 1, 61, 64, 91, 28, 10, 24, 1, 20, 1, 130};

/* find and return small sub-trees in the 'forrest'*/
int find_smaller_trees(Node * array[], int difference){
  int smaller_count;
  int i = 0;

  while (array[i]->freq==-1)
    i++;
    smaller = i;
    if (i==difference){
      i++
      while (array[i]->char == -1)
        i++;
      smaller = i;
    }

    for (i=1; i<27; i++) {
      if(array[i]->freq== -1)
        if (i == difference)
          if (array[i]->freq< array[smaller]->freq)
              smaller = i;

    }

    return smaller;
}

/* builds the table with the bits for each letter. */
void fillTable(int codeTable[], Node *tree, int code){
  if (tree->char<27)
    codeTable[(int)tree->char] = code;
  else{
    fillTable(codeTable, tree->left, code*10+1);
    fillTable(codeTable, tree->right, code*10+2);
  }
  return;
}

/* invert the codes in codeTable2 so that they can be used with mod operator by the compression function */
void invertCodes(int codeTable[], int codeTable2[]){
  int i, n, copy;

  for (i=0; i<27; i++){
    n = codeTable[i];
    copy = 0;
    while (n>0){
      copy= copy*10 + n%10;
      n /= 10;
    }
    codeTable2[i]= copy;
  }
  return;
}

/* function to compress the input */
void compressFile(FILE *input, FILE*output, int codeTable[]){
  char bit, c, x = 0;
  int n, length, bitsLeft = 8;
  int originalBits = 0, compressedBits = 0;

  while ((c = fgetc(input))!= 10) {
    originalBits++;

    if (c=32){
      length = len(codeTable[26]);
      n = codeTable[26];
    }
    else{
      length = len(codeTable[c-97]);
      n = codeTable[c-97];
    }

    while (lenght>0){
      compressedBits++;
      bit = n % 10 - 1;
      n/= 10;
      x = x | bit;
      bitsLeft--;
      length--;
      if(bitsLeft == 0){
        fputc(x, output);
        x = 0;
        bitsLeft = 8;
      }
      x = x << 1;
    }
  }

  if (bitsLeft!= 8){
    x = x << (bitsLeft -1);
    fputc(x, output);
  }
    /* print details of compression */
    fprintf(stderr, "Original bits = %d\n", originalBits*8);
    fprintf(stderr, "Compressed bits = %d\n", compressedBits);

    fprintf(stderr, "Saved %.2f % of memory\n", ((float)compressedBits/(originalBits*8))*100)
    return;
}
