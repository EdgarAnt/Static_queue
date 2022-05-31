#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;

void validar();

void gotoxy(int x,int y){
HANDLE hcon;
hcon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X = x;
dwPos.Y= y;
SetConsoleCursorPosition(hcon,dwPos);
}

class Nodo{


  public:
    int value;
    Nodo* next;


};
bool cola_vacia(Nodo *frente){
return (frente == NULL)? true : false;
};
void push(Nodo *&frente,Nodo *&fin,int n){


Nodo *nuevo_nodo = new Nodo();
nuevo_nodo->value = n;
nuevo_nodo->next = NULL;
if(cola_vacia(frente)){
frente = nuevo_nodo;
}else{
fin->next = nuevo_nodo;
}
fin = nuevo_nodo;


};


void pop(Nodo *&frente,Nodo *&fin){
Nodo *aux = frente;
if(frente == fin){
frente = NULL;
fin = NULL;
}else{
frente = frente->next;
}
delete aux;


};


void display(Nodo *&frente, int cont){
  Nodo *temp = frente;
  for(int i=0; i<cont; i++){
    if(i==0){
      cout <<" ";
    }else{
      cout <<"  ";
    }


  }
  cout <<endl;
printf("\n\n\t        %c%c%c%c%c \n", 201,205,205,205,187);
  while(temp!=NULL){
    cout<<"                " <<char(186)<<" "<<temp->value <<" "<<char(186)<<endl;
    printf("\t\t%c%c%c%c%c", 204,205,205,205,185);
    temp = temp->next;
      cout <<endl;

  }


};


int menu(){
    int opc;
    cout <<endl;
    gotoxy(52,5);
    cout <<"Menu"<<endl;
    gotoxy(52,8);
    cout <<"[1]Push"<<endl;
    gotoxy(52,10);
    cout <<"[2]Pop"<<endl;
    gotoxy(52,12);
    cout <<"[0]Salir"<<endl;
    gotoxy(52,14);
    cout<<"Opcion: ";
    cin>>opc;
    return opc;

};



bool validar(char []);
//char numero='\x0';
int x=0;
void validar() {
    system("cls");
  char buffer[256];
   cout<<"ingrese numero"<<endl;
   cin>>buffer;
   if(validar(buffer)){
      x=atoi(buffer);
       cout<< x+2;
   }
  // cout<<int(numero);
 system("pause>>cls");
}
bool validar(char numero[]){
bool ban=false;
if((int(numero[0])>=48) && (int(numero[0])<=57 )){
       ban=true;
}
return ban;
}

int main(){
  Nodo *frente = NULL;
  Nodo *fin = NULL;
  int value, cont=0, opc=1, cont2=0;
  do {


    switch (menu()) {
      case 1:
         cont2++;
         gotoxy(52,16);
         cout<<"Insertar en cola: ";
         cin>>cont;
         push(frente, fin, cont);
         system("cls");
         display(frente, cont2);
      break;
      case 2:
          cont2--;
          pop(frente, fin);
          system("cls");
          display(frente, cont2);
      break;
      default: cout << "Opcion no disponible" <<endl;


    }


  } while(opc!=0);
};
