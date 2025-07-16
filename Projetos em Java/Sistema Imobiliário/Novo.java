public class Novo extends Imovel {
    @Override
    public double getPreco() {
        double precoBase = super.getPreco();
        return precoBase * 1.10;
    }
}
