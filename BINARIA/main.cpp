#include <iostream>
using namespace std;
#include <fstream>

void ingresar(int a[],int n);
void Busqueda (int a[],int n,int dato);
void Burbuja (int a[],int n);
void imprimir(int a[],int n);
int main()
{
 int a[50];
 int dato,n;
 cout<<"Ingrese el tamaño del arreglo: "<<endl;
 cin>>n;
 ingresar(a,n);
 cout<<"Ingrese el elemento a buscar: "<<endl;
 cin>>dato;
 cout<<endl;
 imprimir(a,n);
 Burbuja(a,n);
 imprimir(a,n);
 Busqueda(a,n,dato);
 return 0;
}

void Burbuja (int a[],int n)
{
   int aux;
    for (int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(a[j]<a[i])
            {
                aux=a[i];

                a[i]=a[j];

                a[j]=aux;

            }

        }
    }
}

void ingresar(int a[],int n)
{

	for(int i=0;i<n;i++)
	{
		cout<<"Ingresar elementos del arreglo "<<i+1<<": ";
		cin>>a[i];
	}

}

void imprimir(int a[],int n)
{
    ofstream Binario;
    Binario.open("Binario.txt",ios::app);
    Binario<<endl;
    for (int i=0; i<n;i++)
    {
      cout<<"["<<a[i]<<"]";
      Binario<<"["<<a[i]<<"]";
    }
    cout<<endl;
    Binario<<endl;
    Binario.close();
}

void Busqueda(int a[],int n,int dato)
{
  ofstream Binario;
  int i,j,k;
  Binario.open("Binario.txt",ios::app);
  i=0;
  j=n-1;

  do
  {
      k=(i+j)/2;
      if(a[k]<=dato)
        {
          i=k+1;
        }
      if (a[k]>=dato)
        {
          j=k-1;
        }
  }while (i<=j);

  if(a[k]==dato)
  {
      cout <<"\nElemento encontrado en la posicion:"<<k<<endl;
      Binario<<"\nElemento encontrado en la posicion:"<<k<<endl;
  }
  else
  {
      cout <<"\nElemento no encontrado"<<endl;
      Binario <<"\nElemento no encontrado :"<<endl;
  }
  Binario.close();
}
