#include<iostream>
#include "itin_methods.h"
#include <string>

using namespace std;
int main(){

int input;
string input_file;

cout << "-------------Welcome to Tailored Itinerary-----------\n";
cout << "This program will help you make your own specialized \n";
cout << "itinerary for your visit to Egypt. Make any plan for \n";
cout << " a trip to Egypt using this program and we will make \n";
cout << "it happen.\n";

cout << "\nPress 1 to create a new itinerary\n";
cout << "Press 2 to view template itineraries\n";
cout << "Press 3 to make a transaction on an exisiting itinerary\n";
cout << "press 4 cancel a trip and recieve a refund";
cout << "Press 9 at anytime to quit";

do
{
cin >> input;
if (input==1) {itinerary new_itinerary();}
else if (input==2) {
    cout << "Please Input an Exisitng File Name to View.\n";
    cout << "Available files:\n";
    listfiles("Itineraries");
    cout << "View : ";
    cin >> input_file;
    itinerary template_itinerary(input_file);
    }
else if (input==3) {
    cout << "Please Input an Exisitng File Name to Make a Purchase.";
    cout << "Available files:\n";
    listfiles("Itineraries");
    cout << "Purchase : ";
    cin >> input_file;
    itinerary purchase_itinerary(input_file);
}
else if (input==4) {

}
else if (input==9) {return 0;}
else {cout<<"Please choose one of the above options.";}
} while ((input>4&&input<1)||input!=9);

return 0;
}