#include <iostream>
#include <cstring>
#include <windows.h>   // ADD THIS
using namespace std;

struct Booking
{
    int bookingID;
    char passengerName[50];
    char destination[50];
    int seatNumber;
    char foodType[30];
};

Booking bookings[100];
int totalBookings = 0;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Add Booking
void addBooking()
{
    cout << "\n===== Add New Booking =====\n";

    cout << "Enter Booking ID: ";
    cin >> bookings[totalBookings].bookingID;

    // Unique Booking ID Check
   for(int i = 0; i < totalBookings; i++)
{
    if(bookings[i].bookingID == bookings[totalBookings].bookingID)
    {
        setColor(12);
        cout << "Booking ID already exists!\n";
        setColor(15);
        return;
    }
}

    cin.ignore();

    cout << "Enter Passenger Name: ";
    cin.getline(bookings[totalBookings].passengerName, 50);

    cout << "Enter Destination: ";
    cin.getline(bookings[totalBookings].destination, 50);

    cout << "Enter Seat Number: ";
    cin >> bookings[totalBookings].seatNumber;

    // Unique Seat Number Check
   for(int i = 0; i < totalBookings; i++)
{
    if(bookings[i].seatNumber == bookings[totalBookings].seatNumber)
    {
        setColor(12);
        cout << "Seat already booked!\n";
        setColor(15);
        return;
    }
}
int category, option;

cout << "\n===== FOOD MENU =====\n";
cout << "1. Vegetarian Meals\n";
cout << "2. Non-Vegetarian Meals\n";
cout << "3. Vegan Meals\n";
cout << "4. Special Meals\n";
cout << "Enter Category: ";
cin >> category;

switch(category)
{
    case 1:
        cout << "\n1. Vegetable Biryani\n";
        cout << "2. Paneer Rice\n";
        cout << "3. Vegetable Pasta\n";
        cout << "Select Meal: ";
        cin >> option;

        if(option == 1)
            strcpy(bookings[totalBookings].foodType,"Vegetable Biryani");
        else if(option == 2)
            strcpy(bookings[totalBookings].foodType,"Paneer Rice");
        else
            strcpy(bookings[totalBookings].foodType,"Vegetable Pasta");
        break;

    case 2:
        cout << "\n1. Chicken Biryani\n";
        cout << "2. Chicken Karahi\n";
        cout << "3. Chicken Sandwich\n";
        cout << "Select Meal: ";
        cin >> option;

        if(option == 1)
            strcpy(bookings[totalBookings].foodType,"Chicken Biryani");
        else if(option == 2)
            strcpy(bookings[totalBookings].foodType,"Chicken Karahi");
        else
            strcpy(bookings[totalBookings].foodType,"Chicken Sandwich");
        break;

    case 3:
        cout << "\n1. Vegan Salad\n";
        cout << "2. Vegan Burger\n";
        cout << "3. Vegan Wrap\n";
        cout << "Select Meal: ";
        cin >> option;

        if(option == 1)
            strcpy(bookings[totalBookings].foodType,"Vegan Salad");
        else if(option == 2)
            strcpy(bookings[totalBookings].foodType,"Vegan Burger");
        else
            strcpy(bookings[totalBookings].foodType,"Vegan Wrap");
        break;

    case 4:
        cout << "\n1. Diabetic Meal\n";
        cout << "2. Low Salt Meal\n";
        cout << "3. Kids Meal\n";
        cout << "Select Meal: ";
        cin >> option;

        if(option == 1)
            strcpy(bookings[totalBookings].foodType,"Diabetic Meal");
        else if(option == 2)
            strcpy(bookings[totalBookings].foodType,"Low Salt Meal");
        else
            strcpy(bookings[totalBookings].foodType,"Kids Meal");
        break;
}

    

    totalBookings++;
    setColor(10);
cout << "\nBooking Added Successfully!\n";
setColor(15);


    
}

// Display Bookings
void displayBookings()
{
    if(totalBookings == 0)
    {
        cout << "\nNo bookings found.\n";
        return;
    }

    cout << "\n===== All Bookings =====\n";

    for(int i = 0; i < totalBookings; i++)
    {
        cout << "\nBooking #" << i + 1 << endl;
        cout << "Booking ID: " << bookings[i].bookingID << endl;
        cout << "Passenger Name: " << bookings[i].passengerName << endl;
        cout << "Destination: " << bookings[i].destination << endl;
        cout << "Seat Number: " << bookings[i].seatNumber << endl;
        cout << "Food Type: " << bookings[i].foodType << endl;
    }
}

// Search Booking
void searchBooking()
{
    int id;
    bool found = false;

    cout << "\nEnter Booking ID to Search: ";
    cin >> id;

    for(int i = 0; i < totalBookings; i++)
    {
        if(bookings[i].bookingID == id)
        {
            cout << "\nBooking Found!\n";
            cout << "Passenger Name: " << bookings[i].passengerName << endl;
            cout << "Destination: " << bookings[i].destination << endl;
            cout << "Seat Number: " << bookings[i].seatNumber << endl;
            cout << "Food Type: " << bookings[i].foodType << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Booking not found.\n";
    }
}

// Update Booking
void updateBooking()
{
    int id;
    bool found = false;

    cout << "\nEnter Booking ID to Update: ";
    cin >> id;

    for(int i = 0; i < totalBookings; i++)
    {
        if(bookings[i].bookingID == id)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Passenger Name: ";
            cin.getline(bookings[i].passengerName, 50);

            cout << "Enter New Destination: ";
            cin.getline(bookings[i].destination, 50);

            cout << "Enter New Seat Number: ";
            cin >> bookings[i].seatNumber;

            cin.ignore();

            cout << "Enter New Food Type: ";
            cin.getline(bookings[i].foodType, 30);

            cout << "\nBooking Updated Successfully!\n";
            break;
        }
    }

    if(!found)
    {
        cout << "Booking ID not found.\n";
    }
}

// Delete Booking
void deleteBooking()
{
    int id;
    bool found = false;

    cout << "\nEnter Booking ID to Delete: ";
    cin >> id;

    for(int i = 0; i < totalBookings; i++)
    {
        if(bookings[i].bookingID == id)
        {
            found = true;

            for(int j = i; j < totalBookings - 1; j++)
            {
                bookings[j] = bookings[j + 1];
            }

            totalBookings--;

            cout << "\nBooking Deleted Successfully!\n";
            break;
        }
    }

    if(!found)
    {
        cout << "Booking ID not found.\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
setColor(11);
cout << "\n====================================";
cout << "\n     AIR FLIGHT BOOKING SYSTEM";
cout << "\n====================================\n";
setColor(15);
        cout << "\n1. Add Booking";
        cout << "\n2. View All Bookings";
        cout << "\n3. Search Booking";
        cout << "\n4. Update Booking";
        cout << "\n5. Delete Booking";
        cout << "\n6. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addBooking();
                break;

            case 2:
                displayBookings();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                updateBooking();
                break;

            case 5:
                deleteBooking();
                break;

            case 6:
                cout << "\nThank You For Using Air Flight Booking System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while(choice != 6);

    return 0;
}