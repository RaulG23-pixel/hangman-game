#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>



using namespace std;

int checkUnderscore(string str){
        return !(str.find("_",0) != -1);
}
    

int main(){
    //Inicialización del srand para generar posteriormente numeros aleatorios
    srand((unsigned) time(NULL));
    string opciones[6] = {"programar","basketball","beisbol","videojuego","espacio", "windows"};
   
    /*Se genera un numero aleatorio entre el 0 y el 6 y
     a partir de dicho indice se selecciona una opcion del array;*/

    string opcion = opciones[rand() % 6];

    char temp;
    int vidas = 8;
    string display;
   
    cout << "Bienvenido al juego del ahorcado, el juego consiste en adivinar la palabra colocando las letras correctas" << endl;
    cout << "De lo contrario pierdes una vida, al llegar a 0 vidas pierdes el juego"<<endl;
    cout << "\nJ U G U E M O S......"<<endl;

    for(int i = 0; i < opcion.length(); i++){
        display += "_ ";
    }


    cout << "\nAdivina la palabra: " << endl;

    while(vidas > 0){
        cout << "\nTotal de vidas: " << vidas << endl;
        cout << "introduce una letra: "; cin >> temp;


        int indice = opcion.find(temp);

        if(indice == -1){
            vidas -= 1;
        }else{
                //Obtiene la cantidad de letras que se repiten
                int totalLetras = count(opcion.begin(),opcion.end(),opcion[indice]);
                
                //Si la cantidad de letras repetidas es mayor que 1 se ejecuta lo de debajo
                if(totalLetras > 1){
                    //cursor hace referencia a la posicion de una de la primera letra repetida en el string
                    int cursor = indice;

                    while(totalLetras > 0){
                        //se obtiene la primera letra repetida mas cercana al indice del cursor
                        int tempIndex = opcion.find(opcion[indice],cursor);
                        display[tempIndex * 2 ] = opcion[tempIndex];

                        if(tempIndex > 0){
                            display[tempIndex * 2 ] = opcion[tempIndex];
                        }else{
                            display[tempIndex] = opcion[tempIndex];
                        }

                        cursor = tempIndex + 1;
                        totalLetras--;
                    }
                }else{
                    if(indice > 0){
                        display[indice * 2 ] = opcion[indice];
                    }else{
                        display[indice] = opcion[indice];
                    }
                }
        }
        
        cout << display << endl;

        if(checkUnderscore(display)){
            break;
        };
    }

    if(vidas > 0){
        cout << "\nHas ganado el juego :D" <<endl;
    }else{
        cout << "\nHas perdido el juego" << endl;
    }
    
    cout << "Programa terminado....." << endl;

    return 0;
}
