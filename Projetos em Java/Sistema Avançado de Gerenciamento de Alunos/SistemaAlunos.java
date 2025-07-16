import java.util.*;

public class SistemaAlunos {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Set<String> dadosBrutos = new HashSet<>();
        int numeroDeAlunos = 5; 

        System.out.println("--- Sistema de Cadastro de Alunos ---");
        System.out.println("Digite os dados de " + numeroDeAlunos + " alunos no formato: id#nome#nota#tipo (R para Regular, E para Especial)");
        
        for (int i = 0; i < numeroDeAlunos; i++) {
            System.out.print("Aluno " + (i + 1) + ": ");
            dadosBrutos.add(scanner.nextLine());
        }

        try {
            Map<String, Aluno> mapaDeAlunos = Utils.retornaDados(dadosBrutos);
            
            // Converte os valores do mapa para uma lista para poder ordenar
            List<Aluno> listaDeAlunos = new ArrayList<>(mapaDeAlunos.values());

            // Ordena a lista de alunos por nome
            Utils.ordena(listaDeAlunos);
            
            System.out.println("\n--- Relatório de Alunos (Ordenado por Nome) ---");
            for (Aluno aluno : listaDeAlunos) {
                System.out.println(aluno);
            }

        } catch (RuntimeException e) {
            System.err.println("Erro ao processar dados: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
