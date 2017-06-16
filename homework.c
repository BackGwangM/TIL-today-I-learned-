#include <stdio.h>
#define swap(temp, a, b) ((temp)=(a), (a)=(b), (b)=(temp))

int main (void)
{
	int start;
	printf("************************************************************\n");
	printf("         선택 정렬을 해드리는 프로그램 입니다.\n");
	printf("      정렬이 끝난 후 원하는 숫자를 찾아드립니다.\n");
	printf("     정렬을 원하신다면 0을 누르고 엔터를 쳐주세요.\n");
	printf("************************************************************\n");
	scanf("%d",&start);
	if(start == 0) 
		select_sort();
}

int select_sort(void)
{
	static int array[10];
	int min, count = 0, find_start;
	int i, temp, j, exchange_count = 0, compare_count = 0, total_exchange = 0, total_compare = 0;
	
	system("cls");
	printf("************************************************************\n");
	printf("         선택 정렬 프로세스가 실행 되었습니다.\n");
	printf("  정렬을 원하시는 숫자를 입력해주세요(10개 까지만 가능)\n");
	printf(" 그만 입력하시고 싶으시다면 9999를 입력해 주시면 됩니다.\n");
	printf("************************************************************\n");
	
	for(i = 0; i<10; i++)
	{
		printf("%d번째 숫자 : ", i+1);
		scanf("%d", &array[i]);
		count++;
		if(array[i] == 9999)
		{
			count--;
			break;
		}
			
	} 
	
	for(j = 0; j<count; j++){
		min = j;
		for (i = j; i<count; i++)
		{
			if (array[min]>array[i])
				min = i;
				compare_count++;
		}
		
		
		if(array[min] != array[j]){
			swap(temp, array[min], array[j]);
			exchange_count++;
		}
		total_exchange = total_exchange + exchange_count;
		total_compare = total_compare + compare_count;
		printf("\t%dpass : \t",j+1);
		
		for (i = 0; i<count; i++){
			printf("%d ", array[i]);
		}
			printf("\t\t비교 횟수 : %d \t교환 횟수 : %d\n", compare_count, exchange_count );
		
		exchange_count = 0;
		compare_count = 0;
	}
	
	printf("\t정렬 완료 : \t");
	for (i = 0; i<count; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\t\t총 비교 횟수 : %d \t교환 횟수 : %d\n",total_compare ,total_exchange);
	
	printf("\n\n원하는 숫자를 찾고 싶으시다면 0번을 누르고 엔터를 쳐주세요.\n");
	printf("원하지 않으신다면 아무거나 누르시고 엔터를 누르시면 됩니다.\n");
	scanf("%d",&find_start);
	
	
}
