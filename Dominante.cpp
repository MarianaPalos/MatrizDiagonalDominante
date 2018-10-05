#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


void Imprimir (int A[3][3]) //Imprime matrices cuadradas
   {
     int i,j;

      for(i=0;i<3;i++){
          cout << "|";
          for (j=0;j<3;j++){
              cout << " " << A[i][j] << " ";
          }
          cout << "|" << endl;
      }

   }

void Revisar (int A[3][3]){ //Funcion que revisa si una matriz de 3x3 es dominante
int suma, i, j, contador=0;

for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
    suma=0;
    if (i!=j)
    {
      suma = suma + A[i][j];
    }
  }

  if(abs(suma)<A[i][i])
  {
    cout<<"\nRenglon " << i+1 << ": DOMINANTE"<< endl;
    contador ++;
  }
  else
  {
   cout <<"\nRenglon " << i+1 << ": NO DOMINANTE" << endl;
  }

}
if (contador==3)
cout <<"\nLa Matriz es DOMINANTE" << endl;
else
cout <<"\nLa Matriz NO es DOMINANTE" << endl;
}

void Dominante (int A[3][3]){ //Convierte la matriz en diagonal dominante
int i,j,k,aux,contador;

for (j = 0; j<3; j++)
{
    for (i = 0; i<3; i++)
    {
        if ((i!= j)&&(fabs(A[j][j])<fabs(A[i][j])))
        {
            if (j<=0)
            {
                for (k=0; k<3; k++)
                {
                    aux = A[i][k];
                    A[i][k] = A[j][k];
                    A[j][k] = aux;
                    contador++;
                }
              }
            else if (j>0)
            {
                if ((fabs(A[j][j])-fabs(A[j][i]))>(fabs(A[i][i])-fabs(A[i][j])))
                {
                    for (k=0; k<3; k++)
                    {
                        aux = A[i][k];
                        A[i][k] = A[j][k];
                        A[j][k] = aux;
                        contador++;
            }
          }
        }
      }
    }
  }
}


int main (void)
{
  int A[3][3];

  A[0][0]= 1;
  A[0][1]= 2;
  A[0][2]= 5;
  A[1][0]= 5;
  A[1][1]= 2;
  A[1][2]= 1;
  A[2][0]= 3;
  A[2][1]= 5;
  A[2][2]= 0;

  cout<< "\nLa Matriz Original: "<<endl;
  Imprimir (A);
  Revisar (A);
  cout << "\nLa Matriz despues del cambio: "<<endl;
  Dominante(A);
  Imprimir (A);
  Revisar (A);


  return 0;
}



//Ordena la matriz de menor a mayor, pero recorre todos los renglones y columnas
/*for(i=0;i<3;i++) {
        for(j=0;j<3;j++)
        {
            min=A[i][j];
            for(k=i;k<3;k++)
            {
                for(w=j;w<3;w++)
                if(A[k][w]<min)
                {
                    min=A[k][w];
                    z=k;
                    q=w;
                }
                w=0;

            }
            tmp=A[i][j];
            A[i][j]=min;
            A[z][q]=tmp;
        }
      }*/
