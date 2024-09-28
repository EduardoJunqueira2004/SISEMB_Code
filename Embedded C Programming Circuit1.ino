/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////
/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////
/////////////////////////////////////////////////
// 2-Exercícios-Ex1:
/////////////////////////////////////////////////

int num;	// define uma variável global do tipo inteira que representa o numero a ser validado
  
/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  Serial.println("Digite um numero inteiro:");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {	
  
   // Ler o número inserido pelo utilizador
    num = Serial.parseInt();
  
 // Verificar se o número é positivo ou negativo 
  if (num > 0) {
    Serial.print("O numero ");//Serial.print mantém a mesma linha.
    Serial.print(num);
    Serial.println(" e positivo.");//Serial.println muda de linha.
    // Pedir um novo numero
    Serial.println("Digite um numero inteiro:");
    
   }
  if (num < 0) {
    Serial.print("O numero ");
    Serial.print(num);
    Serial.println(" e negativo.");
    // Pedir um novo número
    Serial.println("Digite um numero inteiro:");
}
}