#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "sorts1.h"


#define N 20000 //йнкхвеярбн щкелемрнб люяяхбю(он слнквюмхч)
#define K 10 // йнкхвеярбн пегскэрюрнб янпрхпнбнй янупюмъелшу б оюлърх
#define Q 11 // йнкхвеярбн осмйрнб лемч
#define NUM 20 //йнкхвеярбн щкелемрнб люяяхбю бшбндъыхуяъ мю щйпюм

typedef struct //ярпсйрспю дюммшу дкъ упюмемхъ пегсдэрюрнб янпрхпнбйх
{
	int time_sort; //бпелъ янпрхпнбйх
	char *name; //сйюгюрекэ мю мювюкн ярпнйх я мюгбюмхел янпрхпнбйх
	int num;//йнкхвеярбн щкелемрнб
	int sorted_arr[NUM]; //тпюцлемр нрянпрхпнбюммнцн люяяхбю
} sorts_time;

const int NotUsed = system("color F0");//гюлемю жберю йнмянкх (F - BRIGHT WHITE BACKGROUD, 0 - BLACK TEXT)

int main()
{
	void((*f_arr[Q - 3]))(int*, int) = { bubble_sort,shaker_sort,quick_sort,selection_sort,merge_sort,it_merge_sort,lin_insertion_sort,bin_insertion_sort };//янгдюмхе люяяхбю сйюгюрекеи мю янпрхпнбйх
	setlocale(LC_CTYPE, "Russian");//кнйюкхгюжхъ
	int n = N;//йнкхвеярбн щкелемрнб люяяхбю (хглемъелне)
	int *C_ARR = (int*)malloc(N * sizeof(int));//янгдюмхе дхмюлхвеяйнцн люяяхбю (люяяхб он слнквюмхч)
	int *arr = (int*)malloc(N * sizeof(int));//янгдюмхе дхмюлхвеяйнцн люяяхбю (люяяхб дкъ янпрхпнбйх)
	char menu[Q][33] = { "бБНД","бШБНД","яНПРХПНБЙЮ ОСГШПЭЙНЛ","ьЕИЙЕПМЮЪ ЯНПРХПНБЙЮ","аШЯРПЮЪ ЯНПРХПНБЙЮ","яНПРХПНБЙЮ БШАНПНЛ","яНПРХПНБЙЮ ЯКХЪМХЕЛ (МХЯУНДЪЫЮЪ)",
		"яНПРХПНБЙЮ ЯКХЪМХЕЛ (БНЯУНДЪЫЮЪ)","яНПРХПНБЙЮ БЯРЮБЙЮЛХ (КХМЕИМЮЪ)","яНПРХПНБЙЮ БЯРЮБЙЮЛХ (АХМЮПМЮЪ)","бШУНД" };
	int k = 0, flag1 = 0;
	sorts_time sorts_arr[K] = { {0," ",0,0} };
	int s_time, e_time, count = 0;
	srand(time(0));//опнйпсрйю яв╗рвхйю ояебдняксвюимшу вхяек
	create_r_arr(C_ARR, N);//гюонкмъел люяяхб яксвюимшлх вхякюлх
	FILE* file;//янгдюмхе тюикю б йнрнпнл асдср упюмхрэяъ пегскэрюрш янрхпнбнй
	fopen_s(&file, "sorts_time.csv", "w");// нрйпшбюел тюик дкъ гюохях
	if (file != NULL) {
		while (k != 10) {
			k = choice(menu, Q);
			switch (k)
			{
			case 0:
				C_ARR = input(C_ARR, &n);
				free(arr);//нябнанфдюел люяяхб
				arr = (int *)malloc(n * sizeof(C_ARR[0]));//гюбндхл люяяхб мнбнцн пюглепю
				break;

			case 1:
				printf("хЯУНДМШИ ЛЮЯЯХБ :\n");
				print_arr(C_ARR, NUM);
				printf("\n\n");
				fprintf(file, "\sep=,\nйНКХВЕЯРБН ЩКЕЛЕМРНБ,мЮГБЮМХЕ ЯНПРХПНБЙХ,бПЕЛЪ\n");
				if (flag1) {
					for (int i = count; i < K; i++) {
						fprintf(file, "%d,%s,%d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("нРЯНПРХПНБЮММШИ ЛЮЯЯХБ :\n");
						print_arr(sorts_arr[i].sorted_arr, NUM);
						printf("\n\n");
					}
				}
				for (int i = 0; i < count; i++) {
					fprintf(file, "%d,%s, %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("нРЯНПРХПНБЮММШИ ЛЮЯЯХБ :\n");
					print_arr(sorts_arr[i].sorted_arr, NUM);
					printf("\n\n");
				}
				break;

			case 10:
				break;

			default:
				copy_arr(C_ARR, arr, n);//йнохпнбюмхе щк-рнб хг нямнбмнцн люяяхбю б "янпрхпнбнвмши" люяяхб
				s_time = clock();//бпелъ пюанрш опнцпюллш дн янпрхпнбйх
				(*f_arr[k - 2])(arr, n);//бшгнб янпрхпнбйх
				e_time = clock();//бпелъ пюанрш опнцпюллш оняке янпрхпнбйх
				sorts_arr[count].time_sort = e_time - s_time;//гюохяэ пегскэрюрнб
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			}

			if (count == K) { 
				count = 0; //яапня явервхйю опх люйяхлюкэмнл йнкхвеярбе пегскэрюрнб
				flag1 = 1;
			}
		}
	fclose(file);//гюйпшбюел тюик
	}
	free(C_ARR);//нябнанфдюел оюлърэ нр люяяхбнб
	free(arr);
	return 0;
}

