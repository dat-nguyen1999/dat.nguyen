#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
using namespace std;
void print_normal(int arr[], int size) {
	int height= ceil((float)(log(size)/log(2)));
	int h = height;
	cout << height << endl;
	bool head = true;
	int r = 0;
	for (int i = 0; i < h ; i++) {
		for (int j = 0; j < pow(2, i) && pow(2, i) < size; j++) {
			if (j + (int)pow(2, i) - 1 < size) {
				if (j + (int)pow(2, i) - 1 == 0) {
					for (int i = 0; i < 3 * pow(2, height - 1)/2; i++)
						printf(" ");
					for (int i = 0; i < 3 * pow(2, height - 1) / 2 - 3; i++)
						printf("_");
					printf("%03d", arr[j + (int)pow(2, i) - 1]);
					for (int i = 0; i < 3 * pow(2, height - 1) / 2 - 3; i++)
						printf("_");
				}	
				else {
					if (head) {
						for(int i = 0; i< 3 * (int)(pow(2,height)/4) ; i++)
							printf(" ");
						head = false;
					}
					if (height <= 2) {
						if ((j + (int)pow(2, i) - 1) % 2 == 1) {
							printf("%03d", arr[j + (int)pow(2, i) - 1]);
							
						}
						else {
							for (int i = 0; i < (2 * height - 1) * 3; i++)
								printf(" ");
							printf("%03d", arr[j + (int)pow(2, i) - 1]);
							for (int i = 0; i < (2 * height - 1) * 3; i++)
								printf(" ");
						}
					}
					else {
						if ((j + (int)pow(2, i) - 1) % 2 == 1) {
							for (int i = 0; i < 3 * pow(2, height - 1) / 2 - 3; i++)
								printf("_");
							printf("%03d", arr[j + (int)pow(2, i) - 1]);
							for (int i = 0; i < 3 * pow(2, height - 1) / 2 - 3; i++)
								printf("_");
						}
						else {
							for (int i = 0; i < 3 * pow(2, height - 1 ) + 3 ; i++)
								printf(" ");
							for (int i = 0; i < 3 * pow(2, height - 1) / 2 - 3; i++)
								printf("_");
							printf("%03d", arr[j + (int)pow(2, i) - 1]);
							for (int i = 0; i < 3 * pow(2, height - 1) / 2 - 3; i++)
								printf("_");
							for (int i = 0; i < 3 * pow(2, height - 1) + 3; i++)
								printf(" ");
						}
					}
				}
			}
			
		}
		height--;
		printf("\n");
		head = true;
	}
}
void heapDisplay90(int maxHeap[], int position, int size, string s) {
	if (maxHeap == NULL || position >= size|| size<0 ) return;
	heapDisplay90(maxHeap, 2*position + 2, size, s + "          ");
	cout <<s<< maxHeap[position] << endl;
	heapDisplay90(maxHeap, 2 * position + 1, size, s + "          ");

}
void heapDisplay90(int maxHeap[], int position, int size) {
	string s;
	heapDisplay90(maxHeap, position, size,  s);
}
int main() {
	int arr[31] = { 30,21,29,16,20,24,28,9,15,17,19,13,23,25,27,0,6,3,14,2,8,7,18,1,10,5,22,4,12,11,26 };
	print_normal(arr, 31);
	
	system("pause");
	return 0;
}