#include <stdio.h>
#define swap(temp, a, b) ((temp)=(a), (a)=(b), (b)=(temp))

int main(void)
{
	int start;
	printf("************************************************************\n");
	printf("         선택 정렬을 해드리는 프로그램 입니다.\n");
	printf("         정렬이 끝난 후 이진탐색이 가능합니다.\n");
	printf("     정렬을 원하신다면 0을 누르고 엔터를 쳐주세요.\n");
	printf("************************************************************\n");
	scanf("%d", &start);
	if (start == 0)
		select_sort();
}

int select_sort(void)
{
	static int array[10];
	int min, count = 0, find_start, input, search_count = 0;
	int i, temp, j, exchange_count = 0, compare_count = 0, total_exchange = 0, total_compare = 0;

	system("cls");
	printf("************************************************************\n");
	printf("         선택 정렬 프로세스가 실행 되었습니다.\n");
	printf("  정렬을 원하시는 숫자를 입력해주세요(10개 까지만 가능)\n");
	printf(" 그만 입력하시고 싶으시다면 9999를 입력해 주시면 됩니다.\n");
	printf("************************************************************\n");

	for (i = 0; i<10; i++)
	{
		printf("%d번째 숫자 : ", i + 1);
		scanf("%d", &array[i]);
		count++;
		if (array[i] == 9999)
		{
			count--;
			break;
		}

	}

	for (j = 0; j<count; j++) {
		min = j;
		for (i = j; i<count; i++)
		{
			if (array[min]>array[i])
				min = i;
			compare_count++;
		}


		if (array[min] != array[j]) {
			swap(temp, array[min], array[j]);
			exchange_count++;
		}
		total_exchange = total_exchange + exchange_count;
		total_compare = total_compare + compare_count;
		printf("\t%dpass : \t", j + 1);

		for (i = 0; i<count; i++) {
			printf("%d ", array[i]);
		}
		printf("\t\t비교 횟수 : %d \t교환 횟수 : %d\n", compare_count, exchange_count);

		exchange_count = 0;
		compare_count = 0;
	}

	printf("\t정렬 완료 : \t");
	for (i = 0; i<count; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\t\t총 비교 횟수 : %d \t교환 횟수 : %d\n", total_compare, total_exchange);

	printf("\n\n이진탐색으로 이동하고 싶다면  0번을 누르고 엔터를 쳐주세요.\n");
	printf("원하지 않으신다면 아무거나 누르시고 엔터를 누르시면 됩니다.\n");
	scanf("%d", &find_start);

	if (find_start == 0)
	{
		search(array, count);
	}
	else
		return 0;

}

int search(int *array, int count)
{
	int input = 0, count_search;
	int high = count - 1;
	int low = 0, mid, i;

	system("cls");
	printf("************************************************************\n");
	printf("            이진탐색  프로세스가 실행 되었습니다.\n");
	printf("             찾기를 원하시는 숫자를 입력해주세요\n");
	printf("************************************************************\n\n");
	
	for(i = 0; i<count/3; i++)
	{
		printf("%d번째 인덱스 값 : %d\t", i, array[i]);
	}
		printf("\n");
	for(i = 3; i<count/3*2; i++)
	{
		printf("%d번째 인덱스 값 : %d\t", i, array[i]);
	}
		printf("\n");
	for(i = 6; i<count; i++)
	{
		printf("%d번째 인덱스 값 : %d\t", i, array[i]);
	}
		printf("\n");
	
	printf("찾기를 원하는 숫자 : ");
	scanf("%d", &input);


	
	while (low <= high) {
		mid = (low + high) / 2;
		if (input == array[mid]){
			printf("%d번째에서 %d 탐색 성공!\t탐색횟수 : %d", mid, array[mid], count_search);
			break;
		}
		
		else if (input < array[mid])
		{
			count_search++;
			high = mid - 1;
		}

		else if (input > array[mid])
		{
			count_search++;
			low = mid + 1;
		}
		else
		{
			mid = -1;
		}
	}
	if(mid == -1){
		printf("ERROR! 찾지 못하였습니다!!");
	}
}
