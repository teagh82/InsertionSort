#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// ���� �Լ��� �̿��Ͽ� int �迭�� 0~max-1�� ������ �������� ä��� �Լ�
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// �迭�� ȭ�鿡 ���� ���� ����ϴ� �Լ�. ����Ʈ �Ű����� ���
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

static void printStep( int arr[], int n, int c )
{
    printf("Step        %d = ", c);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

void copyArray(int from[], int to[], int n)
{
	for(int i = 0; i < n; i++)
		to[i] = from[i];
}

int arr[9];
int before[9];
int temp = 0;
int s;
void insertionSort (int A[], int n)
{
    for(int i=1; i<n; i++){
		int count = 0;
        int key = A[i];
        int j;
		int bArr[9];
		copyArray(A, bArr, n);
		for(j=i-1 ; j>=0 && A[j] > key ;j--){
			A[j+1] = A[j]; // ���ڵ��� ������ �̵�
			count++;
		}
           
        A[j+1] = key;
		printStep(A, n, i);
		

		if(count > temp){
			temp = count;
			s = i;
			copyArray(A, arr, n);
			copyArray(bArr, before, n);
		}			
	}
}

void main()
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	printArray( list, 9, "Original Data" );	// ���� �� �迭 ��� 
	insertionSort( list, 9 ); 		// ���� ���� ���� 
	printArray( list, 9, "Sorted Data  " );	// ���� �� �迭 ��� 

	printf("---------------------------------------------------\n");
	printf("�迭 �̵��� ���� ���� �Ͼ�� Step��?  Step %d(%d ȸ �̵�)\n",s ,temp);
	printStep(before,9,s-1);
	printStep(arr,9,s);
	printf("---------------------------------------------------\n");

	system("pause");
}