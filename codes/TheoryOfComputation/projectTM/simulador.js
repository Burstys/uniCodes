// Importação do módulo necessário
const fs = require('fs');

// Função para simular a Máquina de Turing
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

const main = () => {
    if (process.argv.length !== 4) {
        console.log('Uso: node simulador.js tm.json test.txt');
        return;
    }
    // Executando a máquina de Turing com os arquivos de especificações e problema fornecidos
    simulateTuringMachine(process.argv[2], process.argv[3]);
}

main();

