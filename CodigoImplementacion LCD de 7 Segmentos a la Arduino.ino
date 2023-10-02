// C++ code
//
//Se declaran las variables de entrada
int A=0;
int B=0;
int C=0;
int D=0;
//Se declaran las variables de salida
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int f=0;
int g=0;
void setup()
{
  //Entradas
  pinMode(13, INPUT);//A
  pinMode(12, INPUT);//B
  pinMode(11, INPUT);//C
  pinMode(10, INPUT);//D
  
  //Salidas
  pinMode(1, OUTPUT);//a
  pinMode(2, OUTPUT);//b
  pinMode(3, OUTPUT);//c
  pinMode(4, OUTPUT);//d
  pinMode(5, OUTPUT);//e
  pinMode(6, OUTPUT);//f
  pinMode(7, OUTPUT);//g
  
}

void loop()
{
  //Leen las entradas
  A = digitalRead(13);
  B = digitalRead(12);
  C = digitalRead(11);
  D = digitalRead(10);
  
  //Funciones simplificadas
  a = (!B && !D) + (B && D) + C + A; 
  b = (!C && !D) + (!A && !B) + (C && D) + A;
  c = !C + (C && D) + (!A && B);
  d = (!B && !D) + (B && !C && D) + A + (C && !D) + (!A && !B && C);
  e = (!B && !C && !D) + (!A && C && !D);
  f = (!C && !D) + A + (B && !C && D) + (B && C && !D);
  g = (B && !C) + (C && !D) + (!A && !B && C) + A;
  
  //Definicion de la salida
  bitWrite(PORTD, 1, a);
  bitWrite(PORTD, 2, b);
  bitWrite(PORTD, 3, c);
  bitWrite(PORTD, 4, d);
  bitWrite(PORTD, 5, e);
  bitWrite(PORTD, 6, f);
  bitWrite(PORTD, 7, g);
}