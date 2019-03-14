/*******************************************/
/*This is my 1st assignment programm in OOP*/
/*			ver1.0 19-03-14				   */
/*******************************************/
#include <iostream>
#include <cstdlib> // For using sturct type
using namespace std;

// Struct type declaration
struct student // Before the function declaration, struct first.
{
	int id; // Idification
	char name[10]; // Name
	int score; // Score
};

// Function declaration
int id_asc (const void* a, const void* b) // ID_Upper func for using qsort
{
	student* pa = (student*)a;
	student* pb = (student*)b;
	if (pa->id < pb->id)
		return -1;
	else if (pa->id > pb->id)
		return 1;
	return 0;
}

int id_dec (const void* a, const void* b) // ID_Lower func for using qsort
{
	student* pa = (student*)a;
	student* pb = (student*)b;
	if (pa->id > pb->id)
		return -1;
	else if (pa->id < pb->id)
		return 1;
	return 0;
}

int name_asc (const void* a, const void* b) // Name_Upper func for using qsort
{
	student* pa = (student*)a;
	student* pb = (student*)b;
	// For comparing each variable. Using for loop
	for(int i = 0; i < 3; ++i){ 
		if (pa->name[i] < pb->name[i])
			return -1;
		else if (pa->name[i] > pb->name[i])
			return 1;
		return 0;
	}
}

int name_dec (const void* a, const void* b) // Name_Lower func for using qsort
{
	student* pa = (student*)a;
	student* pb = (student*)b;
	// For comparing each variable. Using for loop
	for(int i = 0; i < 3; ++i){ 
		if (pa->name[i] > pb->name[i])
			return -1;
		else if (pa->name[i] < pb->name[i])
			return 1;
		return 0;
	}
}

int score_asc (const void* a, const void* b) // Score_Upper func for using qsort
{
	student* pa = (student*)a;
	student* pb = (student*)b;
	if (pa->score < pb->score)
		return -1;
	else if (pa->score > pb->score)
		return 1;
	return 0;
}

int score_dec (const void* a, const void* b) // Score_Lower func for using qsort
{
	student* pa = (student*)a;
	student* pb = (student*)b;
	if (pa->score > pb->score)
		return -1;
	else if (pa->score < pb->score)
		return 1;
	return 0;
}

// Main function
int main()
{
	/* Input the 5 student's Information */
	cout << "Enter the ID, Name, Score of the five students\n"
		 << "For example: \"2015161006 KDH 88\"\n";
	student stu[5];
	for(int i = 0; i < 5; ++i){
		cin >> stu[i].id >> stu[i].name >> stu[i].score;
	}

	/* Select the menu you want to sort the data. */
	cout << "Select the menu:" << endl;
	while(1){
		cout << "1.ID_Upper" << "\t2.ID_Lower"
			<< "\n3.Name_Upper" << "\t4.Name_Lower" << "\n5.Score_Upper"
			<< "\t6.Score_Lower" << "\n7.End\n";
		int chooseMenu;
		cin >> chooseMenu;

		/* Follow the choose number and sort the data. */
		switch(chooseMenu){
			case 1: qsort(stu, 5, sizeof(stu[0]), id_asc);
					cout << "\n|\tID-Upper\t\t|" << endl;
					for (int j = 0; j < 5; ++j) {
						cout << "|\t" << stu[j].id << ", "
							 << stu[j].name << ", " 
							 << stu[j].score << "\t|" << endl;
					}
					break;
			case 2: qsort(stu, 5, sizeof(stu[0]), id_dec);
					cout << "\n|\tID-Lower\t\t|" << endl;
					for (int j = 0; j < 5; ++j) {
						cout << "|\t" << stu[j].id << ", "
							 << stu[j].name << ", " 
							 << stu[j].score << "\t|" << endl;
					}
					break;
			case 3: qsort(stu, 5, sizeof(stu[0]), name_asc);
					cout << "\n|\tName-Upper\t\t|" << endl;
					for (int j = 0; j < 5; ++j) {
						cout << "|\t" << stu[j].id << ", "
							 << stu[j].name << ", " 
							 << stu[j].score << "\t|" << endl;
					}
					break;
			case 4: qsort(stu, 5, sizeof(stu[0]), name_dec);
					cout << "\n|\tName-Lower\t\t|" << endl;
					for (int j = 0; j < 5; ++j) {
						cout << "|\t" << stu[j].id << ", "
							 << stu[j].name << ", " 
							 << stu[j].score << "\t|" << endl;
					}
					break;
			case 5: qsort(stu, 5, sizeof(stu[0]), score_asc);
					cout << "\n|\tScore-Upper\t\t|" << endl;
					for (int j = 0; j < 5; ++j) {
						cout << "|\t" << stu[j].id << ", "
							 << stu[j].name << ", " 
							 << stu[j].score << "\t|" << endl;
					}
					break;
			case 6: qsort(stu, 5, sizeof(stu[0]), score_dec);
					cout << "\n|\tScore-Lower\t\t|" << endl;
					for (int j = 0; j < 5; ++j) {
						cout << "|\t" << stu[j].id << ", "
							 << stu[j].name << ", " 
							 << stu[j].score << "\t|" << endl;
					}
					break;
			case 7: cout << "Thank you!!\n" << endl;
					exit(0);
					break;
			default: cout << "Your choice is incorrect, Try again." << endl;
					break;
		}
		
		/* Other questions */
		cout << "\nAny other choices?" << endl;
	}

	return 0;
}