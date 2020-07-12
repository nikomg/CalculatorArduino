int pin_DT1 = 2;
int pin_CLK1 = 3;
int pin_DT2 = 4;
int pin_CLK2 = 5;
int Last1;
int Last2;
int enc_count1 = 0;
int enc_count2 = 0;
char znak = '+';
// Here i define all variables
void setup() { 
   pinMode (pin_DT1,INPUT);
   pinMode (pin_CLK1,INPUT);
   pinMode (pin_DT2,INPUT);
   pinMode (pin_CLK2,INPUT);
   // Here we says arduino: "On 2,3,4,5 ports we get a variables(not send)"
   Last1 = digitalRead(pin_DT1);
   Last2 = digitalRead(pin_DT2);
   Serial.begin (9600); // Here i start a port monitor
 } 

void loop() {
Last1 = encTick(pin_DT1,pin_CLK1,Last1,1); 
Last2 = encTick(pin_DT2,pin_CLK2,Last2,2);
//Here arduino every time ask encoder
}

int encTick(int pin_DT,int pin_CLK, int Last, int num){
  
  int DT;
  boolean left;
  DT = digitalRead(pin_DT);
  if (DT != Last){
     if (digitalRead(pin_CLK) != DT) {
        if(num == 1) enc_count1++;
        if(num == 2) enc_count2++;
        left = false;
     } else {
        left = true;
        if(num == 1) enc_count1--;
        if(num == 2) enc_count2--;
     }
     //This just function for encoder(more information you can find on google)
     Serial.print(enc_count1);
     Serial.print(" ");
     Serial.print(znak);
     Serial.print(" ");
     Serial.print(enc_count2);
     Serial.print(" ");
     Serial.print("=");
     Serial.print(" ");
     Serial.println(enc_count1+enc_count2);
     //here we print all data to monitor port
   } 
   Last = DT;
   return Last;
 }
