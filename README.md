# Projeto-G11
# 🛰 SolarBot: Robô Autônomo de Limpeza de Placas Solares
---

## 📘 Introdução

A eficiência das placas solares é diretamente afetada pelo acúmulo de poeira e detritos. A limpeza manual é um processo caro e demorado.  
O *SolarBot* foi concebido como uma solução de baixo custo e alta eficácia para automatizar essa manutenção.

Este documento é um guia prático para a montagem e programação do SolarBot — um protótipo que utiliza:

- Motor *Lego NXT Mindstorm*
- *Ponte H*
- *Arduino UNO*

O robô realiza a limpeza autônoma de painéis solares, invertendo o movimento ao atingir os limites da placa por meio de chaves de fim de curso.

---

## 🔎 2. Visão Geral do Sistema

O sistema opera em um ciclo contínuo de detecção de limites e reversão de movimento.  
Quando uma chave é pressionada, o Arduino inverte a polaridade do motor pela Ponte H, fazendo o robô mudar de direção.

### *Componentes Principais*
- *Microcontrolador:* Arduino UNO  
- *Atuador:* Servo Motor NXT Mindstorm  
- *Driver:* Ponte H  
- *Sensores de Limite:* Duas chaves de fim de curso (limit switches)  
- *Estrutura:* Corpo do robô + mecanismo de locomoção  
- *Eixo de Ferro:* Barra que guia o robô de ponta a ponta  
- *Rolamentos:* Dois rolamentos que conectam o robô à barra para estabilização  

---

## ⚙ 3. Lógica de Funcionamento: Passo a Passo

O projeto é dividido em três grandes etapas:  
1. Montagem do hardware  
2. Carregamento do software  
3. Execução  

---

### 🔧 *Etapa 1: Montagem do Hardware*

Garante que os componentes estejam corretamente interligados para permitir o controle do motor e leitura dos sensores.

#### *1. Chaves de Fim de Curso*
- Fixar uma chave em cada extremidade da estrutura.  
- Devem ser acionadas quando o robô atingir o limite da placa solar.

#### *2. Ponte H e Motor NXT*
- Saídas da Ponte H (*OUT1, **OUT2*) → terminais do motor NXT.  
- Pinos de controle da Ponte H (*IN1, **IN2) → pinos **11* e *12* do Arduino.

#### *3. Arduino e Sensores*
- Pinos de sinal das chaves de limite → pinos *7* e *4* do Arduino.  
- *Dica:* Utilize INPUT_PULLUP no código para eliminar necessidade de resistores externos.

---

### 💻 *Etapa 2: Carregamento do Código (Software)*

O software interpreta os sensores e envia comandos adequados ao motor.

1. Instale a *IDE do Arduino*.  
2. Abra o código-fonte do projeto.  
3. Verifique se os pinos configurados no código correspondem à montagem (11, 12, 7 e 4).  
4. Conecte o Arduino via USB.  
5. Faça o *Upload* do sketch.
### **Mapeamento de Pinos e Referência de Conexão**

Abaixo, a referência para as conexões lógicas entre o Arduino e os componentes críticos:

| Componente | Tipo de Conexão | Função | Pinos (Referência de Código) |
| :--- | :--- | :--- | :--- |
| **Ponte H (IN1)** | Saída Digital | Controla Sentido 1 / HIGH | `11` |
| **Ponte H (IN2)** | Saída Digital | Controla Sentido 2 / LOW | `12` |
| **Ponte H (ENA/ENB)** | Saída PWM/Digital | Habilitação do Motor / Velocidade | `5`|
| **Fim de Curso A** | Entrada Digital | Limite de Posição 1 | `7` (Configurado como `INPUT_PULLUP`) |
| **Fim de Curso B** | Entrada Digital | Limite de Posição 2 | `4` (Configurado como `INPUT_PULLUP`) |


---

### ▶ *Etapa 3: Execução*

#### *Alimentação*
⚠ O motor NXT exige *mais corrente* do que a porta USB fornece.  
Use uma fonte externa para alimentar a Ponte H e o motor.

#### *Teste*
- Posicione o SolarBot na placa solar.  

#### *Ação Esperada*
- O robô inicia o movimento.  
- Ao atingir uma borda → a chave de limite é acionada → o motor inverte o sentido → o robô continua a limpeza no sentido oposto.

---

## 🏁 4. Conclusão e Impacto

O SolarBot demonstra a viabilidade de sistemas autônomos para limpeza de painéis solares, promovendo:

### *✔ Autonomia*
Movimentação e reversão automática baseada em chaves de limite.

### *✔ Eficiência Operacional*
Redução de custos e tempo na manutenção de painéis.

### *✔ Sustentabilidade*
A limpeza constante aumenta a eficiência da geração de energia solar.

---



 
