#include "basicFunction.h"

int addDog(Dog *d){
    printf("\n");
    printf("이름? ");
    scanf("%[^\n]s",d->name);

    getchar();

    printf("강아지 종? ");
    scanf("%[^\n]s", d->type);

    getchar();

    do{
        printf("센터 들어온 년/월? ");
        scanf("%d %d", &d->year, &d->month);

        if(d->year<=0 || d->month<=0){
            printf("\n=> 음수 및 0 날짜는 존재 하지 않습니다.\n");
        }else if(d->year<=2021){
            if(d->year==2021){
                if(d->month<=5){
                    break;
                }
            }else if(d->year<2021){
                if(d->month<=12){
                    break;
                }
            }
        }printf("\n=> 현재 잘짜 (2021/5) 보다 앞서는 날짜 지정 못합니다.\n");
    }while(1);

    do{
        printf("나이? ");
        scanf("%d", &d->age);

        if(d->age >= 0){
            break;
        }
        printf("\n==> 나이 음수로 될 수 없습니다.\n");
    }while(1);

    getchar();

    do{
        printf("예방주사 접촉 여부 (true/false)? ");
        scanf("%[^\n]s", d->vaccine);
        getchar();
        if(strcmp(d->vaccine, "true")==0 || strcmp(d->vaccine, "false")==0){
            break;
        }
        printf("\n=> true/false, 둘중에 하나 선택해주세요.\n");
    }while(1);

    do{
        printf("중성화 유뮤(true/false)? ");
        scanf("%[^\n]s", d->neutralization);
        getchar();
        if(strcmp(d->neutralization, "true")==0 || strcmp(d->neutralization, "false")==0){
            break;
        }
        printf("\n=> true/false, 둘중에 하나 선택해주세요.\n");
    }while(1);
    
    printf("==> 추가됨\n"); 
    return 1;
}

void readData(Dog *d){
    printf("%13s %14s %9d/%d %9d %12s %17s\n", d->name, d->type, d->year, d->month, d->age, d->vaccine, d->neutralization);
}

int updateData(Dog *d){
    printf("\n");
    printf("이름? ");
    scanf("%[^\n]s", d->name);

    getchar();

    printf("강아지 종? ");
    scanf("%[^\n]s", d->type);

    getchar();

    do{
        printf("센터 들어온 년/월? ");
        scanf("%d %d", &d->year, &d->month);

        if(d->year<=0 || d->month<=0){
            printf("\n=> 음수 및 0 날짜는 존재 하지 않습니다.\n");
        }else if(d->year<=2021){
            if(d->year==2021){
                if(d->month<=5){
                    break;
                }
            }else if(d->year<2021){
                if(d->month<=12){
                    break;
                }
            }
        }printf("\n=> 현재 잘짜 (2021/5) 보다 앞서는 날짜 지정 못합니다.\n");
    }while(1);

    do{
        printf("나이? ");
        scanf("%d", &d->age);

        if(d->age >= 0){
            break;
        }
        printf("\n==> 나이 음수로 될 수 없습니다.\n");
    }while(1);

    getchar();

    do{
        printf("예방주사 접촉 여부 (true/false)? ");
        scanf("%[^\n]s", d->vaccine);
        getchar();
        if(strcmp(d->vaccine, "true")==0 || strcmp(d->vaccine, "false")==0){
            break;
        }
        printf("\n=> true/false, 둘중에 하나 선택해주세요.\n");
    }while(1);

    do{
        printf("중성화 유뮤(true/false)? ");
        scanf("%[^\n]s", d->neutralization);
        getchar();
        if(strcmp(d->neutralization, "true")==0 || strcmp(d->neutralization, "false")==0){
            break;
        }
        printf("\n=> true/false, 둘중에 하나 선택해주세요.\n");
    }while(1);

    printf("==> 수정됨!\n");
    
    return 1;
}

int deleteData(Dog *d){
    d->year = -1;
    d->month = -1;
    d->age = -1;
    printf("==> 삭제됨!\n");
    return 0;
}


int selectMenu(){
    int menu;
    printf("\n*** 보호견 목록 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 지정 견종인 강아지 정보 검색\n");
    printf("7. 지정 나이 보다 동일하거나 더 어린 강아지 정보 겁색\n");
    printf("8. 지정 날짜와 동일하거나 더 최근에 들어온 강아지 정보 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void listData(Dog *d,int count){
    printf("\nNo. %10s %13s %20s %10s %21s %20s\n", "이름", "견종", "들어온날짜", "나이", "예방접종여부", "중성화유뮤");
    printf("==========================================================================================\n");
    for(int i=0; i<count; i++){
        if( d[i].year == -1 || d[i].age == -1 ) continue;
        printf("%2d.", i+1);
        readData(&d[i]);
    }
    printf("\n");
}

int selectDataNo(Dog *d, int count){
    int no;
    listData(d ,count);
    printf("번호는 (취소:0)? ");
    scanf("%d", &no);
    getchar();
    return no;
}


void saveData(Dog d[], int count){
    FILE* fp;

	fp= fopen("dog.txt","wt");
	
	for(int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", d[i].name);
        fprintf(fp, "%s\n", d[i].type);
		fprintf(fp, "%d %d %d %s %s %s\n", d[i].year, d[i].month, d[i].age, d[i].type, d[i].vaccine, d[i].neutralization);
	}

	fclose(fp);
	printf("저장됨!\n");

}

int loadData(Dog *d){
    int count=0;
	FILE*fp;

	fp = fopen("dog.txt", "r");

    if(fp == NULL) {
        printf("=> 로딩 실패!\n");
        return count;
    }

	while( fscanf(fp, "%d", &(d[count].year)) != -1) {
        fgets(d[count].name, sizeof(d[count].name), fp);
        fgets(d[count].type, sizeof(d[count].name), fp);
        fscanf(fp, "%d ", &(d[count].year));
		fscanf(fp, "%d ", &(d[count].month));
        fscanf(fp, "%d ", &(d[count].age));
        //d[count].vaccine = '\0'; 
        //d[count].neutralization = '\0';
		

		int length = strlen(d[count].name);
		d[count].name[length -1] = '\0';

        length = strlen(d[count].type);
		d[count].type[length -1] = '\0';

		count++;
	}

    fclose(fp);



	printf("=> 로딩 성공!\n");
	return count;

    return 1;
}