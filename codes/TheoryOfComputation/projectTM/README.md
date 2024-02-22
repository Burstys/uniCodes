# Descrição - Máquina de Turing

- O simulador opera com base em 2 (duas) entradas com dados, sendo uma JSON (.json) contendo as configurações da Máquina de Turing e outra TXT (.txt) contendo o problema a ser resolvido.

# Funções utilizadas na elaboração da Máquina de Turing:

>Importando o módulo fs:
- O código começa importando o módulo fs, que é o módulo de sistema de arquivos do Node.js. Ele permite a leitura e escrita de arquivos.
````
const fs = require('fs');
````

>Definindo a função de simulação:
- simulateTuringMachine(specsFile, problemFile): 
    
    Esta é a função que descreve toda a lógica do código. De início, ela recebe um arquivo JSON que contém a especificação da Máquina de Turing e o converte em um objeto JavaScript usando JSON.parse.
    
    Em seguida, é lido o arquivo que contém o problema a ser resolvido, que é uma string, e a Máquina de Turing é iniciada defininido o estado inicial e a posição da cabeça. Logo após a inicialização, um loop é iniciado com a condição de parado sendo econtrar um estado final.

    Esta busca se dá por meio da combinação entre o símbolo que está sendo lido autalmente e o estado em que a máquina se encontra. Caso não seja encontrado nenhuma transição, a entrada/problema é rejeitado (mostrando "0" na linha de comando) e um arquivo ".txt" é criado contendo a fita resultante.

    Caso uma transição seja encontrada, um novo símbolo é escrito na fita e a cabeça de leitura/escrita é movimentada conforme a especificação da transição (caso seja necessário, são acrescentados símbolos brancos em qualquer lado). Por fim, o estado é atualizado.

    Quando o loop alcançar um estado final, a máquina escreverá a fita resultante no arquivo de saída ".txt" e mostrará na linha de comando que aceitou a entrada ("1").

````
const simulateTuringMachine = (specsFile, problemFile) => {
    // Lendo o arquivo de especificações
    const specs = JSON.parse(fs.readFileSync(specsFile));

    // Lendo o arquivo de problema
    let tape = fs.readFileSync(problemFile, 'utf8').trim().split('');

    // Inicializando a Máquina de Turing
    let state = specs.initial; // Estado inicial
    let head = 0; // Posição da cabeça de leitura/escrita

    // Loop até alcançar um estado final
    while (!specs.final.includes(state)) {
        let currentSymbol = tape[head]; // Símbolo atual na fita

        // Procura transição para o estado e símbiolo atuais
        let transition = specs.transitions.find(t =>
            t.from === state && t.read === currentSymbol
        );

        // Rejeita se não encontrar transição
        if (!transition) {
            fs.writeFileSync('output.txt', tape.join(''));
            console.log("0");
            return;
        }

        // Escreve novo símbolo na fita
        tape[head] = transition.write;

        // Move a cabeça de leitura/escrita
        if (transition.dir === "R") {
            head++;
            if (head === tape.length) {
                tape.push(specs.white); // Acrescenta símbolo branco se necessário
            }
        } else if (transition.dir === "L") {
            head--;
            if (head === -1) {
                tape.unshift(specs.white); // Acrescenta símbolo branco se necessário
                head = 0;
            }
        }

        // Atualiza o estado
        state = transition.to;
    }

    // Escreva a fita resultante no arquivo de saída
    fs.writeFileSync('output.txt', tape.join(''));

    console.log("1"); 
}
````
- main(): Esta é a função inicial do programa responsável por executar a Máquina de Turing utilizando os arquivos fornecidos por meio da linha de comando.
````
const main = () => {
    if (process.argv.length !== 4) {
        console.log('Uso: node simulador.js tm.json test.txt');
        return;
    }
    // Executando a máquina de Turing com os arquivos de especificações e problema fornecidos
    simulateTuringMachine(process.argv[2], process.argv[3]);
}
````
>Exemplo de uso
- Com base na seguinte Máquina de Turing:
````
{
    "initial" : 0,
    "final" : [4],
    "white" : "_",
    "transitions" : [
        {"from": 0, "to": 1, "read": "a", "write": "A", "dir":"R"},
        {"from": 1, "to": 1, "read": "a", "write": "a", "dir":"R"},
        {"from": 1, "to": 1, "read": "B", "write": "B", "dir":"R"},
        {"from": 1, "to": 2, "read": "b", "write": "B", "dir":"L"},
        {"from": 2, "to": 2, "read": "B", "write": "B", "dir":"L"},
        {"from": 2, "to": 2, "read": "a", "write": "a", "dir":"L"},
        {"from": 2, "to": 0, "read": "A", "write": "A", "dir":"R"},
        {"from": 0, "to": 3, "read": "B", "write": "B", "dir":"R"},
        {"from": 3, "to": 3, "read": "B", "write": "B", "dir":"R"},
        {"from": 3, "to": 4, "read": "_", "write": "_", "dir":"L"}      
    ]
}
````
- E na seguinte entrada/problema:
````
aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbb
````
- O resultado obtido é:
````
AAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBB_

Linha de comando: 1
````