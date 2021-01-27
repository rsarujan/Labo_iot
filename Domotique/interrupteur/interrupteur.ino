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
   etatBouton = HIGH;
  
} 

void loop () 
{ 
  etatBouton = digitalRead(bouton);
   if(etatBouton == HIGH) // test si le bouton a un niveau logique HAUT
    {
      Serial.println ("on"); 
        digitalWrite(LED, LOW); //le bouton est relâché, la LED est allumée
    }
    else  // test si le bouton a un niveau logique différent de HAUT (donc BAS)
    {
      Serial.println ("off"); 
        digitalWrite(LED, HIGH); //la LED reste éteinte
    }
}
