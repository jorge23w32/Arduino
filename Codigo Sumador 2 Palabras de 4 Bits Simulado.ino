//Declaración de las entradas
int A=0; //Bit mas significativo
int B=0; //Bit menos significativo
int C=0;
int D=0;


//Declaración de las salidas
int C1=0;
int S1=0;
int S0=0;

void setup()
{
  //Configuración de entradas 
  pinMode(9, INPUT); //A
  pinMode(8, INPUT); //B
  pinMode(7, INPUT); //C
  pinMode(6, INPUT); //D
 
  //Configuración de terminal de salida
  pinMode(0, OUTPUT);//C
  pinMode(1, OUTPUT);//S1
  pinMode(2, OUTPUT);//S0
 }

void loop()
{
  //Lectura de entradas
  A=digitalRead(9);
  B=digitalRead(8);
  C=digitalRead(7);
  D=digitalRead(6);
 
  //Funcion a implementar
  
  C1= (B && C && D) || (A && B && D) || (A && C);
  S1=(!A && !B && C)||(!A && C &&!D)||(!A && B && !C && D)||(A && B && C && D)||(A && !C && !D)||(A && !B &&!C);
  S0 = (!B && D) || (B && !C && !D) || (B && C && !D); 
       
  //DEFINICIÓN DE LA SALIDA
  
  bitWrite(PORTD,0,C1);
  bitWrite(PORTD,1,S1);
  bitWrite(PORTD,2,S0);
}