#include<iostream>
#include "rlutil.h"
#include "./validatinguser.hpp"
#define cursor "->"
using namespace std;

bool validateUser(string username, string pswd){
    if(validate(username, pswd) == true){
        return true;
    }else{
        return false;
    }
}
void showMessage(const char* message, rlutil::COLOR color){
    rlutil::setBackgroundColor(color);
    rlutil::locate(1,1);
    cout << message;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void mostrarItem(const char* text, int posx, int posy, bool isSelected){
    if(isSelected){
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTGREEN);
        rlutil::locate(posx,posy);
        cout << text;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(posx,posy);
        cout << text;
    }
}

void Ingresar(){
    bool cantLogIn = true;
    bool failUorPswd = false;
    string user, psw;
    while(cantLogIn){
        string psw, user;
        rlutil::cls();
        if(failUorPswd) showMessage("Usuario o Contrasena Incorrectos", rlutil::COLOR::RED);
        mostrarItem("Usuario: ", 40, 1, false);
        mostrarItem("Contrasena: ", 40, 2, false);
        rlutil::showcursor();
        rlutil::locate(50,1);
        cin >> user;
        rlutil::locate(54,2);
        cin >> psw;
        if(validateUser(user,psw) == false){
            failUorPswd = true;
        }else{
            rlutil::cls();
            showMessage("Ingresando", rlutil::COLOR::GREEN);
            cantLogIn = false;
        }
    }
    
}

void Ayuda(){
    rlutil::locate(1,1);
    cout << "Something";
}
void accion(int opc){       //5->Salir, 4->Ayuda, 3->Ingresar
    switch(opc){
        case 5:
            rlutil::cls();
            break;
        case 4:
            rlutil::cls();
            Ayuda();
        break;
        case 3:
            rlutil::cls();
            Ingresar();
        break;
    }
}
int menuPrincipal(){
    int y = 3;
    while(true){
            mostrarItem("BIENVENIDOS", 40, 1, y == 1);
            mostrarItem(" ",40,2,false);
            mostrarItem("Ingresar", 40, 3, y == 3);
            mostrarItem("Ayuda", 40, 4, y == 4);
            mostrarItem("Salir", 40, 5, y == 5);
        rlutil::locate(37,y);
        cout << cursor;
        int key = rlutil::getkey(); 
        switch(key){
            case rlutil::KEY_DOWN :
                rlutil::locate(37,y);
                cout << "  ";
                y++;
                if(y > 5) y = 5;
                break;
            case rlutil::KEY_UP :
                rlutil::locate(37,y);
                cout << "  ";
                y--;
                if(y < 3) y = 3;
                break;
            case rlutil::KEY_ENTER :
                return y;

        }
    }
    

}

int main(){
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::cls();
    accion(menuPrincipal());
    rlutil::getkey();
    return EXIT_SUCCESS;
}