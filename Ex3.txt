/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex3:https://www.tinkercad.com/things/iSirJYlf4KW-copy-of-fp1-embedded-c-programming/editel?sharecode=Oc2NA7kNZvcklXfzN8I7QKBo2p6MFXL_SN1C_soZfkY
/////////////////////////////////////////////////

int N; // Numero de digitos a serem inseridos
char numeros[10]; // Array para armazenar os digitos (max= 10 caracteres)
bool prontoParaLer = false; // Controlo para saber quando iniciar a leitura dos digitos
int cnt = 0; // Contador para controlar quantos digitos que foram inseridos

void setup() {
  Serial.begin(9600);
  Serial.println("Digite quantos digitos deseja inserir (max 10):");
}

void loop() {
  // Caso ainda não tenha recebido o valor de N, aguarda e processa a entrada
  if (!prontoParaLer) {
    if (Serial.available() > 0) {
      N = Serial.parseInt();  // Lê a quantidade de dígitos que o utilizador deseja inserir
      
      // Verificar se N esta dentro do intervalo permitido
      if (N > 0 && N <= 10) {
        prontoParaLer = true; // Inicia a leitura dos digitos
        Serial.print("Escreva os ");
        Serial.print(N);
        Serial.println(" digitos (0-9):");
        cnt = 0; // Reiniciar o contador
      } else {
        Serial.println("Por favor, insira um numero entre 1 e 10.");
        Serial.println("Escreva quantos digitos deseja inserir (max 10):");
      }
    }
  } 
  else {
    // Lê os digitos e os armazena no array
    if (Serial.available() > 0 && cnt < N) {
      char c = Serial.read();  // Lê o próximo caractere inserido

      // Verificar se o caractere é um dígito válido (0-9)
      if (c >= '0' && c <= '9') {
        numeros[cnt] = c;  // Armazenar o dígito no array
        Serial.print("Digito ");
        Serial.print(cnt + 1); 
        Serial.print(": ");
        Serial.println(c);
        cnt++;
      }
    }

    // Se todos os dígitos foram lidos, imprimir a sequência inversa
    if (cnt == N) {
      Serial.println("Sequencia na ordem inversa:");
      for (int i = N - 1; i >= 0; i--) {
        Serial.print(numeros[i]);
      }
      Serial.println();  // Nova linha após a sequência

      // Após imprimir, reiniciar o processo
      Serial.println("Digite quantos digitos deseja inserir (max 10):");
      prontoParaLer = false; // Reseta para permitir nova leitura
    }
  }
}