//#include<iostream>
//using namespace std;
//class Cl {
//private:
//	int element;
//	
//public: 
//	void get() {
//		cout << "Enter the value of the element: ";
//		cin >> element;
//	}
//	void print() {
//		cout << element;
//	}
//	Cl& ret_el(Cl* array, int index) {
//		
//		return array[index];
//	}
//	Cl& operator-- () {
//		this->element--;
//		return *this;
//	}
//	
//	friend void show_the_array(Cl* arr, int size);
//};
//void show_the_array(Cl* array, int size) {
//	cout << "The array: "<<endl;
//	for (int i = 0; i < size; i++) {
//		array[i].print() ;
//
//		cout << endl;
//	}
//}
//
//
//void main() {
//Cl element1;
//	element1.get();
//	Cl element2;
//	element2.get();
//	Cl element3;
//	element3.get();
//	Cl element4;
//	element4.get();
//	
//	const int size = 4;
//	Cl array[size];
//	array[0] = element1;
//	array[1] = element2;
//	array[2] = element3;
//	array[3] = element4;
//	show_the_array(array, size);	
//	int numb;
//	cout << "Enter the number of the element (0-3): ";
//	cin >> numb;
//	--array[numb].ret_el(array, numb);
//	show_the_array(array, size);
//}
#include<iostream>
using namespace std;
class Cl {
private:
	int** data;
	int lines;
	int colomns;
	int min=0;
	int minInd1;
	int minInd2;
public:

	Cl(int lines, int colomns) {//конструктор
		int** data = new int* [lines];
		for (int i = 0; i < lines; i++)
			data[i] = new int[colomns];

		for (int y = 0; y < lines; y++) {
			for (int j = 0; j < colomns; j++) {
				data[y][j] = rand() % (100 - 1 + 1) + 1;
				cout << data[y][j] << "\t";
			}
			cout << endl;
		}
	}
	//void setter() {
	//			cout << "Enter the number of lines: ";
	//			cin >> lines;
	//			cout << "\nEnter the number of colomns: ";
	//			cin >> colomns;
	//		}
	~Cl() {//деструктор
		for (int q = 0; q < colomns; q++) {
			delete[] data[q];
		}
		delete[]data;
	}
	int null(Cl arr) {

	
		for (int p = 0; p < lines; p++)
			for (int m = 1; m < colomns; m++)
				if (min < arr.data[p][m])
				{
					min = arr.data[p][m];
					minInd1 = p;
					minInd2 = m;
				}
		return min;
	}
};





void main() {
	Cl array1(2, 3);
	int choice, minim;
	cout << "Menu:\n1-null\n2-swap\n";
	cin >> choice;
	switch (choice) {
	case 1:minim = array1.null(array1); cout << minim; break;
	case 2: break;
	}
	array1.~Cl();
}
