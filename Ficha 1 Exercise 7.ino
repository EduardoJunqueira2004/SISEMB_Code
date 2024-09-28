/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex7:https://www.tinkercad.com/things/0fi7Q4h6z3O-copy-of-fp1-embedded-c-programming/editel?sharecode=SoROSWhlEjQ0D2KK2GZ474Ve-6bO9LOan8Dmn90wGm8
/////////////////////////////////////////////////

int numero; // Variável de número inteiro introduzido pelo utilizador
bool calculado = false; // Variável de controle para garantir que o fatorial seja calculado apenas uma vez

// Função que calcula o fatorial de um número
long factorial(int n) {
  long resultado = 1; // Inicializa o resultado como 1

  // Calcula o fatorial de n
  for (int i = 1; i <= n; i++) {
    resultado *= i;
  }

  return resultado; // Retorna o fatorial
}

/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  Serial.println("Introduza um numero para calcular o fatorial:");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {
  // Verificar se há dados disponíveis para ler o número do utilizador
  if (Serial.available() > 0 && !calculado) {
    // Ler o número inserido pelo utilizador
    numero = Serial.parseInt();

     // Verificar se o número é não-negativo
    if (numero >= 0) {
      // Calcula o fatorial usando a função factorial
      long resultado = factorial(numero);

      // Exibe o resultado do fatorial
      Serial.print("O fatorial de ");
      Serial.print(numero);
      Serial.print(" = ");
      Serial.println(resultado);

      // Pedir um novo número
      Serial.println("Introduza outro numero para calcular o fatorial:");
    } else {
      // Mensagem para número negativo
      Serial.println("O fatorial não e definido para numeros negativos. Introduza outro numero:");
    }
  }

  // Ciclo for para garantir que o Arduino continua pedindo números
  for (int i = 0; i < 1; i++) {
    // Esse ciclo for permite que o loop continue executando e verificando novos números
    // sem a necessidade de uma variável de controle como 'calculado'.
  }
}