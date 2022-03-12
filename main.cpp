#include <iostream>

using namespace std;

void menu();
void imprimir(int bytes[]);
void orOperation(int resultado[]);
void andOperation(int resultado[]);
void cargarArreglo(int bytes[]);
void xor20(int resultado[]);
int implicacion();
int bicondicional();

int main()
{
    int opcion =0;
    int resultado[8];
    int resultadoBit;
    do
    {
        menu();
        cout << "Ingresa una opcion: ";
        cin >> opcion;
        cout << endl;
        switch(opcion)
        {
        case 1:
            orOperation(resultado);
            imprimir(resultado);
            break;
        case 2:
            andOperation(resultado);
            imprimir(resultado);
            break;
        case 3:
            xor20(resultado);
            imprimir(resultado);
            break;
        case 4:
            resultadoBit = implicacion();
            cout << "Resultado de la operacion: " << resultadoBit;
            break;
        case 5:
            resultadoBit = bicondicional();
            cout << "Resultado de la operacion: " << resultadoBit;
            break;
        case 6:
            cout << "Nos vemos :)" << endl;
            break;
        }
    }
    while(opcion != 6);
    return 0;
}

int implicacion() {
    int b1,b2;
    b1=0;
    b2 =0;

    do{
        cout << "Ingresa el primer bit: ";
        cin >> b1;
    }while(b1 != 0 && b1 != 1);

    do{
        cout << "Ingresa el segundo bit: ";
        cin >> b2;
    }while(b2 != 0 && b2 != 1);

    if( (b1 ==0 && b2 ==0) || (b1 == 1 && b2 == 1) || (b1==0 && b2 ==1)) {
        return 1;
    }
    else {
        return 0;
    }
}

int bicondicional() {
    int b1,b2;
    b1=0;
    b2=0;

    do{
        cout << "Ingresa el primer bit: ";
        cin >> b1;
    }while(b1 != 0 && b1 != 1);

    do{
        cout << "Ingresa el segundo bit: ";
        cin >> b2;
    }while(b2 != 0 && b2 != 1);

    if(b1==1 && b2 ==1) {
        return 1;
    }
    else return 0;
}

void menu()
{
    cout << endl;
    cout <<"---- Calculadora Logica ----" << endl;
    cout <<"---- 1) Or              ----"<< endl;
    cout <<"---- 2) And             ----"<< endl;
    cout <<"---- 3) XoR 20          ----" <<endl;
    cout <<"---- 4) Implicacion     ----" <<endl;
    cout <<"---- 5) Bicondicional   ----" << endl;
    cout <<"---- 6) Salir           ----" << endl;
    cout << endl;
}

void orOperation(int resultado[])
{
    int a[8];
    int b[8];

    cargarArreglo(a);
    cargarArreglo(b);


    imprimir(a);
    imprimir(b);
    cout << "-------------------" << endl;

    for(int i=0; i<8; i++)
    {
        if( (a[i]== 1 && b[i] == 1) || (a[i]==1 && b[i]==0) || (a[i]==0 && b[i]==1))
        {
            resultado[i] = 1;
        }
        else resultado[i] = 0;
    }
}

void andOperation(int resultado[])
{
    int a[8];
    int b[8];

    cargarArreglo(a);
    cargarArreglo(b);

    imprimir(a);
    imprimir(b);
    cout << "-------------------" << endl;

    for(int i=0; i<8; i++)
    {
        if(a[i]== 1 && b[i] == 1)
        {
            resultado[i] = 1;
        }
        else resultado[i] = 0;
    }
}

void xor20(int resultado[])
{
    int a[8];
    int b[8] = {0,0,1,0,0,0,0,0};
    cargarArreglo(a);
    imprimir(a);
    imprimir(b);
    cout << "-------------------" << endl;

    for(int i=0; i<8; i++)
    {
        if( (a[i] == 0 && b[i] ==0) || (a[i] == 1 && b[i] ==1))
        {
            resultado[i] = 0;
        }
        else
        {
            // b1 == 1 && b2 == 0
            // b1 == 0 && b2 == 1
            resultado[i] = 1;
        }
    }
}


void imprimir(int bytes[])
{
    cout << endl;
    for(int i=0; i<8; i++)
    {
        cout << bytes[i] << ' ';
    }
    cout <<"b) "<< endl;
}

void cargarArreglo(int bytes[])
{
    cout << endl;
    int n;
    for(int i=0; i<8; i++)
    {
        do
        {
            cout << "Ingresa un bit" << endl;
            cin >> n;
        }
        while(n != 1 && n !=0);

        bytes[i] = n;
    }
    cout << "Carga completada";
    cout << endl;
}
