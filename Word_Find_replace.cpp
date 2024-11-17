#include<iostream>
using namespace std;
int lenght(char a[]) {
	int x = 0;
	for (int i = 0;a[i] != '\0';i++) {
		x++;
	}
	return(x);
}
int finder(char main[], char find[]) {
	int check = 0;
	int x = 0;
	for (int i = 0;i < lenght(main);i++) {
		x = i;

		for (int j = 0;j < lenght(find);j++) {
			if (main[x] == find[j]) {
				check = 1;
				x++;
			}
			else {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			return(i);
		}
	}
	return(-1);
}
void same_replace(char main[], char place[], int start, int end) {
	char n[100];
	int x = 0;
	for (int i = 0;i < lenght(main);i++) {
		if (i >= start && i < end) {
			n[i] = place[x];
			x++;
		}
		else {
			n[i] = main[i];
		}
	}
	for (int i = 0;i < lenght(main);i++) {
		cout << n[i];
	}
}
void Bigger_replace(char main[], char place[], int start, int end, int diff) {
	char n[100];
	int x = 0, l = 0;
	for (int i = 0;i < diff + lenght(main);i++) {
		if (i >= start && i < start + lenght(place)) {
			n[i] = place[x];
			x++;
		}
		else if (i >= start + lenght(place)) {
			n[i] = main[i - diff];

		}
		else {
			n[i] = main[i];
		}
		l = i;
	}
	n[l + 1] = '\0';


	for (int i = 0;n[i] != '\0';i++) {
		cout << n[i];
	}
}
void Smaller_replace(char main[], char place[], int start, int end, int diff) {
	char n[100];
	int x = 0, l = 0;
	for (int i = 0;i < diff + lenght(main);i++) {
		if (i >= start && i < start + lenght(place)) {
			n[i] = place[x];
			x++;
		}
		else if (i >= start + lenght(place)) {
			n[i] = main[i - diff];

		}
		else {
			n[i] = main[i];
		}
		l = i;
	}
	n[l + 1] = '\0';
	for (int i = 0;n[i] != '\0';i++) {
		cout << n[i];
	}
}

int main() {
	cout << "\033[92m\033[3m\033[5m                                         Welcome to Word --> Find --> Replace\033[0m\n";
	char main[100], find[100], place[100];
	int diff = 0;
	cout << "\033[95mPlease Enter the main Sentence: \033[93m\033[3m";
	cin.getline(main, 100);
	cout << "\033[0m\033[95mPlease Enter to find: \033[93m\033[3m";
	cin.getline(find, 100);
	if (finder(main, find) == -1) {
		cout << "\033[0m\033[91m\033[5m                                     Sorry, Word not found !! \033[0m";
		return(0);
	}
	cout << "\033[92m\033[5m                                        Word Found !!!\n";
	cout << "\033[0m\033[95mNow Please Enter the word to replace with : \033[0m\033[93m\033[96m";
	cin.getline(place, 100);
	diff = lenght(place) - lenght(find);
	cout <<"\033[0m\033[95mWord starting location is at "<< finder(main, find) <<"\033[96m" << endl;
	cout << "\033[5mThe changed Sentence is :\n";
	int end = finder(main, find) + lenght(find);
	if (lenght(find) == lenght(place)) {
		same_replace(main, place, finder(main, find), end);
	}
	else if (lenght(find) > lenght(place)) {
		Bigger_replace(main, place, finder(main, find), end, diff);
	}
	else if (lenght(find) < lenght(place)) {
		Smaller_replace(main, place, finder(main, find), end, diff);
	}
	cout << "\033[0m";
}
