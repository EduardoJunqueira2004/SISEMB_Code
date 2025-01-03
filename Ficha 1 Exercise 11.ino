/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex11:https://www.tinkercad.com/things/edmwHkK1zu8-ficha-1-ex-11/editel?sharecode=2dQtGqAoQO7I20uuaKya3ob3kv9Qn1OwFrMW99BUCbE
/////////////////////////////////////////////////

////////////////////////////////////////////////////
//Implemente um programa que solicite ao utilizador 
//uma palavra e uma letra e que imprima na consola o 
//número de vezes que a letra é usada na palavra.
/////////////////////////////////////////////////////

//Array para a palavra
char palavra[20];  // Define um array com até 20 caracteres para armazenar a palavra
char letra;  // Variável para armazenar a letra que será contada
int cnt = 0;  // Variável para contar quantas vezes a letra aparece na palavra
 
//Criar uma função que percorra a palavra e conte quantas vezes a letra aparece.
void CntLetra(){
  
  cnt = 0;  // Reinicializa o contador
  
  for (int i = 0; palavra[i] != '\0'; i++) {  // Percorre cada caractere da palavra
    if (palavra[i] == letra) {  // Se o caractere for igual à letra que estamos procurando
      cnt++;  // Incrementa o contador
    }
  }
    // Imprime o resultado
  Serial.print("A letra '");
  Serial.print(letra);
  Serial.print("' aparece ");
  Serial.print(cnt);
  Serial.println(" vez(es) na palavra.");
}
/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  //Indicar que o utilizador insira uma palavra.
  Serial.println("Porfavor introduza uma palavra: ");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {	
  // Verifica se há dados disponíveis no serial para ler a palavra
  if (Serial.available() > 0) {
    Serial.println("Porfavor introduza uma palavra: ");
    //ler a Palavra
    Serial.readBytesUntil('\n', palavra, sizeof(palavra));  // Lê até 20 caracteres ou até encontrar o caractere de nova linha

    Serial.print("Palavra inserida: ");
    Serial.println(palavra);  // Imprime a palavra inserida
    
     // Solicita a letra que será contada
    Serial.println("Agora, introduza a letra que deseja contar na palavra: ");
    
    // Aguarda a inserção da letra
    while (Serial.available() == 0) {
      // Espera o utilizador inserir uma letra
    }
    
    letra = Serial.read();  // Lê a letra que será contada
    
    //Imprimir o resultado na consola.
  CntLetra();
    
     // Espera um tempo antes de permitir outra execução
    delay(5000);  // 5 segundos de delay antes de reiniciar
    Serial.println("\nPor favor, introduza uma nova palavra: ");  // Solicita uma nova palavra
}
}
  