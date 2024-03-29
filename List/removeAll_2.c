#include <stdio.h>
#define Maxlength 30
typedef struct {
    int Elements[Maxlength];
    int Last;       // So phan tu trong list
}List; 

// Khoi tao danh sach rong
void makenullList(List *L){
    L->Last = 0;
}

// Kiem tra danh sach rong
int emptyList(List L){
	return L.Last == 0;
}

// Kiem tra danh sach day
int fullList(List L){
	return L.Last == Maxlength;
}

// Ham in danh sach
void printList(List L){
	int i;
    for(i = 0; i < L.Last; i++)
    	printf("%d ", L.Elements[i]);
    printf("\n");
}

// Xen mot phan tu vao danh sach
void insertList(int x, int p, List *L){
	if(p < 1 || p > Maxlength || fullList(*L))
		printf("Vi tri khong hop le");
	else{
		int i;
		for(i = L->Last; i >= p; i--)
			L->Elements[i] = L->Elements[i-1];
		L->Elements[p-1] = x;
		L->Last++;
	}
}

// Kiem tra mot phan tu co trong danh sach hay khong
int member(int x, List L){
	int i;
	for(i = 0; i < L.Last; i++)
		if(x == L.Elements[i])
			return 1;
	return 0;
}

// Sap xep danh sach tu be den lon
void sort(List *pL){
	int i, j;
	for(i = 0; i < pL->Last-1; i++)
		for(j = i+1; j < pL->Last; j++)
			if(pL->Elements[i] > pL->Elements[j]){
				int temp = pL->Elements[i];
				pL->Elements[i] = pL->Elements[j];
				pL->Elements[j] = temp;
			}
}	

// Xoa mot phan tu trong danh sach
void deleteList(int p, List *L){
	if(p < 1 || p > L->Last)
		printf("Vi tri khong hop le");
	else{
		int i;
		for(i = p-1; i < L->Last; i++)
			L->Elements[i] = L->Elements[i+1];
		L->Last--;
	}
}

// Doc danh sach
void readList(List *L){
	makenullList(L);
	int x, i, n;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &x);
		insertList(x, i, L);
	}
}

int locate(int x, List L){
	int i;
	for(i = 0; i < L.Last; i++)
		if(L.Elements[i] == x)
			return i+1;
	return L.Last+1;
}

// Xoa tat ca phan tu co gia tri l� x trong danh s�ch chi boi con tro pL
void removeAll(int x, List *L){
	while(1){
		int p = locate(x, *L);
		if(p == L->Last+1)
			break;
		deleteList(p, L);
	}
}

int main(){
    List L;
	readList(&L);
	int n;
	scanf("%d", &n);
	printList(L);
	removeAll(n, &L);
	printList(L);	
    return 0;
}
