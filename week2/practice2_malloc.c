#include <stdio.h>
#include <stdlib.h>

int main(void){
	char** pp_data = NULL;
	int n;
	int length;
	int i;

	printf("몇개의 문장을 입력하나요?");
	scanf("%d", &n);


	//1. define & dynamic allocation
	pp_data = (char**)malloc(sizeof(char*)*n);
	for(i = 0; i<n; i++){
		printf("몇 글자를 입력 받나요?");
		scanf("%d", &length);
		*(pp_data+i) = (char*)malloc(sizeof(char)*length);
		printf("글자를 입력해주세요 : ");
		scanf("%s", *(pp_data+i)); 
	}
	//2. print string
	printf("입력받은 문자 \n");
	for(i = 0; i<n; i++){
		printf("%s\n", *(pp_data+i));
	
	}
	

	//3. free memory
	for(int i =0; i<n; i++){
		free(*(pp_data+i));
	}
	free(pp_data);

	return 0;
}
