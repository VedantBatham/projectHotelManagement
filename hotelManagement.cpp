#include<bits/stdc++.h>
using namespace std;
void setdata(string tp,map<string,vector<string>>&mp)
{
    int no_of_rooms;
    cout<<"Please enter the no of "<<tp<<" rooms: ";
    cin>>no_of_rooms;
    vector<string>vstats(no_of_rooms,"UB");
    mp[tp]=vstats;
}
void check_status(map<string,vector<string>>&mpstats,string roomcat)
{
    for(auto it:mpstats)
    {
        if(it.first==roomcat)
        {
            cout<<it.first<<": ";
            for(auto val:it.second)
            {
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    auto itsize=mpstats.find(roomcat);
    int count=0,ub=0;
    if(itsize!=mpstats.end())
    {
        cout<<"Total no of rooms="<<itsize->second.size()<<endl;
        cout<<"Rooms available for booking are: ";
        for(auto num:itsize->second)
        {
            ++count;
            if(num=="UB")
            {
                cout<<count<<" ";
                ub++;
            }
        }
    }
    else
    {
        cout<<"Category doesn't exist"<<endl;
    }
    cout<<endl;
    cout<<"Total number of booked rooms: "<<(itsize->second.size())-ub;
}
void check_in(map<string,vector<string>>&mpbook, string roomcat)
{
    auto itbook=mpbook.find(roomcat);
    int count=0;
    vector<int>bookedrooms;
    if(itbook!=mpbook.end())
    {
        cout<<"Rooms available for booking: ";
        for(auto book:itbook->second)
        {
            ++count;
            if(book=="UB")
            {
                cout<<count<<" ";
                bookedrooms.push_back(count);
            }
        }
    }
    else
    {
        cout<<"Room category doesn't exist"<<endl;
    }
    int room_no;
    cout<<endl;
    cout<<"Please enter the room no to book the desired room: ";
    cin>>room_no;
    int presence=0;
    for(int val:bookedrooms)
    {
        if(room_no==val)
        {
            presence++;
            itbook->second[room_no-1]="B";
            cout<<"Room Booked Successfully"<<endl;
            break;
        }
    }
    if(presence==0)
    {
        cout<<"Invalid room selected"<<endl;
    }
    cout<<endl;
    check_status(mpbook,roomcat);

}
void check_out(map<string,vector<string>>&mpcheckout,string roomcat)
{
    auto itout=mpcheckout.find(roomcat);
    int count=0;
    vector<int>to_check_out;
    if(itout!=mpcheckout.end())
    {
        cout<<"Rooms Booked are: ";
        for(auto val:itout->second)
        {
            ++count;
            if(val=="B")
            {
                cout<<count<<" ";
                to_check_out.push_back(count);
            }
        }
    }
    else
    {
        cout<<"Room category doesn't exist"<<endl;
    }
    int room_no;
    cout<<endl;
    int presence=0;
    cout<<"Please enter the room number to check out: ";
    cin>>room_no;
    for(auto num:to_check_out)
    {
        if(room_no==num)
        {
            presence++;
            itout->second[room_no-1]="UB";
            cout<<"Room Checked out Successfully"<<endl;
            break;
        }
    }
    if(presence==0)
    {
        cout<<"Invalid room selected";
    }
    cout<<endl;
    check_status(mpcheckout,roomcat);
}
int main()
{
    int type_count;
    map<string,vector<string>>m;
    cout<<"Enter the no of categories of room: ";
    cin>>type_count;
    cin.ignore();
    vector<string>type;
    cout<<"Please specify the category of rooms available: "<<endl;
    for(int i=0;i<type_count;i++)
    {
        string type_of_room;
        getline(cin,type_of_room);
        type.push_back(type_of_room);
    }
    for(int j=0;j<type.size();j++)
    {
        setdata(type[j],m);
    }
    cout<<endl;
    char ch;
    while(true)
    {
        int choice;
        string select_room_type;
        cout<<"Please select the category of room: ";
        cin>>select_room_type;
        cout<<endl;
        cout<<"Enter 1 to check the current status"<<endl;
        cout<<"Enter 2 to check in"<<endl;
        cout<<"Enter 3 to check out"<<endl;
        cout<<endl;
        cout<<"Please enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                check_status(m,select_room_type);
                break;
            }
            case 2:
            {
                check_in(m,select_room_type);
                break;
            }
            case 3:
            {
                check_out(m,select_room_type);
                break;
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
                break;
            }
        }
        cout<<endl;
        cout<<"Press N to revalidate data else enter any character: ";
        cin>>ch;
        if(ch=='N')
        {
            cout<<"Run Again to start new entry"<<endl;
            break;
        }
        
    }
}