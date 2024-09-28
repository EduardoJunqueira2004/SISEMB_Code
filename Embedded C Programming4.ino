/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex4:https://www.tinkercad.com/things/dDPJyIWMH4Y-copy-of-fp1-embedded-c-programming/editel?sharecode=5j-4JRxuzIJBkllKdEUQ8oypj0jMmdWOiTU8cdnjNyg
/////////////////////////////////////////////////

float arr[] = {3.0, 5.2, 7.4, 2.5, 3.6, 8.2, 1.1, 7.8, 4.5, 2.2, 7.0};//array default
int n = sizeof(arr) / sizeof(arr[0]); // Calcula o numero de elementos no array

// Inicializando variáveis para maior, menor e soma
    float maior = arr[0];
    float menor = arr[0];
    float soma = 0; 
int cnt = 0;	// define uma variável global do tipo inteira
String str;		// define um objecto do tipo string
  
/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  Serial.println("O array deste exercicio e o seguinte= 3.0, 5.2, 7.4, 2.5, 3.6, 8.2, 1.1, 7.8, 4.5, 2.2, 7.0");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {	
  // Inicializa os valores de maior e menor
  maior = arr[0];
  menor = arr[0];
  soma = 0; 

  // Percorre o array para encontrar o maior, o menor e calcular a soma
  for (int i = 0; i < n; i++) {
    if (arr[i] > maior) {
      maior = arr[i];  // Atualiza o maior valor
    }
    if (arr[i] < menor) {
      menor = arr[i];  // Atualiza o menor valor
    }
    soma += arr[i];  // Soma os valores
  }

  // Calcula a média
  float media = soma / n;

  // Imprime os resultados
  Serial.println("----------------------------");
  Serial.print("O maior elemento do array: ");
  Serial.println(maior);
  Serial.print("O menor elemento do array: ");
  Serial.println(menor);
  Serial.print("O valor medio dos elementos do array: ");
  Serial.println(media);
  Serial.println("----------------------------");

  // Aguarda 5 segundos antes de repetir a operação
  delay(5000);
  
}