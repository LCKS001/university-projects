import java.util.Scanner;

public class UFC {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Lutador[] lutadores = new Lutador[5]; // Tamanho reduzido para facilitar o teste

        System.out.println("--- Cadastro de Lutadores do UFC ---");
        System.out.println("Categorias: Pena (<65kg), Medio (<83.9kg), MeioPesado (<93kg), Pesado (<120.2kg)");

        for (int i = 0; i < lutadores.length; i++) {
            System.out.println("\n--- Cadastro do Lutador " + (i + 1) + " ---");
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            System.out.print("Idade: ");
            int idade = scanner.nextInt();
            System.out.print("Peso (kg): ");
            double peso = scanner.nextDouble();
            scanner.nextLine(); // Consumir a nova linha pendente

            if (peso <= 65.0) {
                lutadores[i] = new PesoPena(nome, idade, peso);
            } else if (peso <= 83.9) {
                lutadores[i] = new PesoMedio(nome, idade, peso);
            } else if (peso <= 93.0) {
                lutadores[i] = new MeioPesado(nome, idade, peso);
            } else if (peso <= 120.2) {
                lutadores[i] = new PesoPesado(nome, idade, peso);
            } else {
                System.out.println("Peso inválido para as categorias listadas. Tente novamente.");
                i--; // Repete a iteração para o mesmo lutador
            }
        }
        
        System.out.println("\n--- Lutadores Cadastrados ---");
        for(int i=0; i<lutadores.length; i++){
            System.out.println(i + ": " + lutadores[i] + " [" + lutadores[i].categoriaLutador() + "]");
        }

        System.out.println("\n--- Simulação de Luta ---");
        System.out.print("Escolha um lutador pelo índice (0 a " + (lutadores.length - 1) + "): ");
        int indiceEscolhido = scanner.nextInt();

        if (indiceEscolhido < 0 || indiceEscolhido >= lutadores.length) {
            System.out.println("Índice inválido.");
        } else {
            Lutador lutadorEscolhido = lutadores[indiceEscolhido];
            System.out.println("\nLutador escolhido: " + lutadorEscolhido);
            
            System.out.println("------------------------------------");
            lutadorEscolhido.possiveisLutas(lutadores);
            System.out.println("------------------------------------");

            Lutador oponenteSorteado = lutadorEscolhido.sorteioLuta(lutadores);

            if (oponenteSorteado != null) {
                System.out.println("\nLUTA SORTEADA:");
                System.out.println(lutadorEscolhido.getNome() + " vs " + oponenteSorteado.getNome());
            } else {
                System.out.println("\nNão foi possível sortear uma luta. Nenhum oponente válido encontrado.");
            }
        }

        scanner.close();
    }
}
