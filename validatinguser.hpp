#include<fstream>
#include<iostream>
using namespace std;
int UserSelectedCounter[10] = {0,0,0,0,0,0,0,0,0,0};
int PaswordSelectedCounter[10] = {0,0,0,0,0,0,0,0,0,0};
int counter = -1;
bool validateUser(string user){
     ifstream file; 
    string text;
    string aux;
    counter = -1;
        file.open("./base_files/usersDataBase.txt", ios::in);
        while(!file.eof())  getline(file,text);
        file.close();
        bool cerrojo = false;
        bool cerrojo4 = false;
        if(cerrojo4) return false;
    for(int i = 1; i < text.length(); i++){
        cerrojo4 = true;
        if(text[i-1] == '"'){
            cerrojo = true; 
            aux = "";
        } 
        if(text[i+1] == '"'){
            aux += text[i];
            counter ++;
            cerrojo = false;
        } 
        if(cerrojo) aux += text[i];
        if(aux == user){
            UserSelectedCounter[counter] = 1;
            return true;
        }else{
            counter ++;
        }
    } return false;
}

bool validatePasword(string pasword){
     ifstream file2; 
    string text2;
    string aux2;
    counter = -1;
        file2.open("./base_files/pswdDataBase.txt", ios::in);
       while(!file2.eof()){
getline(file2, text2);
       }
        
        file2.close();
        bool cerrojo2 = false;
        bool cerrojo3 = false;
    if(cerrojo3) return false;
        for(int i = 1; i < text2.length(); i++){
            cerrojo3 = true;
        if(text2[i-1] == '"'){
            cerrojo2 = true; 
            aux2 = "";
        } 
        if(text2[i+1] == '"'){
            aux2 += text2[i];
            counter ++;
            cerrojo2 = false; 
        } 
        if(cerrojo2) aux2 += text2[i];
        if(aux2 == pasword){
            PaswordSelectedCounter[counter] = 1;
            return true;
        }
    } 
}
bool validate(string user, string pasword){
    
   if(validatePasword(pasword) == true && validateUser(user) == true && UserSelectedCounter[counter] == 1 && PaswordSelectedCounter[counter == 1]){
    return true;
   }else{
    return false;
   }
}
/*int main(){
    validate("EmiCastro01", "Boquita2001");
    return 0;
}
*/