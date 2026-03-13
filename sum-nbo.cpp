#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	uint32_t nums[argc];
	uint32_t sum_nbo = 0;
	for(int i=1;i<argc;i++){
		FILE* fp = fopen(argv[i], "rb");
		if(!fp){
			printf("cannot open %s\n", argv[i]);
			return 1;
		}
		uint32_t n;
		if(fread(&n, 4, 1, fp) != 1){
			printf("wrong file size\n");
			fclose(fp);
			return 1;
		}
		nums[i] = ntohl(n);
		sum_nbo += nums[i];
		fclose(fp);
	}
	for(int i=1;i<argc;i++){
		printf("%d(%08x)", nums[i], nums[i]);
		if(i<argc-1) printf(" + ");
	}
	printf(" = %d(%08x)\n", sum_nbo, sum_nbo);

	return 0;
}
