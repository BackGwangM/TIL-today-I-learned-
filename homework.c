#include <stdio.h>
#define swap(temp, a, b) ((temp)=(a), (a)=(b), (b)=(temp))



int main(void)
{
	int array[10];
	int min, count = 0;
	int i, temp, j, exchange_count = 0, compare_count = 0, total_exchange = 0, total_compare = 0;
	
	for(i = 0; i<10; i++)
	{
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
		printf("%dpass : ",j+1);
		
		for (i = 0; i<count; i++){
			printf("%d ", array[i]);
		}
			printf("\t\t ºñ±³ È½¼ö : %d ±³È¯ È½¼ö : %d\n", compare_count, exchange_count );
		
		exchange_count = 0;
		compare_count = 0;
	}
	
	printf("Á¤·Ä ¿Ï·á : ");
	for (i = 0; i<count; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\t\tÃÑ ºñ±³ È½¼ö : %d ±³È¯ È½¼ö : %d\n",total_compare ,total_exchange);
}
