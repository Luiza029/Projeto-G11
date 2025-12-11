# 🛰 SolarBot: Robô Autônomo de Limpeza de Placas Solares

> **Status:** 🚧 Concluido / 🟢 Funcional

O **SolarBot** é uma solução de baixo custo e alta eficácia para automatizar a manutenção de painéis fotovoltaicos. Ele utiliza um sistema de sensores de fim de curso para percorrer a placa, limpar a superfície e inverter a direção automaticamente ao atingir as bordas.

---

## 📋 Tabela de Conteúdos
1. [Visão Geral](#-visão-geral)
2. [Lista de Materiais](#-lista-de-materiais)
3. [Esquema de Ligação (Pinout)](#-esquema-de-ligação)
4. [Instalação e Código](#-instalação-e-código)
5. [Como Testar](#-como-testar)

---

## 🔎 Visão Geral

O sistema opera em um **ciclo contínuo**:
1. O robô se move linearmente sobre a placa.
2. Ao atingir a extremidade, uma **Chave de Fim de Curso** é pressionada.
3. O Arduino detecta o clique e inverte a polaridade do motor através da **Ponte H**.
4. O robô retorna limpando o sentido oposto até atingir o outro lado.

---

## 📦 Lista de Materiais

| Componente | Quantidade | Descrição |
| :--- | :---: | :--- |
| **Arduino UNO** | 1 | Microcontrolador principal. |
| **Ponte H (L298N ou similar)** | 1 | Driver para controlar força e direção do motor. |
| **Motor Lego NXT** | 1 | Atuador responsável pela locomoção. |
| **Chaves Fim de Curso** | 2 | Sensores de colisão (com alavanca). |
| **Fonte de Alimentação** | 2 | Bateria externa (9V) para o motor e ponte H. |
| **Jumpers** | Vários | Cabos para conexão (Macho-Macho / Macho-Fêmea). |
| **Barra de Aço** | 1 | Barra de suporte para o robô quando finalizado. |
| **MDF** | 25 | Material utilizado para construção de toda a "Carcaça" do robô. |
| **Rolamento linear** | 2 | Rolamento utilizado para o movimento do robô pela placa solar. |

---

## ⚡ Esquema de Ligação

Siga atentamente a tabela abaixo para conectar os componentes.

### 1. Conexão da Ponte H (Motor)
| Pino da Ponte H | Conexão | Observação |
| :--- | :--- | :--- |
| **IN1** | Arduino Pino **11** | Controle de Sentido A. |
| **IN2** | Arduino Pino **12** | Controle de Sentido B. |
| **OUT1 / OUT2** | Motor NXT | Fios do motor. |
| **9V** | Fonte Externa (+) | **NÃO** ligue no 5V do Arduino. |
| **GND** | Fonte (-) + Arduino GND | **Importante:** Unir os terras (GNDs). |

### 2. Conexão dos Sensores (Fim de Curso)
| Sensor | Perna da Chave | Conexão Arduino |
| :--- | :--- | :--- |
| **Chave Esquerda** | Comum (C) | GND |
| **Chave Esquerda** | Normalmente Aberto (NO) | Pino **7** |
| **Chave Direita** | Comum (C) | GND |
| **Chave Direita** | Normalmente Aberto (NO) | Pino **4** |

---

## 💻 Instalação e Código

1. Baixe e instale a [Arduino IDE](https://www.arduino.cc/en/software).
2. Conecte o Arduino via USB em um computador.
3. Copie o código abaixo e faça o upload para a placa.
4. Após o upload, pode retirar o USB do computador e conectar a bateria 9V (o Arduino armazena o código rodado anteriormente)

```cpp
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

  if (estado == 2) { // Voltar
    Serial.println("Esta no estado VOLTANDO");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(velocidade, 200);
  
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
      estado = 0;
    }
  }
}
