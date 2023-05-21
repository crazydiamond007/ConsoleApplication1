#include <iostream>
#include <cstring>
using namespace std;


struct date
{
    int day, month, year;
};
struct car
{
    int ID;
    char owner_name[20], owner_surname[20], model[20];
    struct date reg_date, service_date;
    char phone_no[20];
}
car_directory[100];

void displaymenu();
void add_cars(int);
int delete_car(int);
void list_cars(int);
void Search_a_car(int);
void update_car(int);
void sort_by_id(int);
void sort_byowner_name(int);
int main()
{
  
    int number_cars = 0, choice;
    do
    {
        displaymenu();
        cout << "Please enter your choice :";
            cin >> choice;
        switch (choice)
        {case 1:
            add_cars(number_cars);
            number_cars++;
            break;
        case 2:
            int del;
            del = delete_car(number_cars);
            if (del == 1)
                number_cars--;
            break;
        case 3:
            list_cars(number_cars);
            break;
        case 4:
            Search_a_car(number_cars);
            break;
        case 5:
            update_car(number_cars);
            break;
        case 6:
            sort_by_id(number_cars);
            break;
        case 7:
            sort_byowner_name(number_cars);
            break;
        case 8:
            cout << "\n\nExit programme......\n\n";
            break;  
        default:
            cout << "\n\nInvalid choice\n\n";
            break;
        }
    } while (choice!=8);

}
void displaymenu()
{
    cout << "1-Add a new car to directory" << endl;
    cout << "2-Delete a car from the diectory" << endl;
    cout << "3-List available cars in the directory" << endl;
    cout << "4- Search a car :" << endl;
    cout << " \t A- Search accaording to car id" << endl;
    cout << "\t B- Search according to owner_name" << endl;
    cout << "5- Update car information" << endl;
    cout << "6- Sort according to car id" << endl;
    cout << "7-Sort according to owner_name" << endl;
    cout << "8-Quit" << endl;
}
void add_cars(int numberofcars) {
    if (numberofcars >= 100) {
        cout << "the directory is full" << endl;
        return;
    }
    cout << "Please enter the car Id: ";
    cin >> car_directory[numberofcars].ID;
    cout << "Please enter the owner name of car: ";
    cin >> car_directory[numberofcars].owner_name;
    cout << "Please enter the owner surname of the car: ";
    cin >> car_directory[numberofcars].owner_surname;
    cout << "Please enter the model of the car: ";
    cin >> car_directory[numberofcars].model;
    cout << "Please enter the registration information: "<<endl;
    cout << "day: ";
    cin >> car_directory[numberofcars].reg_date.day;
    cout << "month: ";
    cin >> car_directory[numberofcars].reg_date.month;
    cout << "year: ";
    cin >> car_directory[numberofcars].reg_date.year;
    cout << "Please enter services informtions: "<<endl;
    cout << "day: ";
    cin >> car_directory[numberofcars].service_date.day;
    cout << "month: ";
    cin >> car_directory[numberofcars].service_date.month;
    cout << "year: ";
    cin >> car_directory[numberofcars].service_date.year;
    cout << "Please enter owner phone number: ";
    cin >> car_directory[numberofcars].phone_no;
    cout << "\n\nYou successfully add a new car.\n\n";

}
int delete_car(int numbersofcars) {
    int found = 0, id,del=0;
    cout << "Please enter the id of car: ";
    cin >> id;
    for ( int i = 0;  i < numbersofcars; i++)
    {
        if (car_directory[i].ID == id) { 
            found = 1;
            del = 1;
            for (int j = i; j < numbersofcars; j++)
            {
                car_directory[j] = car_directory[j+1];
            }
            cout << "\n\nthe car is successfully deleted!!!\n\n";
        }
    }if (found == 0) {
        cout << "\n\nno car found with this id " << id << endl;

    }
    return del;
}
void list_cars(int numberofcars) {
    if (numberofcars == 0)
        cout << "\n\nthe directory is empty\n\n";
    cout << "\n\nthis is the list of cars: \n\n";
    for ( int i = 0; i <numberofcars ; i++)
    {
        cout << car_directory[i].ID << "\t" << car_directory[i].owner_name << "\t" 
            << car_directory[i].owner_surname << "\t" << car_directory[i].model << "\t"
            << car_directory[i].phone_no << "\t" << car_directory[i].reg_date.day << "/" << car_directory[i].reg_date.month 
            << "/" << car_directory[i].reg_date.year << "\t" << car_directory[i].service_date.day << "/"
            << car_directory[i].service_date.month << "/" << car_directory[i].service_date.year << endl;

    }
    cout << "\n\n";
}
void Search_a_car(int numberofcars) {
    char choice,owner_name[20];
    int id;
    cout << "Search your car : " << endl;
    cout << "A- by id" << endl;
    cout << "B- by owner name" << endl;
    cout << "please enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 'A':
        cout << "Please entre the id of the car: ";
        cin >> id;

        for (int i = 0; i <numberofcars ; i++)
        {
            if (car_directory[i].ID == id) { 
                cout << "This your car: " << endl;
                cout << car_directory[i].ID << "\t" << car_directory[i].owner_name << "\t"
                    << car_directory[i].owner_surname << "\t" << car_directory[i].model << "\t"
                    << car_directory[i].phone_no << "\t" << car_directory[i].reg_date.day << "/" << car_directory[i].reg_date.month
                    << "/" << car_directory[i].reg_date.year << "\t" << car_directory[i].service_date.day << "/"
                    << car_directory[i].service_date.month << "/" << car_directory[i].service_date.year << endl;

                cout << "\n\n";
            }
        }

        break;
    case 'B':
        cout << "Please enter the owner name of car: ";
        cin >> owner_name;
        for (int i = 0; i < numberofcars; i++)
        {
            if (strcmp(owner_name, car_directory[i].owner_name) == 0)
            {
                cout << "This your car:" << endl;
                cout << car_directory[i].ID << "\t" << car_directory[i].owner_name << "\t"
                    << car_directory[i].owner_surname << "\t" << car_directory[i].model << "\t"
                    << car_directory[i].phone_no << "\t" << car_directory[i].reg_date.day << "/" << car_directory[i].reg_date.month
                    << "/" << car_directory[i].reg_date.year << "\t" << car_directory[i].service_date.day << "/"
                    << car_directory[i].service_date.month << "/" << car_directory[i].service_date.year << endl;
                cout << "\n\n";
            }

        }
        break;
    default :
        cout << "\n\nInvalid choice,please try again\n\n";
        break;
    }
    
}
void update_car(int numberofcars) {
    int id,found=0;
    cout << "Please enter the car ID: ";
    cin >> id;
    for (int i = 0; i < numberofcars; i++)
    {
        if (car_directory[i].ID == id) {
            cout << "Please enter the car Id:";
            cin >> car_directory[i].ID;
            cout << "Please enter the owner name of car:";
            cin >> car_directory[i].owner_name;
            cout << "Please enter the owner surname of the car:";
            cin >> car_directory[i].owner_surname;
            cout << "Please enter the model of the car:";
            cin >> car_directory[i].model;
            cout << "Please enter the registration information:";
            cout << "day: ";
            cin >> car_directory[i].reg_date.day;
            cout << "month: ";
            cin >> car_directory[i].reg_date.month;
            cout << "year : ";
            cin >> car_directory[i].reg_date.year;
            cout << "Please enter services informtions:";
            cout << "day : ";
            cin >> car_directory[i].service_date.day;
            cout << "month : ";
            cin >> car_directory[i].service_date.month;
            cout << "year : ";
            cin >> car_directory[i].service_date.year;
            cout << "Please enter owner phone number : ";
            cin >> car_directory[i].phone_no;
            cout << "\n\nYou successfully update new car.\n\n";
        }
    }if (found == 0)
        cout << "\n\nNo car found with this car ID" << id << "\n\n";
    
}
void sort_by_id(int numberofcars) {
    struct car temp;
    for (int i = 0; i < numberofcars-1; i++)
    {
        for (int j = 0; j < numberofcars - i - 1; j++) {
            if (car_directory[j].ID > car_directory[j + 1].ID) {

                temp = car_directory[j];
                car_directory[j] = car_directory[j + 1];
                car_directory[j + 1] = temp;
                cout << "\n\nYou succesfully sorting the directory by id\n\n";
            }
        }
    }
}
void sort_byowner_name(int numberofcars) {
    struct car temp;
    for (int i = 0; i < numberofcars - 1; i++)
    {
        for (int j = 0; j < numberofcars - i - 1; j++) {
            if (strcmp(car_directory[j].owner_name,car_directory[j+1].owner_name)>0) {

                temp = car_directory[j];
                car_directory[j] = car_directory[j + 1];
                car_directory[j + 1] = temp;
                cout << "\n\nYou succesfully sorting the directory by owner name\n\n";
            }
        }
    }
}


