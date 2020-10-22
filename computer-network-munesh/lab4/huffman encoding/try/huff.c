// C program for Huffman Coding
#include <stdio.h>
#include <stdlib.h>

// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HT 100

struct chart{
		char a;
		int f[10];
};
struct chart ask[26];
int k=0;
// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child of this node
	struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of
// min-heap (or Huffman tree) nodes
struct MinHeap {

	// Current size of min heap
	unsigned size;

	// capacity of min heap
	unsigned capacity;

	// Array of minheap node pointers
	struct MinHeapNode** array;
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq)
{
	struct MinHeapNode* temp
		= (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}

// A utility function to create
// a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)

{

	struct MinHeap* minHeap
		= (struct MinHeap*)malloc(sizeof(struct MinHeap));

	// current size is 0
	minHeap->size = 0;

	minHeap->capacity = capacity;

	minHeap->array
		= (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

// A utility function to
// swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,
					struct MinHeapNode** b)

{

	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)

{

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

// A utility function to check
// if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{

	return (minHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0]
		= minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}

// A utility function to insert
// a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap,
				struct MinHeapNode* minHeapNode)

{

	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minHeap->array[i] = minHeapNode;
}

// A standard function to build min heap
void buildMinHeap(struct MinHeap* minHeap)

{

	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
	int i,p=0;
	for (i = 0; i < n; ++i){
		printf("%d", arr[i]);

		ask[k].f[i]=arr[i];
		p++;
	}
	k++;
	printf("\n");
}

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)

{

	return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)

{

	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)

{
	struct MinHeapNode *left, *right, *top;

	// Step 1: Create a min heap of capacity
	// equal to size. Initially, there are
	// modes equal to size.
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	// Iterate while size of heap doesn't become 1
	while (!isSizeOne(minHeap)) {

		// Step 2: Extract the two minimum
		// freq items from min heap
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		// Step 3: Create a new internal
		// node with frequency equal to the
		// sum of the two nodes frequencies.
		// Make the two extracted node as
		// left and right children of this new node.
		// Add this node to the min heap
		// '$' is a special value for internal nodes, not used
		top = newNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}

	// Step 4: The remaining node is the
	// root node and the tree is complete.
	return extractMin(minHeap);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(struct MinHeapNode* root, int arr[], int top)

{

	// Assign 0 to left edge and recur
	if (root->left) {

		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	// Assign 1 to right edge and recur
	if (root->right) {

		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	// If this is a leaf node, then
	// it contains one of the input
	// characters, print the character
	// and its code from arr[]
	if (isLeaf(root)) {

		printf("%c: ", root->data);
		ask[k].a=root->data;
		printArr(arr, top);
	}
}

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)

{
	// Construct Huffman Tree
	struct MinHeapNode* root
		= buildHuffmanTree(data, freq, size);

	// Print Huffman codes using
	// the Huffman tree built above
	int arr[MAX_TREE_HT], top = 0;

	printCodes(root, arr, top);
}

// Driver program to test above functions
int main()
{

	//////////////////////////////////
		char c[1000],ec[100];
    FILE *fptr;
    if ((fptr = fopen("msg.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    fscanf(fptr,"%[^\n]",c);
    printf("Data from the file:\n%s", c);
    fclose(fptr);
	//////////////////////////////////
   int i = 0, count[26] = {0}, x;

   while (c[i] != '\0') {
   /** Considering characters from 'a' to 'z' only and ignoring others. */

      if (c[i] >= 'a' && c[i] <= 'z') {
         x = c[i] - 'a';
         count[x]++;
      }

      i++;
   }

				 int size = i;

				 char arr[i];
				 int freq[i];
int k=0;
	for (int j = 0; j < 26 ; j++){
		    if(count[j]>0){
					arr[k] = j+'a';
					freq[k] = count[j];
					k++;
				}
			 }

			 for (int i = 0; i < size; i++) {
			 	printf("%c - %d \n",arr[i],freq[i]);
			 }


	//encode(c,ec,arr,freq,size);
	for (int i = 0; i < 26; i++) {
			ask[i].a='%';
		for(int j=0;j<10;j++){
			ask[i].f[j]=5;
		}}
printf("**\n");
	HuffmanCodes(c,count, size);
	for (int i = 0; i < 26 && ask[i].a!='%'; i++) {
			printf("%c",ask[i].a);
	 	for(int j=0;j<10 && ask[i].f[j]!=5;j++){
			printf("%d",ask[i].f[j]);
		}
	}printf("\n");
///////////////////////////////////
   FILE * fp;
   /* open the file for writing*/
   fp = fopen ("encoded.txt","w");
	int j = 0;
	while(c[j]!='\0')
	{
		for(int k=0;k<26;k++)
		{
			if(c[j]==ask[k].a)
			{
				for(int l=0;l<10 && ask[k].f[l]!=5;l++)
				{
					fprintf(fp,"%d",ask[k].f[l]);
				}
			}
		}
		j++;
	}
	fprintf(fp,"\n");
fprintf(fp,"\n");
	for (i = 0; i < 26 && c[i]>0 ; i++)
         fprintf(fp,"%c %d\n", i + 'a', count[i]);
 fprintf(fp,"\n");
   for (int i = 0; i < 26 && ask[i].a!='%'; i++) {
			fprintf(fp,"%c",ask[i].a);
			fprintf(fp," ");
	 	for(int j=0;j<10 && ask[i].f[j]!=5;j++){
			fprintf(fp,"%d",ask[i].f[j]);
		}
			fprintf(fp,"\n");
	}
 
   /* close the file*/  
   fclose (fp);


			//	ec[y]=(char)(ask[j].f[q]+'0');

	return 0;
}
