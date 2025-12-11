// Pinagem do Arduino
// Pinagem do Arduino para 1 motor

int IN1 = 11;         // controle do sentido
int IN2 = 12;         // controle do sentido
int velocidade = 5; // PWM (tem que ser um pino com acento til do Arduino)
int fimcurso = 7;
int fimcurso2 = 4;
bool fimpress;
bool fimpress2;
int estado = 0;
int counter = 0;

// Variaveis auxiliares (se quiser variar algo no tempo)

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(velocidade, OUTPUT);
  pinMode(fimcurso, INPUT_PULLUP);
  pinMode(fimcurso2, INPUT_PULLUP);
}

void loop() { // Andar
  if (estado == 0) {
    Serial.println("Esta no estado ANDANDO");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(velocidade, 200);
    fimpress = digitalRead(fimcurso);
    if (fimpress == HIGH) {
      Serial.println("BOTAO 1 PRESSIONADO");
      estado = 2;
    }
  }

  // if (estado == 1) { // Parar
  //   Serial.println("Esta no estado PARADO");
  //   digitalWrite(IN1, LOW);
  //   digitalWrite(IN2, LOW);
  //   analogWrite(velocidade, 0);

  //   estado = 2;
  // }

  if (estado == 2) { // Voltar
    Serial.println("Esta no estado VOLTANDO");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(velocidade, 200);
    
    // fimpress = digitalRead(fimcurso); //substituir pelo codigo abaixo quando implementar a 2a chave
    // if (fimpress == HIGH) {
    //   delay(500);
    //   estado = 3;
    // }
    fimpress2 = digitalRead(fimcurso2);
    if (fimpress2 == HIGH) {
      Serial.println("BOTAO 2 PRESSIONADO");
      counter++;
      if (counter == 3) {
        counter = 0;
        estado = 3;
      }
      else {
        estado = 0;
      }
    }
  } 

  if (estado == 3) { // Parar
    Serial.println("Esta no estado PARADO2");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(velocidade, 0);

    fimpress = digitalRead(fimcurso); // reiniciar o percurso
    if (fimpress == HIGH) {
      delay(500); // esse delay e necessario
      estado = 0;
    }
  }
}