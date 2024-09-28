/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex6:https://www.tinkercad.com/things/gf7IW9qrlmV-copy-of-fp1-embedded-c-programming/editel?sharecode=Hdf2TzvnEm19EzHL7UEGwJI51ZkpCadSfYBeJV2a3a4
/////////////////////////////////////////////////

int num; // Número inserido pelo utilizador

// Função que testa se um número é primo
char testaPrimo(int num) {
    // Números menores que 2 não são primos
    if (num < 2) {
        return 1; // Não é primo
    }

    // Verificar se o número tem divisores além de 1 e ele mesmo
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 1; // Não é primo
        }
    }

    return 0; // É primo
}

/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");  
  Serial.println("Insira um numero inteiro. O programa verifica se e primo (0 = primo, 1 = nao primo).");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {	
  // Verificar se há dados disponíveis na porta serial
  if (Serial.available() > 0) {
    // Ler o número inserido pelo utilizador
    num = Serial.parseInt();

    // Verificar se o número é positivo ou negativo
    if (num >= 0) {
      Serial.print("O numero ");
      Serial.print(num);
      Serial.println(" e positivo.");

      // Testar se o número é primo
      char resultado = testaPrimo(num);
      
      if (resultado == 0) {
        Serial.print("O numero ");
        Serial.print(num);
        Serial.println(" e primo.");
      } else {
        Serial.print("O numero ");
        Serial.print(num);
        Serial.println(" nao e primo.");
      }
      
      // Pedir um novo número
      Serial.println("Digite outro numero inteiro:");
      
    } else {
      Serial.print("O numero ");
      Serial.print(num);
      Serial.println(" e negativo.");

      // Pedir um novo número
      Serial.println("Digite outro numero inteiro:");
    }
  }
}