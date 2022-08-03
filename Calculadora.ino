// C++ code
//
#include<LiquidCrystal.h>
#include<Keypad.h>

#define PIN_RS 2
#define PIN_E  3

LiquidCrystal lcd(PIN_RS, PIN_E, 4, 5, 6, 7);

char tecladoMatriz[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilasTeclado[4] = {12, 11, 10, 9};
byte pinesColumnasTeclado[4] = {A0, A1, A2, A3};
//byte pinesColumnasTeclado[4] = {13, 8, 1, 0};

Keypad teclado = Keypad(makeKeymap(tecladoMatriz), pinesFilasTeclado, pinesColumnasTeclado, byte(4), byte(4));

char teclaPresionada;
long resultado = 0;
long operando1 = 0;
long operando2 = 0;
int flagOp1 = 1;
int flagOp2 = 1;

/*	    
    #: " = "
    *: "Cambiar signo"
    M1: "Guarda un operando actual o el resultado"
    M2: "Obtengo el valor guardado"
*/

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

/*
Realiza el calculo de los operandos
	A = SUMA
	B = RESTA
    C: Multiplicación
	D: División
*/
void Calculador()
{
  teclaPresionada = teclado.getKey();
  
  switch(teclaPresionada)
  {
    case '0'...'9':
    lcd.clear();
    operando1 = primerOperando();
    imprimirOperando(operando1);
   	break;
    
    case 'A':
    lcd.setCursor(8,0);
    lcd.print("+");
    operando2 = segundoOperando();
    resultado = operando1 + operando2;
  	imprimirCalculo(resultado);
    operando1 = 0;
    operando2 = 0;
    break;
    
    case 'B':
    lcd.setCursor(8,0);
    lcd.print("-");
    operando2 = segundoOperando();
    resultado = operando1 - operando2;
  	imprimirCalculo(resultado);
    operando1 = 0;
    operando2 = 0;
    break;
    
    case 'C':
    lcd.setCursor(8,0);
    lcd.print("*");
    operando2 = segundoOperando();
    resultado = operando1 * operando2;
  	imprimirCalculo(resultado);
    operando1 = 0;
    operando2 = 0;
    break;
    
    case 'D':
    lcd.setCursor(8,0);
    lcd.print("/");
    operando2 = segundoOperando();
    resultado = (operando2 > 0 ? operando1 / operando2 : 0);
  	imprimirCalculo(resultado);
    operando1 = 0;
    operando2 = 0;
    break;
  }

}

void loop()
{
  Calculador();
}

/*
Muestra por pantalla el resultado de la operacion de manera prolija
*/
void imprimirCalculo(int resultado)
{
  if(resultado<= 9){
    if(resultado <0)
    {
     lcd.setCursor(13,1);
   	 lcd.print("=");
 	 lcd.setCursor(14,1);
   	 lcd.print(resultado);
    }
    else{
    lcd.setCursor(14,1);
    lcd.print("=");
  	lcd.setCursor(15,1);
    lcd.print(resultado);
    }
  }
  else if(resultado<=99){
    if(resultado <0)
    {
     lcd.setCursor(12,1);
   	 lcd.print("=");
 	 lcd.setCursor(13,1);
   	 lcd.print(resultado);
    }else{
    lcd.setCursor(13,1);
    lcd.print("=");
    lcd.setCursor(14,1);
    lcd.print(resultado);
    }
  }
  else if(resultado <=999)
  {
    if(resultado <0)
    {
     lcd.setCursor(11,1);
   	 lcd.print("=");
 	 lcd.setCursor(12,1);
   	 lcd.print(resultado);
    }else{
    lcd.setCursor(12,1);
    lcd.print("=");
    lcd.setCursor(13,1);
    lcd.print(resultado);
    }
  }
  else if(resultado <= 9999)
  {
    if(resultado <0)
    {
     lcd.setCursor(10,1);
   	 lcd.print("=");
 	 lcd.setCursor(11,1);
   	 lcd.print(resultado);
    }else{
   	lcd.setCursor(11,1);
    lcd.print("=");
  	lcd.setCursor(12,1);
    lcd.print(resultado);
    }
  }
  else if(resultado <= 99999)
  {
    if(resultado <0)
    {
     lcd.setCursor(9,1);
   	 lcd.print("=");
 	 lcd.setCursor(10,1);
   	 lcd.print(resultado);
    }else{
    lcd.setCursor(10,1);
    lcd.print("=");
  	lcd.setCursor(11,1);
    lcd.print(resultado);
    }
  }
  else if(resultado <= 999999)
  {
    if(resultado <0)
    {
     lcd.setCursor(8,1);
   	 lcd.print("=");
 	 lcd.setCursor(9,1);
   	 lcd.print(resultado);
    }else{
    lcd.setCursor(9,1);
    lcd.print("=");
  	lcd.setCursor(10,1);
    lcd.print(resultado);
    }
  }
  else if(resultado <= 9999999)
  {
    if(resultado <0)
    {
     lcd.setCursor(7,1);
   	 lcd.print("=");
 	 lcd.setCursor(8,1);
   	 lcd.print(resultado);
    }else{
    lcd.setCursor(8,1);
    lcd.print("=");
  	lcd.setCursor(9,1);
    lcd.print(resultado);
    }
  }

}

/*
Muestra por pantalla de manera prolija el primer operando
*/
void imprimirOperando(int operando)
{
  if(operando<= 9){
  lcd.setCursor(7,0);
    lcd.print(operando);
  }
  else if(operando<=99){
    lcd.setCursor(6,0);
    lcd.print(operando);
  }
  else if(operando <=999)
  {
    lcd.setCursor(5,0);
    lcd.print(operando);
  }
  else if(operando <= 9999)
  {
    lcd.setCursor(4,0);
    lcd.print(operando);
  }
  else if(operando <= 99999)
  {
    lcd.setCursor(3,0);
    lcd.print(operando);
  }
  else if(operando <= 999999)
  {
    lcd.setCursor(2,0);
    lcd.print(operando);
  }
  else if(operando <= 9999999)
  {
    lcd.setCursor(1,0);
    lcd.print(operando);
  }
}

/*
Obtiene el primer operando
*/
long primerOperando()
{
  operando1 = operando1 * 10 + (teclaPresionada - '0');
  if(teclaPresionada == '*')
  {
    operando1 = operando1 * -1;
  }
  return operando1;
  
  /*
  do{
    operando1 = operando1 * 10 + (teclaPresionada - '0');
  if(teclaPresionada == '*')
  {
    operando1 = operando1 * -1;
  }
  }while(teclaPresionada!= 'A'|| teclaPresionada!= 'B' || teclaPresionada!= 'C' || teclaPresionada!= 'D');
  return operando1;*/
}

/*
Obtiene el segundo operando 
*/
long segundoOperando()
{
  while(flagOp2)
  {
    teclaPresionada = teclado.getKey();
    if(teclaPresionada >= '0' && teclaPresionada <= '9')
    {
      operando2 = operando2 * 10 + (teclaPresionada - '0');
      lcd.setCursor(9,0);
      lcd.print(operando2);
    }
    
    else if(teclaPresionada == '*')
    {
      operando2 = operando2 * -1;
    }
    
    else if(teclaPresionada == '#')
    {
      flagOp2 = 0;
    }
  }
  flagOp2 = 1;
  return operando2;
}
