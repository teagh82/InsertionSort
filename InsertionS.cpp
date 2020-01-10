#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// 랜덤 함수를 이용하여 int 배열을 0~max-1의 값으로 무작위로 채우는 함수
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// 배열을 화면에 보기 좋게 출력하는 함수. 디폴트 매개변수 사용
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
			A[j+1] = A[j]; // 레코드의 오른쪽 이동
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
	printArray( list, 9, "Original Data" );	// 정렬 전 배열 출력 
	insertionSort( list, 9 ); 		// 삽입 정렬 실행 
	printArray( list, 9, "Sorted Data  " );	// 정렬 후 배열 출력 

	printf("---------------------------------------------------\n");
	printf("배열 이동이 가장 많이 일어나는 Step은?  Step %d(%d 회 이동)\n",s ,temp);
	printStep(before,9,s-1);
	printStep(arr,9,s);
	printf("---------------------------------------------------\n");

	system("pause");
}