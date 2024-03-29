#include <iostream>
#include "itin_methods.hpp"
#include <string>
#include <filesystem>

using namespace std;
int main(){

int input;
int reciept_number;
int flag=0;
string input_file;

cout << "-------------Welcome to Tailored Itinerary-----------\n";
cout << "This program will help you make your own specialized \n";
cout << "itinerary for your visit to Egypt. Make any plan for \n";
cout << " a trip to Egypt using this program and we will make \n";
cout << "it happen.\n";
cout << "\n";
cout << "Press 1 to create a new itinerary\n";
cout << "Press 2 to view template itineraries\n";
cout << "Press 3 to make a transaction on an exisiting itinerary\n";
cout << "press 4 cancel a trip and recieve a refund\n";
cout << "Press 9 at anytime to quit\n";

do
{
cin >> input;
if (input==1) {
    // do I need dynamic mem allocation?
    itinerary * new_itinerary = new itinerary;
    new_itinerary->create_itinerary();
    cout << "Itinerary Created successfully."<< endl;
    // consider using do while loop for all of main so that user can go back to menu after here.
}
else if (input==2) { 
    itinerary *template_itinerary = new itinerary;
    
    cout << "Please Input an Exisitng File Name to View.\n";
    cout << "Available files: " << endl;
    listfiles("Itineraries");
    do {
        cout << "\nView : ";
        cin >> input_file;
        template_itinerary->set_file_name(input_file);
        flag = template_itinerary->file_existence_check(template_itinerary->file_name);
        if (!flag){cout << "Please Input an Exisiting File Name." << endl;}
    } while(!flag);
    template_itinerary->view_itinerary();
}
else if (input==3) {
    int input_2=0;
    itinerary * buy_itinerary = new itinerary;
    
    cout << "Please Input an Existing File Name to Make a Purchase.\n";
    cout << "Available files: " << endl;
    listfiles("Itineraries");
    do {
        cout << "Purchase : ";
        cin >> input_file;
        buy_itinerary->set_file_name(input_file);
        flag = buy_itinerary->file_existence_check(buy_itinerary->file_name);
        if (!flag){cout << "Please Input an Exisiting File Name." << endl;}
    } while (!flag);
    buy_itinerary->calculate_price();
    cout << "Press 1 to Make a Purchase\nPress 9 to Quit the Program\n";
    do {
        cin >> input_2;
        if (input_2==9) {return 0;}
        else if (input_2==1){
        buy_itinerary->purchase_itinerary();
        }
        else {cout << "Invalid Input.\n";}
    } while (input_2!=1);
}
else if (input==4) {
    cout << "Please Input Your Receipt Number Below.\n";
    cout << "Reciept Number:";
    cin >> reciept_number;

    // In the future, find a way to check if reciept number is valid by storing
    // all reciept numbers given out to customers in an external database and then 
    // checking with this database at this step. The database would also contain
    // the type of itinerary bought. For now, the code will continue assuming
    // this step is implemented, allowing this to be step to be implemented later 

    itinerary cancel_itinerary;
    cancel_itinerary.refund_itinerary();
}
else if (input==9) {return 0;}
else {cout<<"Please choose one of the above options.\n";}
} while (input>4||input<1);

return 0;
}