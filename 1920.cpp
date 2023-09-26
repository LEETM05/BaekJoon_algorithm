//#include <iostream>
//
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	int num, rear = 0;
//	int end_index, tmp;
//	cin >> num;
//	end_index = num - 1;
//	int* card = new int[num];
//	for (int i = 0; i < num; i++) {
//		card[i] = i + 1;
//	}
//	for (int i = 0; i < num; i++) {
//		card[rear++] = -1;
//		tmp = card[end_index];
//		card[end_index] = card[rear];
//		card[rear] = tmp;
//
//	}
//	cout << card[num] << "\n";
//}

// 1 2 3 4 5 6 7 8 9
//   9 3 4 5 6 7 8 2
//     2 4 5 6 7 8 3
//       3 5 6 7 8 4
//         4 6 7 8 5
//           5 7 8 6
//             6 8 7
//               7 8
//                 7

#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}


//int binsearch(int left, int right, int* arr, int findnum) {
//    int middle = (left + right) / 2;
//
//    if (findnum == *(arr + middle))
//        return 1;
//    if (left == right)
//        return 0;
//
//    if (findnum < *(arr + middle))
//        binsearch(left, middle - 1, arr, findnum);
//    else if (findnum > *(arr + middle))
//        binsearch(middle + 1, right, arr, findnum);
//}

int binsearch(int left, int right, int *arr, int key)
{
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;

        if (key < arr[mid]) {
            right = mid - 1;
        }
        else if (key > arr[mid]) {
            left = mid + 1;
        }
        else {
            return 1;
        }
    }
    return 0;
}

void quicksort(int left, int right, int *arr) {
    if (left > right)
        return;
    int pivot = left;
    int i = left;
    int j = right + 1;
    do {
        do {
            ++i;
        } while (*(arr + pivot) > *(arr + i));
        do {
            j--;
        } while (*(arr + pivot) < *(arr + j));
        if (i >= j)
            break;
        else
            swap((arr + i), (arr + j));
    } while (i < j);
    swap((arr + j), (arr + pivot));
    quicksort(left, j - 1, arr);
    quicksort(j + 1, right, arr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int* num = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> *(num + i);
    }

    int M;
    cin >> M;
    int* MM = new int[M];
    for (int i = 0; i < M; i++)
        cin >> *(MM + i);

    quicksort(0, n - 1, num);

    for (int i = 0; i < M; i++) {
        if (binsearch(0, n - 1, num, *(MM + i)))
            cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}