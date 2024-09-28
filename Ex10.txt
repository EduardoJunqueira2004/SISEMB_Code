/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex10:https://www.tinkercad.com/things/ayCivT62sws-ficha-1-ex-10/editel?sharecode=6Co5d8i69eLiSTZPwrE_zN2HHlRN6M_tzfmIdyR23ts
/////////////////////////////////////////////////

///////////////////////////////////////////////////
//Implemente um programa que solicite ao utilizador 10 números inteiros 
//e que no fim imprima na consola: número de elementos pares, 
//número de elementos ímpares, número de elementos positivos e 
//número de elementos negativos.
//
///////////////////////////////////////////////////
//Variáveis Iniciais 
const int tamanho = 10;
long N[tamanho];  // Array para armazenar os 10 números
int contador = 0; // Contador de números inseridos

//Funções de operações:
void NumPositivos(){
  //Se >0 numeros positivos
  Serial.print(" Numeros Positivos: ");
  bool primeiroNumero = true;  // Variável para controlar a separação
  for (int i = 0; i < tamanho; i++) {
    if (N[i] > 0) {
       if (!primeiroNumero) {
        Serial.print("; ");  // Adiciona "; " após o primeiro número
      }
   Serial.print(N[i]);
      primeiroNumero = false;
    }
  }
  
}

void NumNegativos(){
  //Se <0 numeros negativos
  Serial.print(" Numeros Negativos: ");
  bool primeiroNumero = true;  // Variável para controlar a separação
  for(int i = 0; i < tamanho; i++){
    if(N[i] < 0){
       if (!primeiroNumero) {
        Serial.print("; ");  // Adiciona "; " após o primeiro número
      }
   Serial.print(N[i]);
      primeiroNumero = false;
  }
    
  }
  
}

void NumPares(){
  //Se o resto da divisão /2 = 0 é par
  Serial.print(" Numeros Pares: ");
  bool primeiroNumero = true;  // Variável para controlar a separação
  for(int i = 0; i < tamanho; i++){
    if(N[i]% 2 == 0 ){
       if (!primeiroNumero) {
        Serial.print("; ");  // Adiciona "; " após o primeiro número
      }
      Serial.print(N[i]);
      primeiroNumero = false;
    }
  }
 
}

void NumImpares(){
  //Se o resto  da divisão /2 ! 0 é impar
  Serial.print(" Numeros Impares: ");
  bool primeiroNumero = true;  // Variável para controlar a separação
  for(int i = 0; i < tamanho; i++){
    if(N[i] % 2 != 0 ){
       if (!primeiroNumero) {
        Serial.print("; ");  // Adiciona "; " após o primeiro número
      }
      Serial.print(N[i]);
    primeiroNumero = false;
    }
  }
  
}
  
/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
                
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
 Serial.println(" Por favor, insira 10 numeros inteiros, um de cada vez: ");
  
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
                
void loop() {	
   // Verifica se já inserimos os 10 números
  if (contador < tamanho) {
    // Verifica se há dados disponíveis no serial
    if (Serial.available() > 0) {
      // Lê o número inserido e armazena no array N
      N[contador] = Serial.parseInt();
      Serial.print(" Numero inserido: ");
      Serial.println(N[contador]); // Imprime o número lido
      
      contador++; // Incrementa o contador de números inseridos

      // Pede o próximo número
      if (contador < tamanho) {
        Serial.print(" Insira o  seguinte numero: ");
        Serial.print(contador + 1);
        Serial.println(": ");
      }
    }
  }
  
  // Se já inseriu 10 números, imprime os resultados
  if (contador == tamanho) {
    // Chamar as funções para imprimir os números em cada categoria
    NumPares();
    NumImpares();
    NumPositivos();
    NumNegativos();
    
    // Reinicia o contador para permitir uma nova inserção após o delay
    contador = 0;
    delay(20000); // 10 segundos de delay antes de iniciar uma nova rodada
    Serial.println("Por favor, insira 10 numeros inteiros, um de cada vez: ");
  }
}