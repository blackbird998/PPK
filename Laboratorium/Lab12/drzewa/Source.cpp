#include <iostream>
#include <string>

using namespace std;

struct Tree_el {
	int val;
	Tree_el *left;
	Tree_el *right;
};

void Add(Tree_el *&el_drzewa, int wart_dodana);
void Show(Tree_el *el_drzewa);
void Del(Tree_el *el_drzewa);

int main() {
	Tree_el root;
	root.left = nullptr;
	root.right = nullptr;
	root.val = 0;
	Tree_el *wsk_root = &root;
	for (int i = 1; i < 10; i++) {
		Add(wsk_root, i);
	}
	Show(wsk_root);
	//Del(wsk_root);
	//Show(wsk_root);
	system("pause");
	return 0;
}

void Add(Tree_el *&el_drzewa, int wart_dodana) {
	if (!el_drzewa){
		el_drzewa = new Tree_el;
		el_drzewa->val = wart_dodana;
		el_drzewa->left = nullptr;
		el_drzewa->right = nullptr;
	}
	else if(el_drzewa->val>wart_dodana){
		Add(el_drzewa->left, wart_dodana);
	}
	else if (el_drzewa->val<wart_dodana) {
		Add(el_drzewa->right, wart_dodana);
	}
}

void Show(Tree_el *el_drzewa) {
	if (el_drzewa) {
		Show(el_drzewa->left);
		cout << "Adres wyswietlanego elementu: " << el_drzewa << endl;
		cout << el_drzewa->val << endl;
		cout << "Adres lewego elementu: " << el_drzewa->left << endl;
		cout << "Adres prawego elementu: " << el_drzewa->right << endl;
		Show(el_drzewa->right);
	}
}

void Del(Tree_el *el_drzewa) {
	if (el_drzewa) {
		Del(el_drzewa->right);
		Del(el_drzewa->left);
	}
	else {
		
	}
}
