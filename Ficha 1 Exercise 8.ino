/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex8:https://www.tinkercad.com/things/c2ONbPXdVI8-ficha-1-ex-8/editel?sharecode=M3GBcgjMLDVizkCT664bgNCTEDfg0-opSUUnn3OgxHk
/////////////////////////////////////////////////

/////////////////////////////////////////////////
//sequência de Fibonacci -->o 1ºtermo =0 2ºtermo=1 A partir do 3ºtermo em diante, cada termo é a soma dos dois anteriores.
//esta sequência irá imprimir os N primeiros termos da sequência que será pedido ao tulizador: por exemplo:10 primeiros termos da sequência de Fibonacci
/////////////////////////////////////////////////

int N;	// define uma variável global do tipo inteira para os N primeiros numeros da sequência
 // Inicializa os dois primeiros termos da sequência
int t1 = 0;// 1ºtermo da sequência
int t2 = 1;//2ºtermo da sequência
int proximoTermo; //Próximo termo da sequência

void Fibonacci(int N) {
    // Reinicializa os dois primeiros termos da sequência toda vez que a função é chamada
    int t1 = 0; // Primeiro termo
    int t2 = 1; // Segundo termo
    int proximoTermo; // Próximo termo da sequência
  
  Serial.print("Sequencia de Fibonacci com: ");
  Serial.print(N);
  Serial.print(" termos: ");

    for (int i = 1; i <= N; i++) {
        if (i == 1) {
          	Serial.print(t1);
            continue;
        }
        if (i == 2) {
           Serial.print(t2);
            continue;
        }
        proximoTermo = t1 + t2; // Calcula o próximo termo
       Serial.print(proximoTermo);

        // Atualiza os valores de t1 e t2
        t1 = t2;
        t2 = proximoTermo;
    }
   Serial.println("");
}
  
/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  Serial.println("Introduz os N termos para a realizacao de uma sequencia de Fibonacci: ");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {	
  
  // Verificar se há dados disponíveis para ler o número N
  if (Serial.available() > 0) {
    // Lê o valor de N do monitor serial
    N = Serial.parseInt();

    // Verificar se o valor de N é positivo
    if (N <= 0) {
        Serial.println("Por favor, insira um numero maior que 0.");
    } else {
        // Chama a função Fibonacci para imprimir os termos
        Fibonacci(N);

        // Pedir um novo número
        Serial.println("Introduza o numero de termos para a sequencia de Fibonacci: ");
    }
  }
}