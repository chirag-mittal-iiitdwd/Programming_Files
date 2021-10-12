/*
    Write and execute a C++ program to demonstrate the working of a movie ticket
    reservation system for XYZ theater using a class and array of objects. The XYZ theater
    has 3 kinds of tickets - Silver, Gold, and Platinum, which has 50, 30, and 20 seats and costs
    Rs. 120, 150 and 200 respectively.


    The application should initially show the number of seats booked and a number of seats
    available for booking. While booking, the user should be prompted to enter the number of
    seats and the kind of seat for booking and should be displayed the amount he/she has to
    pay. The booking process should continue until a user no longer wants to book tickets. Use
    appropriate variables as data members and required member functions to demonstrate this
    application. Also, the outputs and prompts should be appropriately and clearly displayed
    so that there is no ambiguity for the user of this application.
*/


#include<bits\stdc++.h>
using namespace std;

class ticket{
    public:
    int silver,silverSold,silverCost;
    int gold,goldSold,goldCost;
    int platinum,platinumSold,platinumCost;
    ticket(){
        cout<<"We are open now"<<endl;
        silver=50;
        gold=30;
        platinum=20;
        silverCost=120;
        goldCost=150;
        platinumCost=200;
        silverSold=0;
        goldSold=0;
        platinumSold=0;
    }

    void showSeatsBooked(){
        cout<<"Platinum tickets sold : "<<platinumSold<<", Out Of "<<platinum<<endl;
        cout<<"Gold tickets sold : "<<goldSold<<", Out Of "<<gold<<endl;
        cout<<"Silver tickets sold : "<<silverSold<<", Out Of "<<silver<<endl;
        cout<<endl;
        cout<<endl;
    }

    void bookPlatinum(int n){
        if(platinum>=n){
            cout<<"PLease Pay Rupees : "<<n*platinumCost<<endl;
            cout<<"You just booked your "<<n<<" platinum tickets. Enjoy !!!"<<endl;
            platinum=platinum-n;
        }
        else if(platinum<n && platinum>0){
            cout<<"We Only have "<<platinum<<" Platinum tickets"<<endl;
            int choice1;
            cout<<"Enter 1 if you want to book all the left out tickets\nEnter 0 for exiting : ";
            cin>>choice1;
            if(choice1==1){
                cout<<"PLease Pay Rupees : "<<platinum*platinumCost<<endl;
                cout<<"You just booked your "<<platinum<<" platinum tickets. Enjoy !!!"<<endl;
                platinum=0;
            }else{
                cout<<"exiting now!!, We are sorry for the trouble"<<endl;
            }
        }
        else{
            cout<<"Sorry All Platinum tickets are sold, You can try other categories"<<endl;
            showSeatsBooked();
        }
    }

    void bookSilver(int n){
        if(silver>=n){
            cout<<"PLease Pay Rupees : "<<n*silverCost<<endl;
            cout<<"You just booked your "<<n<<" silver tickets. Enjoy !!!"<<endl;
            silver-=n;
        }
        else if(silver<n && silver>0){
            cout<<"We Only have "<<silver<<" Silver tickets"<<endl;
            int choice1;
            cout<<"Enter 1 if you want to book all the left out tickets\nEnter 0 for exiting : ";
            cin>>choice1;
            if(choice1==1){
                cout<<"PLease Pay Rupees : "<<silver*silverCost<<endl;
                cout<<"You just booked your "<<silver<<" silver tickets. Enjoy !!!"<<endl;
                platinum=0;
            }else{
                cout<<"exiting now!!, We are sorry for the trouble"<<endl;
            }
        }
        else{
            cout<<"Sorry All Silver tickets are sold, You can try other categories"<<endl;
            showSeatsBooked();
        }
    }

    void bookGold(int n){
        if(gold>=n){
            cout<<"PLease Pay Rupees : "<<n*goldCost<<endl;
            cout<<"You just booked your "<<n<<" gold tickets. Enjoy !!!"<<endl;
            gold-=n;
        }
        else if(gold<n && gold>0){
            cout<<"We Only have "<<gold<<" gold tickets"<<endl;
            int choice1;
            cout<<"Enter 1 if you want to book all the left out tickets\nEnter 0 for exiting : ";
            cin>>choice1;
            if(choice1==1){
                cout<<"PLease Pay Rupees : "<<gold*goldCost<<endl;
                cout<<"You just booked your "<<gold<<" gold tickets. Enjoy !!!"<<endl;
                gold=0;
            }else{
                cout<<"exiting now!!, We are sorry for the trouble"<<endl;
                showSeatsBooked();
            }
        }
        else{
            cout<<"Sorry All gold tickets are sold, You can try other categories"<<endl;
        }
    }
};

int main(){
    cout<<"Welcome to XYZ theater reservation"<<endl;
    ticket t;

    int breakCondition=0;
    int choice;
    while(!breakCondition){
        cout<<endl;
        cout<<endl;
        t.showSeatsBooked();
        cout<<"Enter 1 for booking Platinum seats"<<endl;
        cout<<"Enter 2 for booking Gold tickets"<<endl;
        cout<<"Enter 3 for booking Silver tickets"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                int numberOfTickets;
                cout<<"Enter number of tickets : ";
                cin>>numberOfTickets;
                t.bookPlatinum(numberOfTickets);

                cout<<endl;
                cout<<endl;
            
                cout<<"If you want to book more tickets or go into different category\nPress 0 or else press 1 : ";
                cin>>breakCondition;
                break;
            case 2:
                int numberOfTickets1;
                cout<<"Enter number of tickets : ";
                cin>>numberOfTickets1;
                t.bookGold(numberOfTickets1);
                cout<<endl;
                
                cout<<"If you want to book more tickets or go into different category\nPress 0 or else press 1 : ";
                cin>>breakCondition;
                break;
            case 3:
                int numberOfTickets3;
                cout<<"Enter number of tickets : ";
                cin>>numberOfTickets3;
                t.bookSilver(numberOfTickets3);
                cout<<endl;
                cout<<endl;
                
                cout<<"If you want to book more tickets or go into different category\nPress 0 or else press 1 : ";
                cin>>breakCondition;
                break;
            default:
                cout<<"Invalid Choice, Please try again !!! "<<endl;\
                break;
        }
    }
}