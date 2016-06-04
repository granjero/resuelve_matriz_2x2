#include <stdio.h>

/* ES IMPORTANTE QUE EL ARCHIVO 
 * DE LA MATRIZ NO TENGA CARACTERES 
 * LUEGO DEL ULTIMO VALOR 
 * PARA QUE n NO AUMENTE DE MAS
 */

/* MATRIZ
 * 
 * |X² X| |A|   |XY|
 * |X  1| |B| = | Y|
 * 
 */
int main() 
{
    float valoresX[1024];
    float valoresY[1024];
    float X = 0;
    float Xcuadrado = 0;
    float Y = 0;
    float XY = 0;
    float A = 0;
    float B = 0;
    int i;
    int n = 0; //será la cantidad de filas del archivo
  
    FILE *valoresMatriz;    
    valoresMatriz = fopen("matriz.txt", "r+");
    while(!feof(valoresMatriz))
    {
        fscanf(valoresMatriz, "%f %f", &valoresX[i], &valoresY[i]);
        //printf("X = %f Y = %f\n",valoresX[i],valoresY[i]);
        i++;
        n++;
        //printf("%d\n",n);
        
    }
        
    //calcula Xcuadrado promediado
    for (i = 0; i < n; i++)
    {
        Xcuadrado = Xcuadrado + (valoresX[i] * valoresX[i]);
    }
    Xcuadrado = Xcuadrado / n;
    
    //calcula X promediado 
    for (i = 0; i < n; i++)
    {
        X = X + valoresX[i];
    }
    X = X / n;
    
    //calcula Y promediado
    for (i = 0; i < n; i++)
    {
        Y = Y + valoresY[i];
    }
    Y = Y / n;

    //calcula XY promedio
    for (i = 0; i < n; i++)
    {
        XY = XY + (valoresX[i] * valoresY[i]);
    }
    XY = XY / n;
     
    printf("\n\nMatriz a Resolver\n\n|X² X| |A|   |XY|\n|X  1| |B| = | Y|\n\n");
      
    A = (XY - (Y * X)) / (Xcuadrado - (X * X));
    B =  ((Xcuadrado * Y) - (XY * X)) / (Xcuadrado - (X * X));
    
    printf("Datos calculados del archivo leido:\n\n");
    
    printf("X/n = %.2f\n",X);
    printf("Y/n = %.2f\n",Y);
    printf("XY/n = %.2f\n",XY);
    printf("X²/n = %.2f\n",Xcuadrado);
    
    printf("\nResultado:\n\n");
    
    printf("A = %.2f\n",A);
    printf("B = %.2f\n",B);

    return 0;
}