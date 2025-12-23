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
    vector<int> faces = {2, 0, 4, 5};
    Face face1 = cube[faces.back()];
    for(int i: faces){
        Face face2 = cube[i];
        cube[i] = face1;
        face1 = face2;
    }
    
    //right face
    Face rightFace = cube[3];
    cube[3][0][0] = rightFace[1][0];
    cube[3][0][1] = rightFace[0][0];
    cube[3][1][0] = rightFace[1][1];
    cube[3][1][1] = rightFace[0][1];

    
    //left face
    Face left = cube[1];
    cube[1][0][0] = left[0][1];
    cube[1][0][1] = left[1][1];
    cube[1][1][0] = left[0][0];
    cube[1][1][1] = left[1][0];
}

void down2(){
    vector<int> faces = {2, 5, 4, 0};
    Face face1 = cube[faces.back()];
    for(int i: faces){
        Face face2 = cube[i];
        cube[i] = face1;
        face1 = face2;
    }
    
    //right face
    Face rightFace = cube[1];
    cube[1][0][0] = rightFace[1][0];
    cube[1][0][1] = rightFace[0][0];
    cube[1][1][0] = rightFace[1][1];
    cube[1][1][1] = rightFace[0][1];

    
    //left face
    Face left = cube[3];
    cube[3][0][0] = left[0][1];
    cube[3][0][1] = left[1][1];
    cube[3][1][0] = left[0][0];
    cube[3][1][1] = left[1][0];
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
        } else{
            if(b=="U") up2();
            if(b=="D") down2();
            // if(b=="L") left2();
            // if(b=="R") right2();
        }
    }
    view(cube);
    up2();
    view(cube);
    down2();
    view(cube);
}