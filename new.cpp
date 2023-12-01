#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<algorithm>
#include<cctype>
#include<stdexcept>
using namespace std;

int generate_random(int a,int b)
{
    int temp=rand();
    temp=temp%(b-a);
    return temp;
}

class pet
{
    string name;
    int hung,happ,energy,age,amount=10;
    public:
    pet(){}
    pet(string s):name(s){
    hung=generate_random(0,100);
    happ=generate_random(0,100);
    energy=generate_random(0,100);
    age=5;
    }
    pet(ifstream &i)
    {
        string s;
        getline(i,s);
        name=s;
        getline(i,s);
        hung=stoi(s);
        getline(i,s);
        happ=stoi(s);
        getline(i,s);
        energy=stoi(s);
        getline(i,s);
        age=stoi(s);
    }

    void inc_hung()
    {
        int a=age/15;
        amount+=a;
        if(amount>15)
        amount=15;
        hung=min(100,hung+amount);
    }
    void inc_happ()
    {
        int a=age/15;
        amount+=a;
        if(amount>15)
        amount=15;
        happ=min(100,happ+amount);
    }
    void inc_energy()
    {
        int a=age/15;
        amount+=a;
        if(amount>15)
        amount=15;
        energy=min(100,energy+amount);
    }
    void dec_hung()
    {
        int a=age/15;
        amount-=a;
        if(amount<4)
        amount=4;
        hung=max(0,hung-amount);
    }
    void dec_happ()
    {
        int a=age/15;
        amount-=a;
        if(amount<4)
        amount=4;
        happ=max(0,happ-amount);
    }
    void dec_energy()
    {
        int a=age/15;
        amount-=a;
        if(amount<4)
        amount=4;
        energy=max(0,energy-amount);
    }
    void feed()
    {
        cout<<"Feeding the pet...\n";
        if(hung!=0)
        dec_hung();
        else
        cout<<"I am full, Let's do some other tasks.\n";
        inc_happ();
        if(energy>20)
        if(energy<20){
        cout<<"My energy is low. Please let me take some rest."<<endl;
        }
        else
        dec_energy();
    }
    void play()
    {
        cout<<"The pet is playing...\n";
        inc_hung();
        if(hung>90)
        cout<<"I am feeling hungry, Let's go and have some food.\n";
        inc_happ();
        inc_happ();
        if(energy<20){
        cout<<"Energy is very low. Please rest the pet."<<endl;
        }
        else
        dec_energy();
    }
    void rest()
    {
        cout<<"The pet is taking rest...\n";
        if(happ>20)
        dec_happ();
        if(happ<20)
        {
            cout<<"I am bored! Let's do something.\n"<<endl;
        }
        inc_energy();
        inc_energy();
        inc_energy();
        age+=5;
    }
    void query()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Hunger Levels: "<<hung<<endl;
        cout<<"Happiness Levels: "<<happ<<endl;
        cout<<"Energy Levels: "<<energy<<endl;
        cout<<"Age: "<<age<<endl;
    }
    friend void save(pet& p);
};

void save(pet& p){
    string filename=p.name+".txt";
    ofstream o;
    o.open(filename.c_str());
    o<<p.name<<endl<<p.hung<<endl<<p.happ<<endl<<p.energy<<endl<<p.age;
    o.close();
}

void operations(pet& m)
{
    string y="1";
    while(y[0]=='1' && y[1]=='\0')
    {
        string k;
        cout<<"Enter the corresponding number to perform an operation: "<<endl;
        cout<<"1. Feed\n2. Play\n3. Rest\n4. Query\n";
        cin>>k;
        if(k[0]=='1' && k[1]=='\0')
        m.feed();
        else if(k[0]=='2' && k[1]=='\0')
        m.play();
        else if(k[0]=='3' && k[1]=='\0')
        m.rest();
        else if(k[0]=='4' && k[1]=='\0')
        m.query();
        else
        cout<<"Invalid input\n";
        while(1){
        cout<<"Do you want to perform another operation(0 or 1): ";
        cin>>y;
        if((y[0]=='1' && y[1]=='\0') || (y[0]=='0' && y[1]=='\0'))
        break;
        else
        cout<<"Invalid input\n";
        }
    }
    string u;
    while(1){
    cout<<"Do you want to save the progress(1 or 0): ";
    cin>>u;
    if(u[0]=='1' && u[1]=='\0'){
    save(m);
    break;
    }
    if(u[0]=='0' && u[1]=='\0'){
    cout<<"The file is not saved\n";
    break;
    }
    else
    cout<<"Invalid input.\n";
    }
}

int main(){
    string w="1";
    cout<<"SIMULATION SESSION STARTED\n\n";
    while(w[0] =='1' && w[1]=='\0'){
    int a;
    string h,filen,_p;
    cout<<"Enter the name of pet: ";
    cin>>h;
    filen=h+".txt";
    try
    {
        for(int j=0;j<h.length();j++)
        {
            if(!isalpha(h[j]))
            throw h[j];
        }
    }
    catch(char c)
    {
        cout<<"Please name the pet with only alphabet, don't use any other characters\n";
        continue;
    }
    ifstream i(filen.c_str());
    if(!i){
    pet p(h);
    operations(p);
    }
    else{
    string g;
    cout<<"A pet with this name already exists. If you want to create a new pet press \"0\" and enter a different pet name: \n";
    cout<<"If you want to use the same pet press some other key :\n";
    cin>>g;
    if(g[0]=='0' && g[1]=='\0')
    continue;
    else{
    pet p(i);
    operations(p);
    }
    }
    while(1){
    cout<<"Do you have another pet(1 or 0)? ";
    cin>>w;
    if(w[0]=='1' && w[1]=='\0')
    break;
    if(w[0]=='0' && w[1]=='\0')
    {
    cout<<"\nSIMULATION SESSION COMPLETED\n";
    return 0;
    }
    else
    cout<<"Invalid entry\n";
    }
    }
    return 0;
}
