import java.util.*;

public class Utils {

    public static boolean existe(List<Aluno> lista, Aluno aluno) {
        return lista.contains(aluno);
    }
    public static void ordena(List<Aluno> lista) {
        Collections.sort(lista);
    }
    public static Map<String, Aluno> retornaDados(Set<String> conjuntoAlunos) {
        Map<String, Aluno> mapaDeAlunos = new HashMap<>();
        Iterator<String> iterator = conjuntoAlunos.iterator();

        while (iterator.hasNext()) {
            String linha = iterator.next();
            String[] dados = linha.split("#");

            String id = dados[0];
            String nome = dados[1];
            double nota = Double.parseDouble(dados[2]);
            String tipo = dados[3];

            Aluno aluno;

            if ("R".equalsIgnoreCase(tipo)) {
                aluno = new AlunoRegular(id);
            } else if ("E".equalsIgnoreCase(tipo)) {
                aluno = new AlunoEspecial(id);
            } else {
                throw new RuntimeException("Tipo de aluno inválido na linha: " + linha);
            }

            aluno.setNome(nome);
            aluno.setNota(nota);
            
            mapaDeAlunos.put(id, aluno);
        }
        return mapaDeAlunos;
    }
}
