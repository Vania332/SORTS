#include <iostream>



using namespace std;


//void vivod_mass(int a[], int size) {
//	for (int i = 0; i < size; i++)
//		cout << a[i] << " ";
//	cout << endl;
//}
void swap(int* x, int* y) {
	int t = *x;
	*x = *y;
	*y = t;
}
void BubbleSort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (a[j - 1] > a[j])
				swap(&a[j - 1], &a[j]);
		}
	}
}
void MinSort(int a[], int n) {
	int k, i, j;
	for (i = 0; i < n; i++) {
		for (k = i, j = i + 1; j < n; j++) {
			if (a[j] < a[k]) {
				k = j;
				swap(&a[k], &a[i]);
			}
		}
	}
}
void InsertSort(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			swap(&a[j], &a[j - 1]);
			j--;
		}
	}
}
void Sort_Shell(int* x, int n) {
	int i, j, gap, sorted;
	for (gap = n / 2; gap > 0; gap /= 2) {
		do {
			sorted = 0;
			for (i = 0, j = gap; j < n; i++, j++) {
				if (*(x + i) > *(x + j)) {
					swap(*(x + i), *(x + j));
					sorted = 1;
				}
			}
		} while (sorted);
	}
}
// quicksort
//int partition(int a[], int low, int high) {
//	int pivot = a[high];//опорная тема
//	int i = low - 1; //индекс меньшего эл
//
//	for (int j = low; j < high; j++) {
//		if (a[j] <= pivot) {
//			i++;
//			swap(a[i], a[j]);
//		}
//	}
//	swap(a[i + 1], a[high]);
//	return i + 1;
//}
//void Quicksort(int a[],int low ,int high){
//	if (low < high) {
//		int razdel = partition(a, low, high);//индекс разделения получаем для рекурсии юзанем
//		Quicksort(a, low, razdel - 1);
//		Quicksort(a, razdel + 1, high);
//	}
//}
void Quicksort(int a[], int low, int high) {
	while (low < high) {

		int mid = low + (high - low) / 2;
		if (a[mid] < a[low]) swap(&a[mid], &a[low]);
		if (a[high] < a[low]) swap(&a[high], &a[low]);
		if (a[mid] < a[high]) swap(&a[mid], &a[high]);

		int pivot = a[high];
		int i = low - 1;


		for (int j = low; j < high; j++) {
			if (a[j] <= pivot) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i + 1], &a[high]);
		int razdel = i + 1;


		if (razdel - low < high - razdel) {
			Quicksort(a, low, razdel - 1);
			low = razdel + 1;
		}
		else {
			Quicksort(a, razdel + 1, high);
			high = razdel - 1;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");


	// ввод массива
	int n = 0;
	//cout << "n = " << endl;
	cin >> n;

	int k;
	cin >> k;

	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//соритировки

	//cout << "массив заполнен\n выбери номер сорт" << endl;

	switch (k){
	case(1):
		BubbleSort(a, n);
	case(2):
		MinSort(a, n);
	case(3):
		InsertSort(a, n);
	case(4):
		Sort_Shell(a, n);
	case(5):
		Quicksort(a, 0, n - 1);
	default:
		break;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
}