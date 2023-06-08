#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float data[][2] = {{0,0},{2,4},{4,8},{8,16},{16,32}};

#define data_count (sizeof(data)/sizeof(data[0]))

float rand_float(void){
	return (float) rand()/(float) RAND_MAX;
};

float cost_func(float w){
	float result = 0.0f;
	for (size_t i = 0; i < data_count; i++){
		float x = data[i][0];
		float y = x*w;
		float d = y - data[i][1];
		result += d*d;
	};
	result /= data_count;
	return result;
};

int main(){
	
	srand(time(0));
	float w = rand_float()*10.0f;

	float eps = 1e-3;
	float rate = 1e-3;

	printf("w = %f\n", w);
	for (size_t i = 0; i < 500; i++){
		float dcost = (cost_func(w + eps) - cost_func(w))/eps;
		w -= rate*dcost;
		float res = cost_func(w);	
		printf("cost = %f, w = %f\n",res, w);
		if (res < 0.0000001f){
			break;
		}
	}
	printf("-----------------------\n");
	printf("%f\n",w);
	return 0;
}
