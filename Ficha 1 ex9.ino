/////////////////////////////////////////////////
// Ficha Prática 1 - Revisões
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// Eduardo Miguel Moreira Junqueira nº30241 ERSC 
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// 2-Exercícios-Ex9:https://www.tinkercad.com/things/1gyULVvvKmJ-ficha-1-ex9/editel?sharecode=3UtB3Nqe6bFNgxmDng4NMwhQttjIY5_G43IqDq-1kC0
/////////////////////////////////////////////////
const int TAMANHO_TURMA = 10; // Define o número de alunos

// Função para introduzir as notas no array
void introduzirNotas(float notas[]) {
    for (int i = 0; i < TAMANHO_TURMA; i++) {
        Serial.print("Introduza a nota do aluno ");
        Serial.print(i + 1);
        Serial.println(":");

        // Aguarda a introdução de uma nota válida
        while (Serial.available() == 0) {
            // Espera a entrada do usuário
        }
        
        // Lê a nota como float
        notas[i] = Serial.parseFloat(); 

        // Verifica se a nota está entre 0 e 20
        while (notas[i] < 0 || notas[i] > 20) {
            Serial.println("Nota invalida. Introduza uma nota entre 0 e 20:");

            // Aguarda nova entrada
            while (Serial.available() == 0) {
                // Espera a entrada do usuário
            }
            notas[i] = Serial.parseFloat(); // Lê a nova nota
        }

        // Imprime a nota inserida
        Serial.print("Nota do aluno ");
        Serial.print(i + 1);
        Serial.print(" = ");
        Serial.println(notas[i]);

        // Espera 1 segundo antes de permitir a introdução da próxima nota
        delay(1000);
    }
}

// Função para calcular a média das notas
float calcularMedia(float notas[]) {
    float soma = 0.0;//variavel soma das notas

    for (int i = 0; i < TAMANHO_TURMA; i++) {
        soma += notas[i];
    }

    return soma / TAMANHO_TURMA; // Calcula a média
}

/////////////////////////////////////////////////
// Função Setup - Inicialização
/////////////////////////////////////////////////
void setup() {	
  Serial.begin(9600);
  Serial.println("In setup function");
  Serial.println(" Introduza as notas da turma:");
}

/////////////////////////////////////////////////
// Função Loop - Loop de controlo
/////////////////////////////////////////////////
void loop() {	
 float notas[TAMANHO_TURMA]; // Array para armazenar as notas

    // Chama a função para introduzir as notas
    introduzirNotas(notas);

    // Calcula a média e imprime o resultado
    float media = calcularMedia(notas);
    Serial.print("A media aritmetica geral = ");
    Serial.print(media);
  // Espera um pouco antes de permitir nova execução
    delay(5000); // 5 segundos de espera antes de reiniciar o processo
}