#include <stdio.h>
#include <conio.h>

int input(int*);

int main(void)
{
	int array[10] = { 0 };
	int count = 0, i, input_sort = 0;

	printf("************************************************************\n");
	printf("         선택 정렬을 해드리는 프로그램 입니다.\n");
	printf("         정렬이 끝난 후 이진탐색이 가능합니다.\n");
	printf("        정렬을 원하신다면 아무거나 입력해주세요.\n");
	printf("************************************************************\n");
	getch();

	system("cls");
	printf("************************************************************\n");
	printf("  정렬을 원하시는 숫자를 입력해주세요(10개 까지만 가능)\n");
	printf(" 그만 입력하시고 싶으시다면 9999를 입력해 주시면 됩니다.\n");
	printf("************************************************************\n");
	count = input(array);

	system("cls");
	printf("************************************************************\n");
	printf("              원하시는 정렬을 선택 하여 주세요\n");
	printf("         1번은 선택 정렬, 2번은 삽입 정렬 입니다!\n");
	printf("************************************************************\n");

	scanf("%d", &input_sort);
	switch (input_sort)
	{
	case 1: select_sort(array, count); break;
	case 2: insertion_sort(array, count); break;
	default: printf("잘못 입력 하셨습니다."); return 0;
	}


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
	search(array, count);
}

int select_sort(int *array, int count)
{
	int min, find_start;
	int i, temp, j, exchange_count = 0, compare_count = 0, total_exchange = 0, total_compare = 0;

	for (j = 0; j<count; j++) {
		min = j;
		for (i = j; i<count; i++)
		{
			if (array[min]>array[i])
				min = i;
			compare_count++;
		}

		if (array[min] != array[j])
		{
			change(&array[min], &array[j]);
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


}

int insertion_sort(int* array, int count) {
	int i, j, temp;
	int exchange_count = 0, compare_count = 0;
	int total_exchange = 0, total_compare = 0;

	for (i = 1; i < count; i++)
	{
		exchange_count = 0, compare_count = 1;
		temp = array[(j = i)];
		while (--j >= 0 && temp < array[j])
		{
			array[j + 1] = array[j];
			compare_count++;
		}
		array[j + 1] = temp;

		if (compare_count > 1)
			exchange_count++;

		total_exchange += exchange_count;
		total_compare += compare_count;
		printf("%dPass : ", i);
		for (j = 0; j < count; j++)
			printf("%d ", array[j]);

		printf("\t\t비교 횟수 : %d \t교환 횟수 : %d\n", compare_count, exchange_count);
	}

	printf("\t\t비교 횟수 : %d \t교환 횟수 : %d\n", total_compare, total_exchange);
}
int change(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int search(int *array, int count)
{
	int input = 0, count_search = 0;
	int high = count - 1;
	int low = 0, mid, i, j;

	system("cls");
	printf("************************************************************\n");
	printf("            이진탐색  프로세스가 실행 되었습니다.\n");
	printf("             찾기를 원하시는 숫자를 입력해주세요\n");
	printf("************************************************************\n\n");


	for (i = 0; i<count; i++)
	{
		printf("%d번째 인덱스 : %d\n", i, array[i]);
	}

	printf("\n\n찾기를 원하는 숫자 : ");
	scanf("%d", &input);



	while (low <= high) {
		mid = (low + high) / 2;
		if (input == array[mid]) {
			printf("%d번째에서 %d 탐색 성공!\t탐색횟수 : %d", mid, array[mid], count_search);
			break;
		}

		else if (input < array[mid])
		{
			count_search++;
			printf("%d번째로 탐색한 곳 \t 검색 위치 : %d \t검색위치의 값 : %d\n", count_search, mid, array[mid]);
			high = mid - 1;
		}

		else if (input > array[mid])
		{
			count_search++;
			printf("%d번째로 탐색한 곳 \t 검색 위치 : %d \t검색위치의 값 : %d\n", count_search, mid, array[mid]);
			low = mid + 1;
		}
		else
		{
			mid = -1;
		}
	}
	if (mid == -1) {
		printf("ERROR! 찾지 못하였습니다!!");
	}
}

int input(int* array)
{
	int i, count = 0;
	for (i = 0; i<10; i++)
	{
		printf("%d번째 숫자 : ", i + 1);
		scanf("%d", &array[i]);
		count++;
		if (array[i] == 9999)
		{
			count = count - 1;
			break;
		}
	}
	return count;
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
