/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex5:https://www.tinkercad.com/things/iicfj4fOz2X-copy-of-fp1-embedded-c-programming/editel?sharecode=PIbLw345yuoQWaePUPN1LVfNScCKVYAvvTxtDwo3Xjg
/////////////////////////////////////////////////

float soma = 0.0; // Inicializa a soma como 0
    int numerador = 1;
    int denominador = 1;

/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  Serial.println("Realizar o somatorio do exercico= soma = 1/1 + 3/2 + 5/3 + 7/4 + ... + 99/50");
  
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {	
  // Realiza o somatório conforme o padrão apresentado
    while (numerador <= 99 && denominador <= 50) {
        soma += (float)numerador / denominador; // Soma cada termo da série
        numerador += 2; // Incrementa o numerador de 2 em 2 (1, 3, 5, ...)
        denominador += 1; // Incrementa o denominador de 1 em 1 (1, 2, 3, ...)
    }

    // Exibe o resultado da soma
    Serial.println("O resultado da soma = ");
    Serial.println(soma);
  
}