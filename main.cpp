#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
using namespace std;


    const int FIL= 4;
    const int COLUM=4;
    void aleatorio (bool Mbuscaminas [][COLUM],int, int);//prototipo
    void cargarCampo (char,int ,int , char campo [][COLUM]);
    int contar0 (int, int, bool Mbuscaminas[][COLUM]);
    void iniciarJuego (int ,int ,int , int&,bool Mbuscaminas [][COLUM], char campo [][COLUM],char letraB [][16]);
    void apertura (char campo[][COLUM]);
    int dificultad (int);

int main()
{
    setlocale (LC_CTYPE,"spanish");
    int jugar =1,cantidad0;

while (jugar !=0)
{


    const int f=FIL;
    const int c=COLUM;
    int vidas=1;

    bool Mbuscaminas [f][c];
    char campo [f][c];                       //1                                                                   2                                                                        3                                                              4                                                                        5                                                         6                                                        7
    char letraB [7][16]={{'.','-','.',' ',' ','-',' ',' ',' ','-',' ',' ','^',' ','^',' '},{'|','o','|',' ','|',' ','|',' ','|',' ','|',' ','|','w','|',' '},{'|',' ','/',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' '},{'|','<',' ',' ','|','0','|',' ','|','0','|',' ','|',' ','|',' '},{'|',' ','.',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' '},{'|','o','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' '},{'.','-','.',' ',' ','-',' ',' ',' ','-',' ',' ','|',' ','|',' '}};


    aleatorio(Mbuscaminas,f,c);
    cargarCampo ('=',f,c,campo);


    cantidad0= contar0 (f,c,Mbuscaminas);
    apertura (campo);
    vidas=dificultad (vidas);
    iniciarJuego (f,c,cantidad0,vidas,Mbuscaminas,campo,letraB);

    do {cout << "desea volver a jugar?"<<endl<< "¿si? ingrese (1) " << endl<< "¿no? ingrese (0)"<< endl;
    cin >> jugar;} while (jugar !=1 && jugar!=0);
}
    return 0;
}

void aleatorio (bool Mbuscaminas [][COLUM],int f, int c)
{
    srand (time(0));
    for (int x=0;x<f;x++)
    {
        for (int y=0; y<c; y++)
        {
            Mbuscaminas [x][y]=0+ rand () % 2;
        }
    }
}

void cargarCampo (char forma,int f,int c, char campo [][COLUM])
{
    for (int x=0;x<f;x++)
    {
        for (int y=0; y<c; y++)
        {
            campo [x][y]=forma;
        }
    }
}



int contar0 (int f, int c, bool Mbuscaminas[][COLUM])
{
    int cont=0;

    for (int x=0; x<f;x++)
    {
        for (int y =0;y<c;y++)
        {
            if (Mbuscaminas[x][y]==0)
            {
                cont++;
            }
        }
    }
    return cont;
}

void fExplota (int ,int ,int ,int ,int& ,bool Mbuscaminas[][COLUM],char campo[][COLUM],char letraB[][16]);
void fNoexplota (int ,int ,int ,int ,int ,int& ,bool Mbuscaminas[][COLUM] ,char campo[][COLUM] );

void iniciarJuego (int f,int c,int cantidad0, int& vidas,bool Mbuscaminas [][COLUM], char campo [][COLUM],char letraB [][16])
{
int cantidadTESORO=0,Fusuario,Cusuario,explota;

do{
    do{
    cout<< "ingrese coordenada para fila: ";
    cin >> Fusuario;} while (Fusuario>FIL || Fusuario<1);
    do {cout<< "ingrese coordenada para columna: ";
    cin >> Cusuario;} while (Cusuario>COLUM || Cusuario<1);
    cout <<endl;
    Fusuario-=1;
    Cusuario-=1;
    explota= Mbuscaminas[Fusuario][Cusuario];

    if (explota)
    {
     fExplota (f,c,Fusuario,Cusuario,vidas,Mbuscaminas,campo,letraB);
    } else
    {
     fNoexplota (f,c,Fusuario,Cusuario, cantidad0,cantidadTESORO,Mbuscaminas,campo);
    }

  } while (vidas !=0 && cantidad0 !=cantidadTESORO);
}

void fExplota (int f,int c,int Fusuario,int Cusuario,int& vidas,bool Mbuscaminas[][COLUM],char campo[][COLUM],char letraB[][16])
{
     for (int x=0; x<7;x++)
      {
        for (int y=0; y<16;y++)
        {
            cout<<letraB [x][y]<<" ";
        } cout<<endl;
      }
      cout<< endl<<endl;
    campo[Fusuario][Cusuario]='*';


    for (int x=0; x<f;x++)
    {
        for (int y=0; y<c;y++)
        {
            cout<<campo[x][y]<<" ";
        }cout <<endl;
    }
    cout<< endl;
    vidas--;
    if (vidas==0)
    {
    cout << "PERDISTE ¿DE verda?"<<endl;
    }else
    {
       if (vidas==1)
       {
        cout << "te queda: " << vidas<< " vida"<<endl;
       } else
       {
        cout << "te quedan: " << vidas<< " vidas"<<endl;
       }
    }
    cout<< endl;
}


void fNoexplota (int f,int c,int Fusuario,int Cusuario,int cantidad0,int& cantidadTESORO,bool Mbuscaminas[][COLUM] ,char campo[][COLUM])
{
    campo [Fusuario][Cusuario]='$';
    cout<< endl;
     for (int x=0; x<f;x++)
      {
        for (int y=0; y<c;y++)
        {
            cout<<campo [x][y]<<" ";
        } cout<<endl;
      }
      cout<< endl;

      cantidadTESORO++;
      if (cantidad0==cantidadTESORO)
      {
       for (int x=0; x<f;x++)
      {
        for (int y=0; y<c;y++)
        {
            cout<<Mbuscaminas [x][y]<<" ";
        }cout <<endl;
      }
      cout << "GANASTE CHIMERGUENCHA"<<endl;
      }
}

void apertura (char campo[][COLUM])
{
    cout << "*******BIENVENIDO A BUSCANDO EL TESORO*******"<< endl<<endl;
    cout << "FORMA DE JUGAR: Debe ingresar datos de fila y columna" << endl<<endl;
    cout << "                  FILA: de arriba para abajo"<<endl<< "ejemplo:"<<endl;
    for (int x=0; x<FIL;x++)
      {cout <<x+1;
        for (int y=0; y<COLUM;y++)
        {
            cout<<campo [x][y]<<" ";
        } cout<<endl;
      }


    cout << "                 COLUMNA: de izquierda a derecha"<<endl<< "ejemplo:"<<endl;
    cout << "1 2 3 4"<<endl;
    for (int x=0; x<FIL;x++)
      {
        for (int y=0; y<COLUM;y++)
        {
            cout<<campo [x][y]<<" ";
        } cout<<endl;
      }
    cout<< endl<<"MUCHA SUERTE... A JUGAR!!!" <<endl<<endl;

}
int dificultad (int vidas)
{int opcion;
    cout << "SELECCIONE DIFICULTAD: ";
    cout << endl<< "1- Facil (12 vidas)"<< endl<< "2- Medio (8 vidas)"<< endl<< "3- Dificil (4 vidas)"<< endl;
    cin>> opcion;
    cout << endl;

    switch (opcion)
    {
     case 1:
     opcion=12;
     break;
     case 2:
     opcion=8;
     break;
     default:
     opcion=4;
     break;
    }
    return opcion;
}
