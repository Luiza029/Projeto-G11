# Projeto-G11
# 🤖 SolarBot: Robô Autônomo de Limpeza de Placas Solares

---

### **Descrição do Projeto**

O **SolarBot** é um protótipo de robô autônomo desenvolvido em plataforma **Arduino** para a limpeza eficiente de painéis solares. Este sistema foi integralmente construído com componentes de fácil acesso e visa ser um modelo de referência para controle de movimento bidirecional com delimitação precisa.

O robô utiliza um **Servo Motor LEGO MindStorm NXT** para propulsão, controlado por uma **Ponte H** (e.g., L298N) conectada ao Arduino. A lógica de controle depende de **chaves de fim de curso** (Limit Switches) posicionadas nas extremidades da estrutura. Ao acionarem, elas enviam um sinal digital para o Arduino, que inverte a polaridade da Ponte H, garantindo o ciclo de limpeza completo e seguro dentro dos limites da placa solar.

---

### **Requisitos de Hardware**

Para replicar o **SolarBot**, os seguintes componentes são mandatórios:

* **Microcontrolador:** 1 x Placa **Arduino** (Uno, Nano ou compatível).
* **Atuador:** 1 x **Servo Motor LEGO MindStorm NXT**.
* **Controle de Motor:** 1 x Módulo **Ponte H** (e.g., L298N) para controle de sentido e velocidade.
* **Sensores de Posição:** 2 x **Chaves de Fim de Curso** (Limit Switches).
* **Estrutura Mecânica:** Chassi e sistema de limpeza.
* **Alimentação:** Fonte ou bateria compatível com o motor NXT e o Arduino.
* **Conectividade:** Cabos Jumper.

---

### **Mapeamento de Pinos e Referência de Conexão**

Abaixo, a referência para as conexões lógicas entre o Arduino e os componentes críticos:

| Componente | Tipo de Conexão | Função | Pinos (Referência de Código) |
| :--- | :--- | :--- | :--- |
| **Ponte H (IN1)** | Saída Digital | Controla Sentido 1 / HIGH | `IN1` |
| **Ponte H (IN2)** | Saída Digital | Controla Sentido 2 / LOW | `IN2` |
| **Ponte H (ENA/ENB)** | Saída PWM/Digital | Habilitação do Motor / Velocidade | `velocidade` (Opcional) |
| **Fim de Curso A** | Entrada Digital | Limite de Posição 1 | `fimcurso1` (Configurado como `INPUT_PULLUP`) |
| **Fim de Curso B** | Entrada Digital | Limite de Posição 2 | `fimcurso2` (Configurado como `INPUT_PULLUP`) |

---

### **Instruções para Replicação e Execução**

A execução do SolarBot requer a montagem correta do hardware baseada no mapeamento de pinos e o carregamento do *sketch* do Arduino.

#### **1. Integração de Hardware**

A montagem física deve priorizar a **funcionalidade das Chaves de Fim de Curso**, garantindo que sejam acionadas pela estrutura do robô ao atingir o limite da superfície.

1.  **Motor e Ponte H:** O **Servo Motor NXT** deve ser conectado à **Ponte H** (via terminais OUT1/OUT2). Os pinos de controle da Ponte H (IN1, IN2) devem ser conectados aos pinos digitais 11 e 12 do Arduino, conforme definido no código.
2.  **Sensores:** As **Chaves de Fim de Curso** devem ser conectadas aos pinos de entrada 7 e 4 do Arduino. É vital configurar estas entradas no código como `INPUT_PULLUP` para obter a leitura correta do estado LOW/HIGH.
3.  **Alimentação Externa:** O motor NXT exige alimentação externa dedicada para garantir corrente e tensão suficientes para operação, independente da alimentação do Arduino.

#### **2. Compilação e Carregamento (Software)**

1.  **Configuração do Ambiente:** Utilize a **IDE do Arduino** para compilar o código-fonte (`.ino`).
2.  **Ajuste de Referência:** Antes do upload, **verifique e ajuste as constantes de pinos** no início do *sketch* para refletir o mapeamento de hardware utilizado na sua montagem.
3.  **Upload:** Conecte o Arduino e realize o *Upload* do código.

#### **3. Ciclo de Operação**

O robô opera em um ciclo contínuo (função `loop`):
1.  **Movimento Inicial:** O motor é acionado em uma direção.
2.  **Detecção de Limite:** O Arduino monitora o estado das entradas digitais dos Fim de Curso.
3.  **Inversão:** Quando um Fim de Curso é acionado (e.g., `digitalRead(fimcurso) == HIGH`), o sistema interrompe o motor momentaneamente, inverte o estado dos pinos da Ponte H, e inicia o movimento na direção oposta.

---
 
