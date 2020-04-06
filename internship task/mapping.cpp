#include<bits/stdc++.h>
using namespace std;

class person{
    private:
    long userId;
    char gender;
    char genderPref;
    double lattitue;
    double longitude;
    public:
    person(long userId,char gender, char genderPref,double lattitude, double longitude){
        userId=userId;
        gender=gender;
        genderPref=genderPref;
        lattitude=lattitude;
        longitude=longitude;
    }
    long getUser(){
        return userId;
    }
    char getGender(){
        return gender;
    }
    char getGenderPreferance(){
        return genderPref;
    }
    double getLattitude(){
        return lattitue;
    }
    double getLongitude(){
        return longitude;
    }




};

static double haversine(double lat1, double lon1, double lat2, double lon2) 
    { 
        // distance between latitudes 
        // and longitudes 
        double dLat = (lat2 - lat1) * 
                      M_PI / 180.0; 
        double dLon = (lon2 - lon1) *  
                      M_PI / 180.0; 
  
        // convert to radians 
        lat1 = (lat1) * M_PI / 180.0; 
        lat2 = (lat2) * M_PI / 180.0; 
  
        // apply formulae 
        double a = pow(sin(dLat / 2), 2) +  
                   pow(sin(dLon / 2), 2) *  
                   cos(lat1) * cos(lat2); 
        double rad = 6371; 
        double c = 2 * asin(sqrt(a)); 
        return rad * c; 
    } 




int main(){
    set<class person> peopleSet;
    person p1(100,'F','F',51.5107,0.1256);
    person p2(101,'F','M',40.5007,74.0445);
    person p3(102,'M','F',51.5112,0.1236);
    peopleSet.insert(p1);
    peopleSet.insert(p2);
    peopleSet.insert(p3);

    inRadius(peopleSet);

};
  

