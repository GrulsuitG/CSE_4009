//2016025205
#include "cachelab.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned long long int address;

int hits = 0;
int misses = 0;
int evictions = 0;

int setNum;
int lineNum;
int blockNum;
int s, b;
unsigned time = 0;
bool verbose = false;

FILE *fp;

typedef struct cacheLine{
	bool valid;
	int ref;
	address tag;
	char *block;	
}cacheLine;

typedef struct cacheSet{
	cacheLine *lines;
	int lru;
}cacheSet;

typedef struct cache{
	cacheSet *sets;
}cache;

cache make_cache(){
	cache c;
	cacheSet set;
	cacheLine line;
	c.sets = (cacheSet*)malloc(sizeof(cacheSet)*setNum);
	for(int i =0; i<setNum; i++){
		set.lines = (cacheLine*) malloc(sizeof(cacheLine) * lineNum);
		c.sets[i] = set; 
		for(int j=0; j<lineNum; j++){
			line.valid = false;
			line.ref = 0;
			line.tag = 0;
			set.lines[j] = line;
		}
	}
	return c;
}

int eviction(cacheSet set){
	int result = 0;
	for(int i =0; i<lineNum; i++){
		if(set.lines[i].ref < set.lines[result].ref )
			result = i;
	}
	return result;
}


int find_cache(cache c, address mem){
	int tagsize = (64-(s+b));
	address inputTag = mem >>(s + b);
	address inputset = mem <<(tagsize); 
	inputset = inputset >> (tagsize+b);
	int lineIndex;
	int result;
	cacheSet tempSet = c.sets[inputset];
	bool full = true;
	for(int i =0; i < lineNum; i++){
		if(tempSet.lines[i].valid){
			if(tempSet.lines[i].tag == inputTag){
				hits++;
				tempSet.lru = i;
				tempSet.lines[i].ref = time++;
				return 1;	
			}
		}
		else{
			full = false;
		}
	}
	misses++;
	if(full){
		lineIndex = eviction(tempSet);
		result =3;
		evictions++;
	}
	else{
		for(int i =0; i<lineNum; i++){
			if(tempSet.lines[i].valid == false){
				lineIndex = i;
				break;
			}
		}
		
		result = 2;
	}
	tempSet.lru= lineIndex;
	tempSet.lines[lineIndex].valid = true;
	tempSet.lines[lineIndex].ref = time++;
	tempSet.lines[lineIndex].tag = inputTag;
	return result;
}

int main(int argc, char* argv[]){
	char ch;
	address mem;
	int size, result;
	cache c;
	while((ch = getopt(argc,argv,"vs:E:b:t:")) != -1){
		switch(ch){
		 case 'v':
		 	verbose = true;
		 	break;
		 case 's':
		 	s = atoi(optarg);
		 	setNum = pow(2,atoi(optarg));
		 	break;
		 case 'E':
		 	lineNum = atoi(optarg);
		 	break;
		 case 'b':
			b = atoi(optarg);		 	
		 	blockNum = pow(2,atoi(optarg));
		 	break;
		 case 't':
		 	if((fp = fopen(optarg, "r")) == NULL){
		 		perror("file open error");
		 		exit(EXIT_FAILURE);
		 	}
		 	break;
		 default:
		 	exit(EXIT_FAILURE); 
		}
	}
	c = make_cache();
	while(fscanf(fp, " %c %llx,%d", &ch, &mem, &size) == 3){
		switch(ch){
			case 'I':
				break;
			case 'L':
				result = find_cache(c, mem);
				if(verbose){
					printf("%c %llx,%d ", ch, mem, size);
					if(result ==1)
						printf("hit\n");
					else if(result ==2)
						printf("miss\n");
					else
						printf("miss eviction\n");
				}
				break;
			case 'S':
				result = find_cache(c, mem);
				if(verbose){
					printf("%c %llx,%d ", ch, mem, size);
					if(result ==1)
						printf("hit\n");
					else if(result ==2)
						printf("miss\n");
					else
						printf("miss eviction\n");
				}
				break;
			case 'M':
				result = find_cache(c, mem);
				if(verbose){
					printf("%c %llx,%d ", ch, mem, size);
					if(result ==1)
						printf("hit ");
					else if(result ==2)
						printf("miss ");
					else
						printf("miss eviction ");
				}
				result = find_cache(c, mem);
				if(verbose){
					if(result ==1)
						printf("hit\n");
					else if(result ==2)
						printf("miss\n");
					else
						printf("miss eviction\n");
				}
				break;
			default:
				break;
		}
	}
	fclose(fp);
    printSummary(hits, misses, evictions);
    
    return 0;
}
