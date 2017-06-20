#include <stdio.h>
#include <conio.h>
#define change(temp, a, b) ((temp)=(a), (a)=(b), (b)=(temp))

int main(void)
{
	printf("************************************************************\n");
	printf("         선택 정렬을 해드리는 프로그램 입니다.\n");
	printf("         정렬이 끝난 후 이진탐색이 가능합니다.\n");
	printf("        정렬을 원하신다면 아무거나 입력해주세요.\n");
	printf("************************************************************\n");
	getch();
	select_sort();
}

int select_sort(void)
{
	int array[10];
	int min, count = 0;
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

			change(temp, array[min], array[j]);
			exchange_count++;
			
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

	if (array[0] == 9999)
	{
		system("cls");
		printf("아무것도 쓰지 않고 그냥 꺼버린 그대여...\n");
		printf("천벌을 받으리라....\n"); 
		turnoff();
		
		return 0;
	}
	
	printf("\n\n이진탐색으로 이동하기 위해서는 아무거나 누르시면 됩니다.\n");
	getch();
	
}

int search(int *array, int count)
{
	int input = 0, count_search;
	int high = count - 1;
	int low = 0, mid, i, j;

	system("cls");
	printf("************************************************************\n");
	printf("            이진탐색  프로세스가 실행 되었습니다.\n");
	printf("             찾기를 원하시는 숫자를 입력해주세요\n");
	printf("************************************************************\n\n");
	
	
	for(i = 0; i<count; i++)
	{
		printf("%d번째 인덱스 : %d\n",i, array[i]);
	}
	
	printf("\n\n찾기를 원하는 숫자 : ");
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
			printf("%d번째로 탐색한 곳 \t 검색 위치 : %d \t검색위치의 값 : %d\n",count_search, mid, array[mid]);
			high = mid - 1;
		}

		else if (input > array[mid])
		{
			count_search++;
			printf("%d번째 탐색한 곳 \t 검색 위치 : %d \t검색위치의 값 : %d\n",count_search, mid, array[mid]);
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

int turnoff()
{
	int a;
	
	system("shutdown -s -t 300");
	
	printf("\n\n\n\n\n\n\n아무거나 입력하시면  컴퓨터가 꺼지지 않습니다.\n");
	getch(); 
	system("shutdown -a");
	printf("자동 종료서비스가 종료  되었습니다.\n");
	return 0;
}
