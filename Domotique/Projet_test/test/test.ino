const int bouton = D0; // GPIO 0 (bouton Flash)
const int LED = D2; // LED bleue embarquée

int etatBouton;

void setup() { 
   // on met le bouton en entrée
   // pinMode(unBouton, INPUT);
    // on active la résistance de pull-up en mettant la broche à l'état haut
    // (mais cela reste toujours une entrée)
    //digitalWrite(unBouton, HIGH);
  Serial.begin (115200); 
  pinMode (LED, OUTPUT); 
  pinMode (bouton, INPUT_PULLUP);
  
  
  //LUMIERE
  Serial.begin(9600);
} 

void loop () 
{
  digitalWrite(LED, LOW);
}

