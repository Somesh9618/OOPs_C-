//polymorphism

#include <bits/stdc++.h>
#include <iostream>
#include <list>

using namespace std;
//base class
class youTubeChannel{   
private:
    string Name;
    int subCount;
    list<string>Uploads;
protected:
    string OwnerName;
    int ContentQuality;
public:
    youTubeChannel(string name,string ownerName){ //constructor
        Name = name;
        OwnerName = ownerName;
        subCount = 0;
        ContentQuality=0;
    }
    
    void GetInfo(){
        cout << "name : " << Name <<endl;
        cout << "ownerName : " << OwnerName <<endl;
        cout << "subCount : " << subCount <<endl;     //class methods
        cout << "uploads :" <<endl;
        for(string videoTitle:Uploads){
           cout << videoTitle <<" "<<"\n";
        }
    }
    
    void Subscribe(){
        subCount++;
    }
    
    void Unsubscribe(){
        if(subCount > 0)
          subCount--;
    }
    
    void Pubishvideo(string title){
        Uploads.push_back(title);
    }
    
    void ContentAnalatics(){
        if(ContentQuality < 5){
            cout << Name <<" has bad quality of videos" <<endl;
        }
        else{
            cout << Name << " has a very good Content" << endl;
        }
    }
};

//derived class
class CookingYoutubeChannel:public youTubeChannel{  
public:
   CookingYoutubeChannel(string name,string ownerName) : youTubeChannel(name,ownerName){
       
   }
   
   void Practice(){
       cout << OwnerName << " is practicing and experrimentnting" << endl;
       ContentQuality++;
   }
   
};

class VlogingYoutubeChannel:public youTubeChannel{  
public:
   VlogingYoutubeChannel(string name,string ownerName) : youTubeChannel(name,ownerName){
       
   }
   
   void Practice(){
       cout << OwnerName << " is vloging and experrimentnting" << endl;
       ContentQuality++;
   }
   
};

int main()
{
    CookingYoutubeChannel CookingYtChannel("Somesh","Dualipa");
    VlogingYoutubeChannel VlogingYtChannel("sam","tric");
    
    CookingYtChannel.Practice();
    VlogingYtChannel.Practice();
    CookingYtChannel.Practice();
    VlogingYtChannel.Practice();
    VlogingYtChannel.Practice();
    VlogingYtChannel.Practice();
    VlogingYtChannel.Practice();
    VlogingYtChannel.Practice();
    VlogingYtChannel.Practice();
    
    youTubeChannel *yt = &CookingYtChannel;
    youTubeChannel *xt = &VlogingYtChannel;
    yt->ContentAnalatics();
    xt->ContentAnalatics();
    
    
    return 0;
}
