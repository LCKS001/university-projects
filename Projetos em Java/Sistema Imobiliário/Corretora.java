import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Corretora {

    public double calcularValorTotal(List<Imovel> imoveis) {
        double soma = 0.0;
        for (Imovel imovel : imoveis) {
            // O Java chama o getPreco() correto (de Novo ou Velho) em tempo de execução.
            soma += imovel.getPreco();
        }
        return soma;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Imovel> listaDeImoveis = new ArrayList<>();
        System.out.println("--- Cadastro de Imóveis da Corretora ---");
        System.out.println("\nCadastrando um Imóvel NOVO...");
        Novo imovelNovo = new Novo();
        imovelNovo.setEndereco("Rua das Flores, 123");
        imovelNovo.setPreco(200000.00); // Preço base
        listaDeImoveis.add(imovelNovo);
        System.out.println("Imóvel Novo cadastrado. Preço com adicional: " + imovelNovo.getPreco());

        System.out.println("\nCadastrando um Imóvel VELHO...");
        Velho imovelVelho = new Velho();
        imovelVelho.setEndereco("Av. Principal, 456");
        imovelVelho.setPreco(150000.00); // Preço base
        listaDeImoveis.add(imovelVelho);
        System.out.println("Imóvel Velho cadastrado. Preço com desconto: " + imovelVelho.getPreco());
        
        System.out.println("\nCadastrando outro Imóvel VELHO...");
        Velho imovelVelho2 = new Velho();
        imovelVelho2.setEndereco("Travessa dos Pássaros, 789");
        imovelVelho2.setPreco(180000.00); // Preço base
        listaDeImoveis.add(imovelVelho2);
        System.out.println("Imóvel Velho cadastrado. Preço com desconto: " + imovelVelho2.getPreco());
        
        System.out.println("\n-------------------------------------------");

        // Cria uma instância da corretora para usar seu método
        Corretora corretora = new Corretora();
        double valorTotal = corretora.calcularValorTotal(listaDeImoveis);
        
        System.out.printf("O valor total de todos os imóveis na corretora é: R$ %.2f\n", valorTotal);

        scanner.close();
    }
}
