#include<bits/stdc++.h>
using namespace std;

using Face = vector<vector<string>>;
using Cube = vector<vector<vector<string>>>;
Cube cube(6, Face(2, vector<string>(2)));


void view(Cube cube){
    Face face = cube[0];
    for(auto i: face){
        cout<<"    ";
        for(auto j: i) cout<<j;
        cout<<endl;
    }
    cout<<endl;
    for(int r=0; r<face.size(); r++){
        for(int i=1; i<=4; i++){
            face = cube[i];
            for(int j=0; j<face.size(); j++) cout<<face[r][j]; cout<<"  ";
        }
        cout<<endl;
    }
    face = cube.back();
    cout<<endl;
    for(auto i: face){
        cout<<"    ";
        for(auto j: i) cout<<j;
        cout<<endl;
    }
    cout<<"__________________________________________\n";
    
}

void up1(){
    vector<int> faces = {2, 0, 4, 5};
    vector<string> vv;
    for(auto i: cube[5]){
        vv.push_back(i[1]);
    }
    for(auto &i: faces){
        vector<string> vc;
        for(auto &j: cube[i]){
            vc.push_back(j.back());
        }

        for(int j=0; j<cube[i].size(); j++){
            cube[i][j].back() = vv[j].back();
        }
        vv = vc;
    }

}


void down1(){
    vector<int> faces = {2, 5, 4, 0};
    vector<string> vv;
    for(auto i: cube[0]){
        vv.push_back(i[1]);
    }
    for(auto &i: faces){
        vector<string> vc;
        for(auto &j: cube[i]){
            vc.push_back(j.back());
        }

        for(int j=0; j<cube[i].size(); j++){
            cube[i][j].back() = vv[j].back();
        }
        vv = vc;
    }

}

void right1(){
    vector<int> faces = {2, 3, 4, 1};
    vector<string> vv=cube[faces.back()].back();
    for(auto &i: faces){
        vector<string> vc=cube[i].back();
        cube[i].back() = vv;
        vv = vc;
    }
}

void left1(){
    vector<int> faces = {2, 1, 4, 3};
    vector<string> vv=cube[faces.back()].back();
    for(auto &i: faces){
        vector<string> vc=cube[i].back();
        cube[i].back() = vv;
        vv = vc;
    }
}

void up2(){
    
}

int main(){
    vector<string> colors = {"W", "G", "R", "B", "O", "Y"};
    int c=0;
    for(auto &f: cube){
        for(auto &i: f){
            for(auto &j: i) j=colors[c];
        }
        c++;
    }

    view(cube);
    vector<pair<int,string>> moves  = {
        {1, "L"},
        {1, "L"},
        {1, "L"},
        // {1, "L"},
    };

    for(auto [a, b]: moves){
        if(a==1){
            if(b=="U") up1();
            if(b=="D") down1();
            if(b=="L") left1();
            if(b=="R") right1();
        }
    }

    view(cube);
}