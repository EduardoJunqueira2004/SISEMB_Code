/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex2:https://www.tinkercad.com/things/gNFp0JgFRG5-copy-of-fp1-embedded-c-programming/editel?sharecode=5wzt0IISJ8kSW78AllKlikmynKeDk-WP94AaumuBNTM
/////////////////////////////////////////////////

int N; 	// define uma variável global do tipo inteira

/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  Serial.println("Digite um numero inteiro entre 1 e 10: ");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {
  // Verificar se há dados disponíveis para ler
  if (Serial.available() > 0) {
    // Ler o número inserido pelo utilizador
    N = Serial.parseInt();

    if (N >= 1 && N <= 10) {
      // Exibir a tabuada se o número estiver no intervalo certo
      Serial.print("Tabuada do ");
      Serial.print(N);
      Serial.println(":");

      // Exibir a multiplicação de N por valores de 1 a 10
      for (int i = 1; i <= 10; i++) {
        Serial.print(N);
        Serial.print(" x ");
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(N * i);
      }
      Serial.println(); // Adiciona uma linha em branco ao final da tabuada

      // Pedir um novo número
      Serial.println("Digite outro numero inteiro entre 1 e 10:");
    } else {
      // Se o número estiver fora do intervalo, exibir uma mensagem de erro
      Serial.print("O numero ");
      Serial.print(N);
      Serial.println(" nao e valido. Por favor, digite um numero inteiro entre 1 e 10.");
    }
  }
}