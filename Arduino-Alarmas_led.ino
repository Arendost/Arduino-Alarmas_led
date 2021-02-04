#include <LiquidCrystal.h>                                  //Libreria de la pantalla
LiquidCrystal lcd(7, 6, 5,4,3,2);                           //Pines usados en la pantalla

int ledrojo=11;                                             //Pin del Led Rojo
int ledverde=13;                                            //Pin del Led Verde
int ledamarillo=12;                                         //Pin del Led Amarillo

int rojoOn=0;                                               //Variable para marcar cambio
int verdeOn=0;                                              //Variable para marcar cambio
int amarilloOn=0;                                           //Variable para marcar cambio

int alarmaRoja=0;                                           //Variable para contar las alarmas
int alarmaAmarilla=0;                                       //Variable para contar las alarmas
int alarmaVerde=0;                                          //Variable para contar las alarmas

      
int Estado0=0;                                              //Variable para comprobar el estado actual de la medicion
int Estado1=0;                                              //Variable para comprobar el estado actual de la medicion
int Estado2=0;                                              //Variable para comprobar el estado actual de la medicion            


void setup() {                                              //configuracion de los pines 
  
pinMode(ledrojo,OUTPUT);                                    //Configuracion del pin del led rojo como salida digital 
pinMode(ledamarillo,OUTPUT);                                //Configuracion del pin del led Amarillo como salida digital
pinMode(ledverde,OUTPUT);                                   //Configuracion del pin del led Verde como salida digital

lcd.begin(20,4);                                            //Declaracion de la pantalla
lcd.print("Voltimetro");                                    //Nombre del proyecto
digitalWrite(ledrojo,LOW);                                  //Escritura digital para que los led por defecto esten apagados
digitalWrite(ledamarillo,LOW);                              //Escritura digital para que los led por defecto esten apagados
digitalWrite(ledverde,LOW);                                 //Escritura digital para que los led por defecto esten apagados
  
}

void loop() {
  
float dato1=(analogRead(A0)*0.00488);                       // Medicion de voltaje del arduino el "0.00488" es el resultado de dividir 5/1024 que  resulta de hacer la regla de 3 correspondiente
 if(dato1<1.25){                                            // Condicion del programa cuando el voltaje es menor que 1.25 se apagan todos los leds
digitalWrite(ledrojo,LOW);                                  // Led rojo apagado
digitalWrite(ledamarillo,LOW);                              // Led amarillo apagado
digitalWrite(ledverde,LOW);                                 // Led verde apagado
}

if((dato1>1.25)){                            // condicion adyacente del programa 
digitalWrite(ledrojo,HIGH);                                 // led rojo encendido
digitalWrite(ledamarillo,LOW);                              // Led amarillo apagado
digitalWrite(ledverde,LOW);                                 // Led verde apagado
rojoOn=1;                                                   // Variable que cambia de estado al entrar la medicion en 1.25V
}
else{                                                       // Condicion para que se ponga a cero la variableanterior
  rojoOn=0;                                                 // Variable que vuelve a su estado original 
}

if((dato1>3.25)) {                           // condicion adyacente del programa
digitalWrite(ledrojo,HIGH);                                  // led rojo apagado
digitalWrite(ledamarillo,HIGH);                             // Led Amarillo Encendido
digitalWrite(ledverde,LOW);                                 // Led verde apagado
amarilloOn=1;                                               // Variable que cambia de estado al entrar la medicion en 3.25V
} 
else{                                                       // Condicion para que se ponga a cero la variableanterior
  amarilloOn=0;                                             // Variable que vuelve a su estado original 
}

if((dato1>4.25)){                           // condicion adyacente del programa
digitalWrite(ledrojo,HIGH);                                  // led rojo apagado
digitalWrite(ledamarillo,HIGH);                              // Led verde apagado
digitalWrite(ledverde,HIGH);                                // Led verde Enecedido
verdeOn=1;                                                  // Variable que cambia de estado al entrar la medicion en 3.25V
}
else{                                                       // Condicion para que se ponga a cero la variableanterior
  verdeOn=0;                                                // Variable que vuelve a su estado original
}

int lecturaRed=rojoOn;                                      // Variable que lee si hubo un cambio con la variable rojoOn                   
int lecturaGreen=verdeOn;                                   // Variable que lee si hubo un cambio con la variable verdeOn
int lecturaYellow=amarilloOn;                               // Variable que lee si hubo un cambio con la variable amarilloOn


if(lecturaRed!=Estado0){                                    // Comparacion entre estado y la lectura si son diferentes quiere decir que cambio de estado la variable rojoOn
  Estado0=lecturaRed;                                       // Obtengo el estado de la lectura
  if(Estado0==HIGH){                                        // Si el estado es alto quiere decir que el voltaje paso el humbral
  lcd.setCursor(0,2);                                       // Posiciono el cursor
  lcd.print("LED R =");                                     // Identifico el led
  lcd.print(alarmaRoja=alarmaRoja+1);                       // Sumo 1 al valor de la alarma
  }}

if(lecturaYellow!=Estado1){                                 // Comparacion entre estado y la lectura si son diferentes quiere decir que cambio de estado la variable amarilloOn
  Estado1=lecturaYellow;                                    // Obtengo el estado de la lectura
  if(Estado1==HIGH){                                        // Si el estado es alto quiere decir que el voltaje paso el humbral
  lcd.setCursor(10,2);                                      // Posiciono el cursor
lcd.print("LED A =");                                       // Identifico el led
  lcd.print(alarmaAmarilla=alarmaAmarilla+1);               // Sumo 1 al valor de la alarma
  }}


if(lecturaGreen!=Estado2){                                  // Comparacion entre estado y la lectura si son diferentes quiere decir que cambio de estado la variable verdeOn
  Estado2=lecturaGreen;                                     // Obtengo el estado de la lectura
  if(Estado2==HIGH){                                        // Si el estado es alto quiere decir que el voltaje paso el humbral
  lcd.setCursor(0,3);                                       // Posiciono el cursor
lcd.print("LED V =");                                       // Identifico el led
  lcd.print(alarmaVerde=alarmaVerde+1);                     // Sumo 1 al valor de la alarma
  }}


  

lcd.setCursor(0,1);                                         // Posiciono el cursor
lcd.print("Voltaje =");                                     // Identifico el menbrete
lcd.setCursor(10,1);                                        // Posiciono el cursor
lcd.print(dato1);                                           // Muestro la medidicion de voltaje

lcd.setCursor(0,2);                                         // Posiciono el cursor
lcd.print("LED R =");                                       // Identifico el menbrete
lcd.setCursor(10,2);                                        // Posiciono el cursor
lcd.print("LED A =");                                       // Identifico el menbrete
lcd.setCursor(0,3);                                         // Posiciono el cursor
lcd.print("LED V =");                                       // Identifico el menbrete


delay(200);                                                 // Espero 200mS entre cada medicion


}
