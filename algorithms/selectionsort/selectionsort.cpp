#include <iostream>
using namespace std;

class Date {
public:
    int year;
    int day;
    int month;

    void setter(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
};

void selectionSort(Date objs[], int length) {
    int i, j;
    for (i = 0; i < length - 1; i++) {
        int min_pos = i;
        for (j = i + 1; j < length; j++) {
            if (objs[j].year < objs[min_pos].year) {
                min_pos = j;
            } else if (objs[j].year == objs[min_pos].year && objs[j].month < objs[min_pos].month) {
                min_pos = j;
            } else if (objs[j].year == objs[min_pos].year && objs[j].month == objs[min_pos].month && objs[j].day < objs[min_pos].day) {
                min_pos = j;
            }
        }
        Date temp = objs[i];
        objs[i] = objs[min_pos];
        objs[min_pos] = temp;
    }
}

int main() 
{
    Date obj[5];
    int i, a, b, c; //a, b, c are variables which will store month, day, year in the for-loop
    for (i = 0; i < 5; i++) {
        cout << "Enter Day, Month, Year: ";
        cin >> a >> b >> c;
        obj[i].setter(a, b, c);
    }
    
    selectionSort(obj, 5);

    cout << "Displaying Sorted Dates." << endl;
    for (i = 0; i < 5; i++) {
        cout << "Date " << i + 1 << ": " << obj[i].day << "/" << obj[i].month << "/" << obj[i].year << endl;
    }
    return 0;
}
